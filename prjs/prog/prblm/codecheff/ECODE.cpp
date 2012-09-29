#include<cstdio>
//#include<iostream>
//using namespace std;
typedef unsigned long long ull;
ull C[20];
ull B[20];
ull A;
int N;
bool toBase(ull base,ull NUM,ull *out){
    int i=0;
    bool retVal=true;
    while(NUM){
        C[i++]=NUM%base;
        NUM/=base;
        if(C[i-1]>9){
            retVal=false;
        }
    }    
    return retVal;
}
bool add(ull base,ull *tgt,ull *src){
    int i=0;
    bool retVal=true;
    ull carry=0;
    for(int i=0;i<16;i++){
        ull val = tgt[i]+src[i]+carry;
        tgt[i]=val%base;
        carry = val/base;
        if(tgt[i]>9){
            retVal=false;
        } 
    }
    return retVal;
}
void printSol(){
    for(int i=N-1;i>=0;i--){
        printf("%llu",C[i]);
    }
    printf("\n");
}
void init(){
for(int i=0;i<20;i++){
    C[i]=0;
    B[i]=0;
}
}
int main(){
    ull b,g;
    scanf("%d %llu %llu %llu",&N,&A,&b,&g);
//    cout<<N<<" "<<A<<" "<<b<<" "<<g<<endl;    
    if(toBase(A,g,C)){
        printSol();
    } else {
      toBase(A,b,B);
      while(!add(A,C,B));
      printSol();
    }
}
