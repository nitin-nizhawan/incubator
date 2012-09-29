#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    long long T=300000;
    cout<<T<<endl;
    while(T--){
     cout<<(1000ULL)*(rand()%1000)+rand()%1000<<endl;
    }
}
