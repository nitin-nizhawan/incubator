#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){

srand(time(NULL));
 int n=1000;
cout<<n<<endl;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
  if(rand()%2==0){
    cout<<"X";
  }  else {
    cout<<".";
  }
}
 cout<<endl;
}

}
