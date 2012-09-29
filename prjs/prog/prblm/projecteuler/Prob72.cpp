#include<iostream>
#include<cmath>
using namespace std;
#define PCOUNT 999
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
long long gcd(long m,long n){
   long long r = m%n;
   while(r>0){
       m = n; n = r;
       r = m%n;
   }
   return n;
}

long long totient2(long long m){
  long long t=0;
  for(long long i=1;i<m;i++){
      if(gcd(m,i)==1){
          t++;
      }
  }
  return t;
}

long long totient(long long m){
  if(m==1){
     return 1;
  }
  long long val = m;
  long long num_prod=1; // product of numerator in num*((p1-1)/p1)((p2-1)/p2).....
  long long max_lm = (long long ) sqrt(m);
  for(int i=0;primes[i]<=max_lm;i++){
      
      if(m%primes[i]==0){
        while(m%primes[i]==0){
            m=m/primes[i];
        }
          val=val/primes[i];
          num_prod*=(primes[i]-1l);
      }
  }
 if(m!=1){
     num_prod*=m-1;
     val/=m;
 }
  return num_prod*val;
}
long long numFrac(long long n){
long long retVal = 1;
 for(long long m=1;m<=n;m++){
  retVal +=totient(m);
 }
 return retVal;
}
int main(){
  long long max_num;
  createPrimes();
//  cout<<"last prime = "<<primes[PCOUNT-1]<<endl;
  // totient test 

//for(int i=1;i<38;i++){
//cout<<i<<" : "<<totient(i)<<endl;
//}
 // cin>>max_num;
max_num=1000000l;
  cout<<numFrac(max_num)-2;    

}
