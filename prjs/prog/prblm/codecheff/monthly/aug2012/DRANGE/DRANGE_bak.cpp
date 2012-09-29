#include<stdio.h>
#include<stdlib.h>

struct Node{
public:
  int TID;
  int sid;
  int eid;
  int min;
  int max;
  int pendingUpdate;
  /*Node(){
  min=max=TID=sid=eid=pendingUpdate;
 }*/
};

struct Node nodes[2005000];
int N,M,CTID;
int min(int a,int b){
  return a<b?a:b;
}
int max(int a,int b){
   return a>b?a:b;  
}
void throwError(){
 int a=1;
 a = a/(a-1);
}
int right(int i){
  return 2*i+2;
}
int left(int i){
  return 2*i+1;
}
bool isLeaf(int i){
    return nodes[i].sid==nodes[i].eid;
}
void pushUpdate(int p){
    if(!isLeaf(p)){
        int l = 2*p+1;
        int r = 2*p+2;
        if(nodes[l].TID!=CTID){
           nodes[l].TID=CTID;
           nodes[l].sid = nodes[p].sid;
           nodes[l].eid = (nodes[p].sid+nodes[p].eid)/2;
           nodes[l].min = nodes[l].sid + nodes[p].pendingUpdate;
           nodes[l].max = nodes[l].eid + nodes[p].pendingUpdate;
           nodes[l].pendingUpdate=0;
        } else {
           nodes[l].min+= nodes[p].pendingUpdate;
           nodes[l].max+= nodes[p].pendingUpdate;
        }   

        if(nodes[r].TID!=CTID){
           nodes[r].TID=CTID;
           nodes[r].eid = nodes[p].eid;
           nodes[r].sid = (nodes[p].sid+nodes[p].eid)/2 + 1;
           nodes[r].min = nodes[r].sid + nodes[p].pendingUpdate;
           nodes[r].max = nodes[r].eid + nodes[p].pendingUpdate;
           nodes[r].pendingUpdate=0;
        } else {
           nodes[r].min+= nodes[p].pendingUpdate;
           nodes[r].max+= nodes[p].pendingUpdate;
        }

        nodes[l].pendingUpdate+=nodes[p].pendingUpdate;
        nodes[r].pendingUpdate+=nodes[p].pendingUpdate;
        nodes[p].pendingUpdate=0;    
    }
}
void update(int p,int x, int y, int z){
    int l = left(p);
    int r = right(p);
    if(x==nodes[p].sid&&y==nodes[p].eid){
        nodes[p].min+=z;
        nodes[p].max+=z;
        nodes[p].pendingUpdate+=z;
    } else {
        pushUpdate(p);
        if(isLeaf(p)){
            throwError();
        }
        if(x<=nodes[l].eid){
            update(l,x,min(y,nodes[l].eid),z);
        }
        if(y>=nodes[r].sid){
            update(r,max(x,nodes[r].sid),y,z);
        }
	nodes[p].min = min(nodes[l].min,nodes[r].min);
	nodes[p].max = max(nodes[l].max,nodes[r].max);
        
    }
}
int main(){
  int T;
scanf("%d",&T);
  for(CTID=1;CTID<=T;CTID++){
      scanf("%d %d",&N,&M);
      nodes[0].TID=CTID;
      nodes[0].sid=1;
      nodes[0].eid=N;
      nodes[0].min=1;
      nodes[0].max=N;
      for(int i=0;i<M;i++){
          int a,x,y,z;
          scanf("%d %d %d %d",&a,&x,&y,&z);
          if(a==2) z = -1*z;
          update(0,x,y,z);
          nodes[0].min = min(nodes[1].min,nodes[2].min);
          nodes[0].max = max(nodes[1].max,nodes[2].max);
      }
      printf("%d\n",nodes[0].max-nodes[0].min);
  }
}
