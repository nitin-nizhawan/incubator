/*
ID: nitin.n1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
typedef unsigned long long ull;
ull starts[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
bool isPrime(ull n){
    if(n<2){
        return false;
    }
    for(ull i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
bool isSPrime(ull n){
    ull a =n;
    while(a>0){
        if(!isPrime(a)){
            return false;
        }
        a = a/10;
    }
    return true;
}
ull fs[]={2,3,5,7};
ull store[2][100000];
ull ss[]={1,3,5,7,9};
int flag=0;
int fcount=0;
void calcprimes(ull n){
    if(n<=1){
        return;
    }
    else{
        calcprimes(n-1);
        int ncount=0;
        for(int i=0;i<fcount;i++){
            for(int j=0;j<5;j++){
                if(isPrime(store[flag][i]*10+ss[j])){
                    store[1-flag][ncount++]=store[flag][i]*10+ss[j];
                }
            }
        }
        fcount = ncount;
        flag = 1-flag;
    }
}
int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    int a;
    fin >> a;
    store[flag][0]=2;
    store[flag][1]=3;
    store[flag][2]=5;
    store[flag][3]=7;fcount=4;
    if(a==1){
        fout<<2<<"\n"<<3<<"\n"<<5<<"\n"<<7<<"\n";
    } else {
        calcprimes(a-1);
        int ncount=0;
        for(int i=0;i<fcount;i++){
            for(int j=0;j<5;j++){
                if(isPrime(store[flag][i]*10+ss[j])){
                    fout<<store[flag][i]*10+ss[j]<<"\n";
                }
            }
        }

    }
    return 0;
}

