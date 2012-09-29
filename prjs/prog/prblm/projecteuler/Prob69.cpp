#include <iostream>
#include <cmath>
using namespace std;
long long primes [100000];
int count=0;
int isPrime(long long n){
	double sqrt1 =  ::sqrt(n);
	for(int i=0;primes[i]<=sqrt1;i++){
		cout<<primes[i]<<","<<i<<","<<sqrt1<<","<<n<<endl;
		if(n%primes[i]==0){
			return 0;
		}
	}
	return 1;
}
long long doit(){
primes[0]=2;
count=1;
long long prod=2;
for(int i=3;count<100000;i+=2){
	if(isPrime(i)){
		if(prod*i>1000000){
			return prod;
		}
		prod=prod*i;
		
		primes[count++]=i;

	}
}
}
int main(){
	cout<<doit()<<endl;
}
