#include<iostream>
#include<cmath>
using namespace std;
#define PCOUNT 99999
#define SWAPMAX(l,m) if(streaklen>max_p_streak){ \
       cout<<"max streak "<<streaklen<<" for "<<l<<" "<<m<<endl; \
                        max_a=l; \
                        max_b=m; \
                        max_p_streak=streaklen;  }

long long primes[PCOUNT];
bool isPrime(long long n){
  long long sqrt1 = (long long) sqrt(n);
  int i=0;
  while(primes[i]<=sqrt1){
      if(n%primes[i++]==0){
         return false;
      }
  }
  return true;
}
void createPrimes(){
   primes[0]=2;
   primes[1]=3;
   long long num=5;
   int count=2;
   while(count<PCOUNT){
      if(isPrime(num)){ 
         primes[count++]=num;
      }
      num+=2;
   }
}
long long getNextVal(long long cval,long long n,long long a){
   return cval+2*n-1+a;
}
long getStreakLength(long long a, long long b){
  long long n=0;
  while(isPrime(b=getNextVal(b,++n,a)));
  return n;
}
int main(){
  long max_a = -1000;
  long max_b=-999;
  long max_p_streak=0;
  createPrimes();
  cout<<"Created all primes"<<endl;
  // prime less than 1000;
  int x=100;
  for(;primes[x]<1000;x++);
 cout<<"Found sub 1000 primes"<<primes[x-1]<<endl;
  int i=0;  
  long a,b;
  for(b=primes[0];i<x;i++,b=primes[i]){
    for(a=-1000;a<1000;a++){
       long streaklen = getStreakLength(a,b);
       if(streaklen>max_p_streak){
         max_a=a;
         max_b=b;
         max_p_streak=streaklen;
       }
       streaklen = getStreakLength(a,0-b);
       if(streaklen>max_p_streak){
         max_a=a;
         max_b=0-b;
         max_p_streak=streaklen;
       }
    }
  }
  cout<<max_a<<" "<<max_b<<" "<<max_a*max_b<<endl;
}
