#include<stdio.h>
#include<stdlib.h>
#include<map>
#define MAXTRY 101
using namespace std;
class Node{
public:
  int s,e;
 void init(int a, int b){
      s= a;
      e=b;
  }
};
Node mem[100000];
int cp=0;
int N;
long long A[2000];
int idx[MAXTRY][1001];
int ans[1001];
bool uni[1001];
void randomize(int s){
    int tmp=0;
    int p;

    //log("randomizing \n");
    for(int i=0;i<N;i++){
        idx[s][i]=i;
    }
    for(int i=0;i<N;i++){
        p = rand()%(N-i);
        tmp = idx[s][i] ;
        idx[s][i]  = idx[s][i+p];
        idx[s][i+p]=tmp;
        //log("%d ",idx[s][i]);
    }
    //log("\n");
}
bool findmatch(int k,int l,int k1,int l1){    
    for(int i=0;i<N;i++){
        uni[i]=false;
    }
    for(int i=0;i<=l;i++){
        uni[idx[k][i]]=true;
    }
    for(int i=0;i<=l1;i++){
        if(uni[idx[k1][i]]==true) uni[idx[k1][i]]=false;
        else  uni[idx[k1][i]]=true;
    }
    bool isfull=true;
    bool isempty=true;
    for(int i=0;i<N;i++){
        if(uni[i]==false){
            isfull=false;
        }
        if(uni[i]==true){
            isempty=false;
        }
        if(!isfull&&!isempty){
              break;
        }
    }
    if(isfull||isempty){
        return false;
    }
    for(int i=0;i<N;i++){
        if(uni[i]==true){
        ans[i]=2;
        }
    }
    return true;
}
int solve(){
    long long acc=0;
   // init
   cp=0;
   for(int i=0;i<N;i++) { idx[0][i]=i; ans[i]=1; };
   map<long long,int> mymap;
   for(int k=0;k<(MAXTRY-1);k++){
           acc=0;
	   for(int i=0;i<N-1;i++){
		   acc^=A[idx[k][i]];
		   if(mymap[acc]>0){  // found  probable match
                       int k1 = mem[mymap[acc]].s;
                       int i1 = mem[mymap[acc]].e;
                       if(findmatch(k,i,k1,i1)){
                           return 1;
                       }
		   } else {
                       mymap[acc]=++cp;
                       mem[mymap[acc]].init(k,i);
		   }
	   }
           randomize(k+1);
    }  
}
int main(){
   int T;
   scanf("%d",&T);
   while(T-->0){
      scanf("%d",&N);
      for(int i=0;i<N;i++){
          scanf("%lld",&A[i]);
      }
     //check
      solve();
      for(int i=0;i<N;i++){
          if(i>0) printf(" ");
          printf("%d",ans[i]);
      }
      printf("\n");
   } 
}
