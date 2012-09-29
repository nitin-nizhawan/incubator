#include <iostream>
using namespace std;
long long mult(long long a,long long b,long long mod){
	long long result =0;
	while(b>0){
		if(b&1){
			b= b-1;
			result=(result+a)%mod;
		}
		b=b>>1;
		a = (a+a)%mod;
	}
	return result;
}
int main(){
	unsigned long long pow = 7830457;
	unsigned long long x=2;
	unsigned long long mod1 = 100000;
	unsigned long long mod = mod1*mod1;
	unsigned long long result=1;
	unsigned long long mul = 28433;
	unsigned long long one= 1;
	while(pow>0){
		if(pow&1){
			pow = pow-1;
			result = (mult(result,x,mod))%mod;
		}
		pow = pow>>1;
                x= mult(x,x,mod)%mod;
	}
	result = mult(result,mul,mod)%mod;
	result = (result+one)%mod;
	cout<<result<<endl<<sizeof(long long);
	
	 
}
