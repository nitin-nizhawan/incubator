#include<iostream>
#include<vector>
#include<string>
using namespace std;  
                    //   zero,one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen,fourteen,fifteen, sixteen, seventeen, eighteen, nineteen} 
long singledigits[20] = {0,   3,  3,  5,    4,   4,   3,  5,    5,    4,   3,  6,     6,    8,       8,       7,      7,       9,         8,        8 };
              //   twenty,thirty,forty,fifty,sixty,seventy,eighty,ninety,Hundred, thousand
long tees[11] = {0,0,6,     6,     5,     5,    5,    7,      6,     6,     7 }; 
  
long long getsize(int i){
	if(i<20){
		 return singledigits[i];
		 }
	if(i<100){
	return	tees[i/10]+singledigits[i%10];
	}
	if(i==100){
	 return 3+7;
	}
	if(i<1000){
		   // one            hundred and
       if(i%100==0){
	       return singledigits[i/100]+7;
       }
	return 	singledigits[i/100] +7 +      3+  getsize(i%100);
	}
	return 3+8;//thousand
}
int main(){
	long n;
	while(cin>>n){
	cout<<getsize(n)<<endl;
	long long sum = 0;
	for(int i=1;i<=n;i++){
		sum+=getsize(i);
	}
	cout<<"Ans: "<<sum<<endl;
	}
  
}
