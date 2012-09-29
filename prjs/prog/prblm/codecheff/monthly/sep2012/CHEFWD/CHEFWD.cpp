#include<stdio.h>
long long ra,rb,rc,rd;
long long ba,bb,bc,bd;
long long PRIME=1000000007;
long long N;

long long ta,tb,tc,td,tcd,tabc;
void baseWithResult2(){
     tcd=(bc+bd)%PRIME;
     tabc = ((ba+bb)%PRIME+bc)%PRIME;
     ta = ((((tcd*ra)%PRIME + (bc*rb)%PRIME)%PRIME + (tabc*rc)%PRIME)%PRIME + (ba*rd)%PRIME)%PRIME;
     tb = ((((bc*ra)%PRIME + (bd*rb)%PRIME)%PRIME + (ba*rc)%PRIME)%PRIME + (bb*rd)%PRIME)%PRIME;
     tc = ((tcd*rc)%PRIME + (bc*rd)%PRIME)%PRIME;
     td = ((bc*rc)%PRIME + (bd*rd)%PRIME)%PRIME;
     ra=ta;rb=tb;rc=tc;rd=td;
}
void baseWithBase2(){
     tcd=(bc+bd)%PRIME;
     tabc = ((ba+bb)%PRIME+bc)%PRIME;
     ta = ((((tcd*ba)%PRIME + (bc*bb)%PRIME)%PRIME + (tabc*bc)%PRIME)%PRIME + (ba*bd)%PRIME)%PRIME;
     tb = ((((bc*ba)%PRIME + (bd*bb)%PRIME)%PRIME + (ba*bc)%PRIME)%PRIME + (bb*bd)%PRIME)%PRIME;
     tc = ((tcd*bc)%PRIME + (bc*bd)%PRIME)%PRIME;
     td = ((bc*bc)%PRIME + (bd*bd)%PRIME)%PRIME;
     ba=ta;bb=tb;bc=tc;bd=td;
}


void raisePow2(long long exp){
      ra=rb=rc=0;rd=1;
      ba=bb=bd=0;bc=1;
      while(exp>0){
             if(exp%2==1){
                 baseWithResult2();
                 exp-=1;
             }
             baseWithBase2();;
//printBase();
             exp = exp/2;
      } 

     
}


long long solve2(){
    raisePow2(N-2);
    return ((((ra*21)%PRIME+(rb*13)%PRIME)%PRIME+(rc*18)%PRIME)%PRIME+(rd*5)%PRIME)%PRIME;
}
int  main(){
   int T;
   scanf("%d",&T);
   while(T-->0){
       scanf("%lld",&N);
      if(N<2){
          printf("%d\n",0);
      } else if(N==2){
           printf("%d\n",5);
       } else{

         printf("%lld\n",solve2()); 
  //printResult();
//         printf("result : %lld,%lld,%lld,%lld\n",ra,rb,rc,rd);
     }
   }
}
