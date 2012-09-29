/*
ID: nitin.n1
PROG: fact4
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define MAX 1100
using namespace std;
int num[MAX];
// max limit for input N is 4220. There are 1round 1052 zeros in 4220!
// therefore we calculate N! mod (10^x) where is x is number larger than 1052
// the we print first no zero digit
int main() {
    ofstream fout ("fact4.out");
    ifstream fin ("fact4.in");
    int N;
    fin >>N;
    num[0]=1;
    int cl=1;
    int c=0;
    for(int i=1;i<=N;i++){
        c=0;
        for(int j=0;j<cl;j++){
            int cv = num[j]*i+c;
            num[j] = cv%10;
            c = cv/10;
        }
        while(c>0){
            num[cl++]=c%10;
            if(cl>MAX){
                break;
            }
            c/=10;
        }
    }
    int i=-1;
    while(num[++i]==0);
    fout<<num[i]<<"\n";
    return 0;
}

