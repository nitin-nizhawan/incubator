#include <iostream>
using namespace std;
#define stacksize 1000000
int profit[stacksize];
long long cache[stacksize];
long long stack[stacksize];
int top=-1;
void push(long long n){
	if(top>=stacksize){
		cout<<"stackofferflow";
	}
	stack[++top]=n;
}
long long pop(){
	return stack[top--];
}
long long maxprofit(long long n1){
  push(n1);
  long long profitnet = 0;
  while(top>-1){
   long long n = pop();
	long long n2 = n/2,n3=n/3,n4=n/4;
	 if (n2+n3+n4+n/12-n<1){
		continue;
	 }
	 if(n2<stacksize&&profit[(int)n2]>-1){
		 profitnet+=profit[(int)n2];
	 } else {
		 push(n2);
	 }
       
         if(n3<stacksize&&profit[(int)n3]>-1){
		 profitnet+=profit[(int)n3];
	 }	 else {
		 push(n3);
	 }
	 
	 if(n4<stacksize&&profit[n4]>-1){
               profitnet+=profit[n4];
	 } else {
		 push(n4);
	 }
   }

  
  return n1/12+profitnet;
}
int main(){
	long long n;
	for(int k=0;k<stacksize;k++){
		profit[k]=-1;
	}
        for(int i=0;i<stacksize;i++){
		 if(i<12){
	        
              profit[i]=(i/2+i/3+i/4)-i;
	         if(profit[i]<0){
			 profit[i]=0; // we know how to make 0 profit at least
		 }
		 } else {
                      profit[i] = maxprofit(i) ;
		 }
       }
		while(cin>>n){
			cout<<n+maxprofit(n)<<endl;
		}
}
