#include<stdio.h>
#include<stdlib.h>
#include <iostream>

#define  maxio (1000000)

char buf[maxio], *s = buf + maxio;

inline char getc1(void)
{
   if(s >= buf + maxio) { fread_unlocked(buf,sizeof(char),maxio,stdin); s = buf; }
   return *(s++);
}
inline int input()
{
   char t = getc1();
   int n=1,res=0;
   while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-')
   {
      n=-1; t=getc1();
   }
   while(isdigit(t))
   {
     res = 10*res + (t&15);
     t=getc1();
   }
   return res*n;
}
struct Node{
public:
  int TID;
  int sid;
  int eid;
  int min;
  int max;
  int pendingUpdate;
  int r,l,p,c;
  /*Node(){
  min=max=TID=sid=eid=pendingUpdate;
 }*/
};
int ctr;
struct Node nodes[2000050];
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
        if(nodes[p].c==0){
           nodes[p].l=++ctr;
           nodes[p].r=++ctr;
        }
        int l=nodes[p].l;
        int r = nodes[p].r;
        if(nodes[p].c==0){
           nodes[l].c=0;
           nodes[l].sid = nodes[p].sid;
           nodes[l].eid = (nodes[p].sid+nodes[p].eid)/2;
           nodes[l].min = nodes[l].sid + nodes[p].pendingUpdate;
           nodes[l].max = nodes[l].eid + nodes[p].pendingUpdate;
           nodes[l].pendingUpdate=0;
           nodes[l].p = p;
        } else {
           nodes[l].min+= nodes[p].pendingUpdate;
           nodes[l].max+= nodes[p].pendingUpdate;
        }   

        if(nodes[p].c==0){
           nodes[r].c=0;
           nodes[r].eid = nodes[p].eid;
           nodes[r].sid = (nodes[p].sid+nodes[p].eid)/2 + 1;
           nodes[r].min = nodes[r].sid + nodes[p].pendingUpdate;
           nodes[r].max = nodes[r].eid + nodes[p].pendingUpdate;
           nodes[r].pendingUpdate=0;
           nodes[r].p=p;
        } else {
           nodes[r].min+= nodes[p].pendingUpdate;
           nodes[r].max+= nodes[p].pendingUpdate;
        }

        nodes[l].pendingUpdate+=nodes[p].pendingUpdate;
        nodes[r].pendingUpdate+=nodes[p].pendingUpdate;
        nodes[p].pendingUpdate=0;    
        nodes[p].c = 1;
    }
}
void update(int p,int x, int y, int z){
    if(x==nodes[p].sid&&y==nodes[p].eid){
        nodes[p].min+=z;
        nodes[p].max+=z;
        nodes[p].pendingUpdate+=z;
    } else {
        pushUpdate(p);
        int l = nodes[p].l;
        int r = nodes[p].r;
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
//scanf("%d",&T);
 T=input();
  for(CTID=1;CTID<=T;CTID++){
      //scanf("%d %d",&N,&M);
  N=input();
  M=input();
      nodes[0].TID=CTID;
      nodes[0].sid=1;
      nodes[0].eid=N;
      nodes[0].min=1;
      nodes[0].max=N;
      nodes[0].c=0;
      for(int i=0;i<M;i++){
          int a,x,y,z;
          //scanf("%d %d %d %d",&a,&x,&y,&z);
     a=input();x=input();y=input();z=input();
          if(a==2) z = -1*z;
          update(0,x,y,z);
         if(nodes[0].c){
          nodes[0].min = min(nodes[nodes[0].l].min,nodes[nodes[0].r].min);
          nodes[0].max = max(nodes[nodes[0].l].max,nodes[nodes[0].r].max);
         }
      }
      printf("%d\n",nodes[0].max-nodes[0].min);
      ctr=0;
  }
}
