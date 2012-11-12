#include<stdio.h>
#include<map>
using namespace std;
#define setb(p,x) ((p)|=(1LL<<(x)))
#define getb(p,x) ((p)&(1LL<<(x)))
#define flip(p,x) ((p)^=(1LL<<(x)))
#define unset(p,x) ((p)&=~(1LL<<(x)))
int N,M,Q;
int Sr,Sc;
int P1[6],P2[6];
long long tc[2000000];
int st,end;
long long game;
map <long long,int> mymap;
int idx(int r, int c){
    return r*M+c;
}
void set(int r,int c){
    setb(game,idx(r,c));
}
int mv0(int r,int c){
    int r1=r,c1=c;
    r1-=P1[0];
    while(r1>=0){
        flip(game,idx(r1,c1));
	r1-=P1[0];
    }
    r1=r+P2[0];
    while(r1<N){
       flip(game,idx(r1,c1));
       r1+=P2[0];
    }
}
int mv1(int r,int c){
    int r1=r,c1=c;
    c1=c-P1[1];
    while(c1>=0){
        flip(game,idx(r1,c1));
        c1-=P1[1];
    }
    c1=c+P2[1];
    while(c1<M){
       flip(game,idx(r1,c1));
       c1+=P2[1];
    }
}
int mv2(int r,int c){
    int r1=r,c1=c;
    r1-=P1[2];
    while(r1>=0){
        flip(game,idx(r1,c1));
        r1-=P1[2];
    }
    r1=r;c1=c+P2[2];
    while(c1<M){
       flip(game,idx(r1,c1));
       c1+=P2[2]; 
    }
}
int mv3(int r,int c){
    int r1=r,c1=c;
    c1+=P1[3];// R
    while(c1<M){
        flip(game,idx(r1,c1));
	c1+=P1[3];// R
    }
    r1=r+P2[3];c1=c; //D
    while(r1<N){
       flip(game,idx(r1,c1));
       r1+=P2[3];
    }
}
int mv4(int r,int c){
    int r1=r,c1=c;
    r1+=P1[4];  //D
    while(r1<N){
        flip(game,idx(r1,c1));
	r1+=P1[4];  //D
    }
    c1=c-P2[4];r1=r; //L
    while(c1>=0){
       flip(game,idx(r1,c1));
       c1-=P2[4];
    }
}
int mv5(int r,int c){
    int r1=r,c1=c;
    c1-=P1[5]; //L
    while(c1>=0){
        flip(game,idx(r1,c1));
	c1-=P1[5]; //L
    }
    r1=r-P2[5];c1=c; //U
    while(r1>=0){
       flip(game,idx(r1,c1));
       r1-=P2[5];
    }
}

int makeMove(){
    long long gc = game;// create a copy of game state
    int rowset[40];
    int colset[40];
    for(int r=0;r<N;r++){
        rowset[r]=0;
        for(int c=0;c<M;c++){
	    if(getb(gc,idx(r,c))){
                rowset[r]++;
	    }
        }
    }
    for(int c=0;c<M;c++){
       colset[c]=0;
       for(int r=0;r<N;r++){
          if(getb(gc,idx(r,c))){
           colset[c]++;
          }
       }
    }
    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++){
            if(getb(gc,idx(r,c))){
                int nbit = (rowset[r]+colset[c]-1)%6;     
                switch(nbit){
                    case 0: mv0(r,c); break;
                    case 1: mv1(r,c); break;
                    case 2: mv2(r,c); break;
                    case 3: mv3(r,c); break;
                    case 4: mv4(r,c); break;
                    case 5: mv5(r,c); break;
                }
            }
        }
    }
   int cnt=0;
   for(int r=0;r<N;r++){
      for(int c=0;c<M;c++){
         if(getb(game,idx(r,c))){
             cnt++;
         }
      }
   } 
   return cnt;
}
void printGame(){
    for(int r=0;r<N;r++){
       for(int c=0;c<M;c++){
           if(getb(game,idx(r,c))){
              printf("1 ");
           } else { printf("0 ");}
       }
       printf("\n");
    }
}
void init(){
    set(Sr,Sc);
    mymap[game]=1;
    for(int i=1;i>=0;i++){
       long long cnt=makeMove();
        //printGame();
        if(mymap[game]>0){
           st=mymap[game]-1;
           end=i-1;
           //printf(" repeated after %d moves\n",i); 
           break;
        }
        tc[i]=cnt+tc[i-1];
        mymap[game]=i+1;
    }
}
long long solveQ(long long n){
    if(n<=end){
       return tc[n];
    }
    long long ans=tc[end];
    n -= end;
    long long p = end-st+1;
    long long mul = n/p;
    long long rem = n%p;
    ans = ans+ mul*tc[end];
    if(st>0) ans =ans - mul*tc[st-1];
    ans = ans + tc[st+rem-1]; 
    if(st>0) ans = ans - tc[st-1];
    return ans;
}
int main(){
    tc[0]=1;
    scanf("%d",&N);
    scanf("%d",&M);
    scanf("%d",&Q);
    scanf("%d",&Sr);Sr--;
    scanf("%d",&Sc);Sc--;
    for(int i=0;i<6;i++){
       scanf("%d",&P1[i]);scanf("%d",&P2[i]);
    }
    init();
  //  printf("start %d, end%d\n",st,end);
    for(int i=0;i<Q;i++){
      long long n;
            scanf("%lld",&n);
      printf("%lld\n",solveQ(n));
    }
}

