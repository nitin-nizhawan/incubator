#include<iostream>
#include "bigint/BigInteger.hh"

long long d(long long n){
	long long sum=0;
	while(n>0){
		sum+= n%10;
                n/=10;
	}
	return sum;
}
int main(){
	long long eleven=11;
	long long tenpow[12]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000};
        long pown=1;
	BigInteger tenpowb = 10;
	for(int k=0;k<23;k++){
		cout<<"10^"<<pown<<"%23 : "<<(tenpowb%23)<<"\n";
		pown++;
		tenpowb*=10;
	}
	long long prod = 1;
	for(long long j=0;j<12;j++){
          prod*=eleven;
	}
	cout<<" N = "<<prod<<endl;
	long long n = 23;
	long long count = 0;
        long long mul = 0;
	int powcount=3;
        for(long long i=43478299;mul<10000000000;i++){
		mul = n*i;
		
	        long long sum = d(mul);
		if(mul<0){ cout<<mul<<endl; return 1;}

	        if(sum==23){
			if(mul>tenpow[powcount]){
				cout<<"S(n): "<<powcount<<" "<<count<<" "<<mul<<" "<<i<<endl;
				powcount++;
			}
		//cout<<i<<" "<<mul<<endl;
		count++;
		}
	}
	cout<<count<<endl;

}
