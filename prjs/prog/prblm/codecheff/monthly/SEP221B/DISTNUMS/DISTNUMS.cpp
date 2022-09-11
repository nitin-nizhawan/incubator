#include <iostream>
#include<algorithm>
#include<set>
#define READ_ARR(X,NUM) {for(int i=0;i<NUM;i++) { cin>>X[i]; }}
#define FORI(MAX) for(int i=0;i<MAX;i++) 
#define FORRI(MAX) for(int i=(MAX)-1;i>=0;i--)
#define PARR(X,MAX) {FORI(MAX){ cout<<X[i]<<", "; } cout<<endl;}
using namespace std;

#ifdef ENABLE_PERF
#include<chrono>
using namespace std::chrono;
auto perf_start = high_resolution_clock::now();
auto perf_stop = high_resolution_clock::now();
auto perf_duration = duration_cast<microseconds>(perf_stop - perf_start);
#define PERF_START() {perf_start=high_resolution_clock::now();}
#define PERF_END(PERF_NAME) {perf_stop=high_resolution_clock::now(); \
                         perf_duration = duration_cast<microseconds>(perf_stop - perf_start); \
                         cout << "PERF::"<<PERF_NAME<<": "<< perf_duration.count() << " microseconds" << endl;}
#else
#define PERF_START() 
#define PERF_END(PERF_NAME)
#endif


#define MAXPRIME 600

long primes[MAXPRIME];

const long MOD = 1000000007;
// luckily MOD2 is also a prime
const long MOD2 = (MOD-1)/2L;
long N;
long K;
const long MAX_N = 10000000;
long NP[MAX_N];
long NE[MAX_N];
int EXP_LEN=0;
void prime_expo22(long N){
  long prime = 2;
  NE[EXP_LEN]=0;
  while(N%prime == 0){
    N=N/prime;
    NE[EXP_LEN]++; 
  }
  if(NE[EXP_LEN] > 0){
    NP[EXP_LEN]=prime;
    EXP_LEN++;
  }

  prime = 3;
  while(prime <= N){
    NE[EXP_LEN]=0;
    while(N>0 && N%prime==0){
       N=N/prime;
       NE[EXP_LEN]++;
    }
    if(NE[EXP_LEN] > 0){
      NP[EXP_LEN]=prime;
      EXP_LEN++;
    }
    prime+=2;
  }
}
void prime_expo(long N){
  NE[EXP_LEN]=0;

  long prime = primes[0];
  int i=0;
  while(N > 1 && i < MAXPRIME-10){
    NE[EXP_LEN]=0;
    while(N%prime==0){
       N=N/prime;
       NE[EXP_LEN]++;
    }
    if(NE[EXP_LEN] > 0){
      NP[EXP_LEN]=prime;
      EXP_LEN++;
    }
    i++;
    prime=primes[i];
    if(prime*prime > N){
      break;
    }
  }
  if(N > 1){
    NE[EXP_LEN]=1;
    NP[EXP_LEN]=N;
    EXP_LEN++;
  }
}

// multiplicative inverse mod MOD
long mi(long a){
    long n = MOD;
    long t=0;   
    long newt=1L;
    long r=n; 
    long newr=a;

    while(newr!=0){
        long q=r/newr;
        long tmp =t;
        t = newt;
        newt = tmp - q*newt;
        tmp = r;
        r = newr;
        newr = tmp - q*newr;
   }

   if(r>1){
      return -1;
   }
   if(t<0){
     t = t+n;
   }

   return t ;
}
long raiseBy2powKSimple(long A,long K){
  for(int i=0;i<K;i++){
    A = (A * A)%MOD;
  }
  return A;
}
long expBySq(long x, long n,long M){
    if(n<0){
      x=1/x;
      n=-n;
    }
    if(n==0){ return 1;}
    long y=1;
    while(n>1){
      if(n%2==0){
        x=(x*x)%M;
        n=n/2;
      }
      else{
        y=(x*y)%M;
        x=(x*x)%M;
        n=(n-1)/2;
      }
    }
    return (x*y)%M;
}

long raiseBy2powK(long A, long K){
  if(K < 3){
    return raiseBy2powKSimple(A,K);
  }
  // calculate 2^K-1 % MOD2
  long B=expBySq(2L,K-1,MOD2);
  // 2^K % (MOD-1) ~ 2*(2^K-1) (MOD2) since MOD-1 = 2*MOD2 
  long B2 = (2L*B)%MOD;
  // now since A^(MOD-1) ~ 1 (MOD)
  // we only need to calulate A^B2 (MOD)
  return expBySq(A,B2,MOD);
}
unsigned long one_term(long P,long p,long K){
  long p_power = 1;
  long P_p = 1;
  // P^p
  for(int i=0;i<p;i++){
    P_p = ( P_p *P)%MOD;
  }
  p_power=P_p;

PERF_START()
  // now (P^p) ^  (2^K)
  p_power = raiseBy2powK(p_power,K);
PERF_END("raiseBy2powK")
  // P^(2^K * p) + 1
  p_power = (p_power * P) % MOD;



  // p_power - P^p
  p_power = (p_power + MOD - P_p)%MOD;

  // (p_power - 1)/P-1
  long mult_inverse = mi(P-1);
 // cout<<"MI for "<<P<<" : "<<mult_inverse<<endl;
  p_power = (p_power*mult_inverse)%MOD;
  long ans =p_power;// (P*p_power)%MOD;
//  cout<<"one_term_ans: "<<ans<<endl;
  return ans;
}
void solve(){
  EXP_LEN=0;
  cin>>N>>K;
#ifdef ENABLE_PERF
 cout<<"N="<<N<<",K="<<K<<endl;
#endif
// get prime exponenet
PERF_START()
  prime_expo(N); 
PERF_END("prime_expo")
  //PARR(NP,EXP_LEN)
  //PARR(NE,EXP_LEN)
 PERF_START()
  unsigned long ans = 1;
  for(int i=0;i<EXP_LEN;i++){
     ans = (ans * one_term(NP[i],NE[i],K))%MOD;
  }

  PERF_END("result")
  cout<<ans<<endl;
}
bool isPrime(long n,int nextprime){

  for(int i=0;i<nextprime;i++){
    long p = primes[i];
    if(n%p == 0){
      return false;
    }
    if(p*p > n){
      break;
    }
  }
  return true;
}
void calcprimes(){
  primes[0]=2;
  int nextprime=1;
  long testnum=3;
  while(nextprime < MAXPRIME){
    if(isPrime(testnum,nextprime)){
      primes[nextprime]=testnum;
      nextprime++;
    }  
    testnum+=2;
  }
// PARR(primes,MAXPRIME)
}
int main() {
	// your code goes here
	int T;
	cin>>T;
  PERF_START()
  calcprimes();
  PERF_END("calcprimes")
	while(T-- >0){
		solve();
	}
	return 0;
}

