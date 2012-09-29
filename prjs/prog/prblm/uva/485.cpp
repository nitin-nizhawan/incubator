#include<iostream>
#include<cstdio>
using namespace std;
struct Num {
  char val[100];
  int d;
};
void add(Num &t,Num &s){
    int c=0;
    int max = t.d>s.d?t.d:s.d;
    for(int i=0;i<max;i++){
      int val = t.val[i]+s.val[i]+c;
      t.val[i]=val%10;
      c = val/10;
    }
    if(c>0){
      t.d = max+1;
      t.val[max]=c;
    } else {
      t.d=max;
    }
}
int compare(Num &t, Num &t2){
    if(t.d>t2.d){
        return 1;
    } else if(t.d<t2.d){
        return -1;
    } else {
        for(int i=t.d-1;i>=0;i--){
            if(t.val[i]>t2.val[i]){
                  return 1;
            } else if(t.val[i]<t2.val[i]) {
                  return -1;
            }
        }
    }
    return 0;
}
void print(Num &p){
 for(int i=p.d-1;i>=0;i--){
    printf("%d",p.val[i]);
 }
}
void reset(Num &st){
 for(int i=0;i<100;i++){
     st.val[i]=0;
 }
 st.d=0;
}
struct Num mem[2][250];
int main(){
    bool flag=1;
    int cur=0;
    int nxt=1;
    struct Num MAX;
    reset(MAX);
    MAX.d=60;
    MAX.val[MAX.d-1]=1;
    int row = 1;
    mem[cur][0].d=1;
    mem[cur][0].val[0]=1;
    while(flag){
       // print row
       for(int i=0;i<row;i++){
           if(i) printf(" "); 
           print(mem[cur][i]); 
         /*  if(compare(mem[cur][i],MAX)>=0){
               printf("hello");
               flag=0;
           }*/ if(row>204) flag=0;
       }
       printf("\n");
       // calculate next row;
       mem[nxt][0].d=1;
       mem[nxt][0].val[0]=1;
       for(int i=1;i<row;i++){
           reset(mem[nxt][i]);
           add(mem[nxt][i],mem[cur][i-1]);
           add(mem[nxt][i],mem[cur][i]);
       }
       row++;
       mem[nxt][row-1].d=1; mem[nxt][row-1].val[0]=1;
       nxt = 1-nxt;
       cur = 1- cur;
    }
}
