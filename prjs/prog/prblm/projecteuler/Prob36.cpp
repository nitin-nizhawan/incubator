#include<iostream>
using namespace std;
long getEvenDigitPalin(long a,long b,long c){
	long abc = 100*a+10*b+c;
	if(abc>=100){
		return abc*1000+(c*100+b*10+a); //cba
	} else if(abc>=10){
		return abc*100+(c*10+b); //cb
	} else {
		return abc*10+c;
	}

}
long getOddDigitPalin(long a,long b,long c){
	long abc = 100*a+10*b+c;
	long ab =a*10+b; // reversed
	if(ab>=10){
		return abc*100+(b*10+a); // ba
	}
	else if(ab>=1){
		return abc*10+b; // only b
	} else {
           return abc;
	}
}
int isPalinB2(long p){
	long fwd=p;
	long rev=0;
	long base=2;
        long digit=0;
	while(fwd>0){
		digit=fwd%base;
		rev = rev*base+digit;
		fwd/=base;
	}
	return p==rev;
}
int main(){
	long long sum=0;
	for(int a=0;a<10;a++){
		for(int b=0;b<10;b++){
			for(int c=1;c<10;c+=2){ // only odd numbers can be palin in base 2
				if(a==0&&b==0){
					// single and double digit
					if(isPalinB2(c)){
						sum+=c;
					}
					if(isPalinB2(c*11)){
						sum+=c*11;

							}
				}
				if(a==0){


					// three and four digits
					if(isPalinB2(c*100+b*10+c)){
                                            sum+=c*100+b*10+c;
					}
					if(isPalinB2(c*1000+b*100+b*10+c)){
						sum+=c*1000+b*100+b*10+c;

					}
				}
			 long p1=getOddDigitPalin(c,b,a);
			 long p2=getEvenDigitPalin(c,b,a);
			 cout<<p1<<" "<<p2<<endl;
			 if(isPalinB2(p1)){
			    sum+=p1;
			 }
			 if(isPalinB2(p2)){
			    sum+=p2;
			 }
			}
		}
	}
	cout<<sum<<endl;
}
