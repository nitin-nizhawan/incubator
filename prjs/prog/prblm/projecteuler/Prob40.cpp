#include<iostream>
using namespace std;
int getNthDigits(long n){
  long long numdigits[8] = {0,9,90,900,9000,90000,900000,9000000};
  long long tenpow [8] =     {1,10,100,1000,10000,100000,1000000};
  long long lastnumbers[8]= {0,9,99,999,9999,99999,999999,9999999};
  long long digitscovered [8];
  digitscovered[0] = 0;
  int i=1;
  for(i=1;i<8;i++){
    digitscovered[i] = i*numdigits[i]+digitscovered[i-1];
    if(digitscovered[i]>n){
	    break;
    }
  }
  cout<<" i = "<<i<<endl;
  long remainingdigits = n - digitscovered[i-1];
  cout<<" remainingdigits "<<remainingdigits<<endl;
  long numberofnumbersrequiredatleast = remainingdigits/i;
  cout<<" numberofnumbersrequiredatleat "<<numberofnumbersrequiredatleast<<endl;
  long lastnumberreached = lastnumbers[i-1]+numberofnumbersrequiredatleast;
  cout<<" lastnumberreached = "<<lastnumberreached<<endl;
  remainingdigits = remainingdigits%i;
  cout<<" remainingdigits "<<remainingdigits<<endl;
  if(remainingdigits>0){
	  lastnumberreached+=1;
	  cout<<" ten pow "<<tenpow[i+1-remainingdigits]<<endl;
  return (lastnumberreached%tenpow[i+1-remainingdigits])/tenpow[i-remainingdigits];
  }
  else { return (lastnumberreached)%10;}
   
}

int main(){
  cout<<getNthDigits(1)<<endl;
  cout<<getNthDigits(10)<<endl;
  cout<<getNthDigits(100)<<endl;
  cout<<getNthDigits(1000)<<endl;
  cout<<getNthDigits(10000)<<endl;
  cout<<getNthDigits(100000)<<endl;
  cout<<getNthDigits(1000000)<<endl;
}
