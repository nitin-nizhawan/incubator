/*
ID: nitin.n1
PROG: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int a, b;
int primes[200];
int humbles[200000];
int hcount=0;
int start = 0;
//bool isAdded[(1<<30)];
bool generateBatch(){
   int hcount_cpy = hcount;
   for(int i=0;i<a;i++){
       for(int j=start;j<hcount;j++){
           if(hcount_cpy>=200000){
               break;
           }
           int num = humbles[j]*primes[i];
           if(num<(1<<30)){ //&&!isAdded[num]){
    //           isAdded[num]=true;
               humbles[hcount_cpy++]=num;
           }
           
       }
   }
   start = hcount;
   hcount = hcount_cpy;
   return start!=hcount;
}
int main() {
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");
    fin >> a >> b;
    for(int i=0;i<a;i++){
        fin>>primes[i];
        humbles[hcount++]=primes[i];
  //      isAdded[primes[i]]=true;
    }
    bool newadded = true;
    while(hcount<2*a*b&&newadded){
        newadded = generateBatch();
    }
    sort(humbles,humbles+hcount);
    int cnt=1;
    int last = humbles[0];
    for(int i=1;i<hcount;i++){
        if(humbles[i-1]!=humbles[i]){
            cnt++;
        }
        if(cnt==b){
            fout<<humbles[i]<<"\n";
            break;
        }
    }
//    fout<<b<<"\n";
    return 0;
}

