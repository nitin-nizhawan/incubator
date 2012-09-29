/*
ID: nitin.n1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
typedef unsigned long long ull;
using namespace std;
ull pprimes[60000];
int primesCount=0;
int fcount=0;
bool isPrime(ull n){
    for(int i=2;i*i <= n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
ull revapp(ull a,ull b){
    while(b>0){
        a = a*10+b%10;
        b = b/10;
    }
    return a;
}
int numlen(ull n){
    int len =0;
    while(n>0){
        len++;
        n/=10;
    }
    return len;
}
int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    ull a, b;
    fin >> a >> b;
    int na = numlen(a);
    int nb = numlen(b);
    pprimes[0]=2;pprimes[1]=3;pprimes[2]=5;pprimes[3]=7;
    primesCount=4;
    ull num=0;
    for(ull l=1;num<=b;l++){
        num = revapp(l,l);
        if(isPrime(num)){
            pprimes[primesCount++]= num;
        }
    }
    num=0;
    for(ull l=1;num<=b;l++){
        for(ull i=0;i<=9;i++){
             num = revapp(l*10+i,l);
            if(isPrime(num)){
                pprimes[primesCount++]=num;
            }
        }
    }
    sort(pprimes,pprimes+primesCount);
    for(int i=0;i<primesCount;i++){
        if(pprimes[i]>=a&&pprimes[i]<=b){
            fout<<pprimes[i]<<"\n";
        }
    }
    return 0;
}

