#include<iostream>
#include<cmath>
using namespace std;
#define PRIMES  99999
long long primes[PRIMES]={0};
int isPrime(long long n){
	if(n<2){
		return 0;
	}
	if(n==2||n==3){
		return 1;

	}
	if(n%2==0||n%3==0){
		return 0;
	}
 long long sqrt1 = (long long) sqrt(n);
 for(int i=0;primes[i]<=sqrt1;i++){
	 if(n%primes[i]==0){
		 return 0;
	 }
 }
 return 1;
}
void fillPrimes(){
	primes[0]=2;
	int count=1;
	for(long long i=3;count<PRIMES;i+=2){
		if(isPrime(i)){
			primes[count++]=i;
		}
	}
}	
long long abs(long long n){
	if(n<0) return -1*n;
	return n;
}
void log(char *str){
//	cout<<str<<endl;
}
long long getCellVal(long long x, long long y){
     if(x==0&&y==0){
	     return 0;
     }
     long long absx = abs(x);
     long long absy = abs(y);
     if(absx==absy){
	     // we are at the corner
	     long long n = absx; // square number
	     if(x>0&&y<0){
		     return 4*n*(n+1);
	     } else if(x>0&&y>0){
		     return 4*n*(n-1)+2*n;
	     } else if(x<0&&y>0){
		     return 4*n*(n-1)+4*n;
	     } else {
		     return 4*n*(n-1)+6*n;
	     }

     } else {
	     log(" we are at the wall");
	     long long n = absx>absy?absx:absy;
	     if(absx==n){
		     log(" are on verticals");
		     if(x>0){
			     log("we are on right vertical");
			     return 4*n*(n-1)+2*n-(n-y);
		     } else {
			     log("we are left vertical");
			     return 4*n*(n-1)+4*n+(n-y);
		     }
	     } else {
		     // we are on horizontals
		     if(y>0){
			     // we are on upper horzontal
			     return 4*n*(n-1)+2*n+(n-x);
		     } else {
			     // we are bottom horizontal
			     return 4*n*(n+1)-(n-x);
		     }
	     }
     }
}
int check(long long x,long long y){
	if(x>2000000||x<-2000000||y>2000000||y<-2000000){
		return 0;
	}
  return isPrime(getCellVal(x,y));
}
int symCheck(long long x,long long y,long long x0,long long y0){
 return check(x0+x,y0+y)||check(x0-x,y0-y)||check(x0+x,y0-y)||check(x0-x,y0+y);
}
int searchDist(long long dist,long long x0,long long y0){
	long long y=dist;
	for(long long x=0;x<=dist;x++){
          if(symCheck(x,y,x0,y0)){
		  return x+y;
	  }
            if(x!=y){
               if(symCheck(y,x,x0,y0)){
		       return x+y;
	       }
	    }
	}
	return 0;
}
long long findMinDist(long long x, long long y){
	
	long long val = getCellVal(x,y);
	if(isPrime(val)){
		log("true");
		return 0;

	}
	long long dist = 1;
	int found = 0;
	while(!found){
	 found=searchDist(dist,x,y);
	}
	return found;
}
int main(){
	fillPrimes();
	int T = 0;
	cin>>T;
	long long x;
	long long y;
	for(int i=0;i<T;i++){
		cin>>x;
		cin>>y;
		cout<<findMinDist(x,y)<<endl;
	}
}
