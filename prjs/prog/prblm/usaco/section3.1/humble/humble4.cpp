/*
ID: nitin.n1
PROG: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include<vector>
#include <map>
#define MAX 200000
using namespace std;
unsigned int max_int = 0x00FFFFFF;
int a, b;
unsigned pows[110][40];
unsigned mprimes[110];
unsigned len[110]={0};
unsigned humbles[700000];
//vector<unsigned> humbles;
unsigned lastp[110];
int hcnt=0;
int binsearch(int start, int end,unsigned prime){
    unsigned cval = humbles[end];
    unsigned least = cval/prime +1;
    if(humbles[end]<least){
        return -1;
    }
    int st = start, ed = end, mid;
    while(st<ed){
        mid = st  + (ed-st)/2;
        if(humbles[mid]>=least){
            ed = mid;
        } else {
            st = mid + 1;
        }
    }
    return st;
}
int msearch(int start, int end, unsigned prime){
    if(true){
        unsigned least = (humbles[end])/prime +1;
        unsigned prod = humbles[end]*prime;
        for(int i=start;i<=end;i++){
            if(prime*humbles[i]>humbles[end]){
                return i;
            }
        }
    } else {
        return binsearch(start,end,prime);
    }
}
int findFirstLarger1(unsigned prime,int start, int end){
    for(int i = start;i<=end;i++){
        if(prime*humbles[i]>humbles[end]){
            return i;
        }
    }
}
int findFirstLarger(unsigned prime,int start, int end){
   int lo = start,hi = end,mid;
   unsigned maxVal = humbles[end];
   while(lo<hi){
       mid = lo + (hi-lo)/2;
       if(humbles[mid]>(maxVal/prime)){
           hi = mid;
       } else {
           lo = mid+1;
       }
   }
   return lo;
}
unsigned findNext(int ith){
    unsigned lastHmbl = humbles[ith-1];
    int k = findFirstLarger(mprimes[0],lastp[0],ith-1);
    unsigned minVal = humbles[k]*mprimes[0];
    int minH = k;
    int minP = 0;
    for(int i=1;i<a;i++){
        k = findFirstLarger(mprimes[i],lastp[i],ith-1);
        if(humbles[k]*mprimes[i]<minVal){
            minVal = humbles[k]*mprimes[i];
            minH = k;
            minP = i;
        }

    }
    lastp[minP]=minH;
    return minVal;
}
int main() {
  //  humbles.resize(2000000);
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");
    fin >> a >> b;
    for(int i=0;i<a;i++){
        fin>>mprimes[i];
        lastp[i]=0;
    }
    humbles[0]=1;
    for(int i=1;i<=b;i++){
       humbles[i] = findNext(i);
    }

    fout<<humbles[b]<<"\n";
    return 0;
}

