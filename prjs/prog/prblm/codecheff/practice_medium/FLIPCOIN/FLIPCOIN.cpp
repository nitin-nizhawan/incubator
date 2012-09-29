#include<stdio.h>
struct Node{
public:
  int TID;
  int sid;
  int eid;
  int heads;
  int tails;
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
           nodes[l].heads=0;// = nodes[l].sid + nodes[p].pendingUpdate;
           nodes[l].tails=nodes[l].eid-nodes[l].sid+1;// = nodes[l].eid + nodes[p].pendingUpdate;
           if(nodes[p].pendingUpdate){
               int tmp = nodes[l].heads;
              nodes[l].heads = nodes[l].tails;
              nodes[l].tails = tmp;
           }
           nodes[l].p = p;
        } else {
           if(nodes[p].pendingUpdate){
               int tmp = nodes[l].heads;
              nodes[l].heads = nodes[l].tails;
              nodes[l].tails = tmp;
           }
           
        }   

        if(nodes[p].c==0){
           nodes[r].c=0;
           nodes[r].eid = nodes[p].eid;
           nodes[r].sid = (nodes[p].sid+nodes[p].eid)/2 + 1;
           nodes[r].heads = 0;//nodes[r].sid + nodes[p].pendingUpdate;
           nodes[r].tails =  nodes[r].eid - nodes[r].sid +1;// + nodes[p].pendingUpdate;
           if(nodes[p].pendingUpdate){
               int tmp = nodes[r].heads;
              nodes[r].heads = nodes[r].tails;
              nodes[r].tails = tmp;
           }
           nodes[r].p=p;
        } else {
           if(nodes[p].pendingUpdate){
               int tmp = nodes[r].heads;
              nodes[r].heads = nodes[r].tails;
              nodes[r].tails = tmp;
           }
        }

        nodes[l].pendingUpdate=nodes[p].pendingUpdate;
        nodes[r].pendingUpdate=nodes[p].pendingUpdate;
        nodes[p].pendingUpdate=0;    
        nodes[p].c = 1;
    }
}
void update(int p,int x, int y){
    if(x==nodes[p].sid&&y==nodes[p].eid){
        int tmp = nodes[p].heads;
        nodes[p].heads=nodes[p].tails;
        nodes[p].tails=tmp;
        nodes[p].pendingUpdate=1-nodes[p].pendingUpdate;
    } else {
        pushUpdate(p);
        int l = nodes[p].l;
        int r = nodes[p].r;
        if(isLeaf(p)){
            throwError();
        }
        if(x<=nodes[l].eid){
            update(l,x,min(y,nodes[l].eid));
        }
        if(y>=nodes[r].sid){
            update(r,max(x,nodes[r].sid),y);
        }
	nodes[p].heads = nodes[r].heads+nodes[l].heads;
	nodes[p].tails = nodes[r].tails + nodes[l].tails;
        
    }
}


void update(int a, int b){
    //printf("update with %d,%d\n",a,b);
    update(0,a, b);
}
int qr(int a , int b, int p){
    if(nodes[p].sid==a&&nodes[p].eid==b){
        return nodes[p].heads;
    } else {
        pushUpdate(p);
        int l = nodes[p].l;
        int r = nodes[p].r;
        if(isLeaf(p)){
            throwError();
        }
        int ans=0;
        if(a<=nodes[l].eid){
            ans+=qr(a,min(b,nodes[l].eid),l);
        }
        if(b>=nodes[r].sid){
            ans+=qr(max(a,nodes[r].sid),b,r);
        }
        return ans;
         
    }
    
}
void query(int a, int b){
    printf("%d\n",qr(a,b,0));
}
int main(){
    int Q;
    scanf("%d",&N);
   // printf("DEBUG:h: %d, n: %d \n ",heap[0].h,heap[0].n);
    scanf("%d",&Q);
    nodes[0].sid=0;
    nodes[0].eid=N-1;
    nodes[0].heads=0;
    nodes[0].tails=N;
    nodes[0].pendingUpdate=0;
    nodes[0].c=0;
    while(Q--){
        int t,a,b;
        scanf("%d %d %d",&t,&a,&b);
        if(t){
            query(a,b);
        } else {
            update(a,b);
        }
    }
}



