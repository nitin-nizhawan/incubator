#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
srand(time(NULL));
int num_tests=5000;
cout<<num_tests+12<<endl;
 while(num_tests--){
  unsigned long long a = (unsigned long long)(rand()%400000)+(unsigned long long)(rand()%500000)*(10000ULL);
  unsigned long long b = (unsigned long long)(rand()%400000)+(unsigned long long)(rand()%500000)*(10000ULL);
  if(a>b){
  cout<<b<<" "<<a<<endl;
  } else {
   cout<<a<<" "<<b<<endl;
  }
  
 }
  
cout<<"1 10"<<endl;
cout<<"1 100"<<endl;
cout<<"1 1000"<<endl;
cout<<"1 10000"<<endl;
cout<<"1 100000"<<endl;
cout<<"1 1000000"<<endl;
cout<<"1 10000000"<<endl;
cout<<"1 100000000"<<endl;
cout<<"1 1000000000"<<endl;
cout<<"1 10000000000"<<endl;
cout<<"2345678923 7543562845"<<endl;
cout<<"499875921 499875921"<<endl;


}
