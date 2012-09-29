
/*
ID:nitin.n1
PROG: stamps
LANG: C++
*/
#include<fstream>
#include<iostream>
using namespace std;
int nums[205];
int K,N;
int count[3000000];
int main(){
    ofstream fout((const char*)"stamps.out");
    ifstream fin((const char*)"stamps.in");
   fin>>K;
   fin>>N;
   for(int i=0;i<N;i++){
       fin>>nums[i];
   }
   for(int i=1;;i++){
       int minC = 1<<30;
       for(int j=0;j<N;j++){
           if((i-nums[j])>=0){
               int pcount = count[i-nums[j]]+1;
               if(pcount<=K&&pcount<minC){
                   minC=pcount;
               }
           }
       }
       count[i]=minC;
       if(count[i]>=(1<<30)){
           fout<<i-1<<"\n";
           return 0;
       }
   }
}
