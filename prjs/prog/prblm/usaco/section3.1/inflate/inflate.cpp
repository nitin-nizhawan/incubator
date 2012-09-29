/*
ID: nitin.n1
PROG: inflate
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int M,N;
int cats_p[20001];
int cats_t[20001];
int dp[20001]={0};
int dp2[20001]={0};
int main() {
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");
    int M, N;
    fin >> M >> N;
    for(int i=0;i<N;i++){
        fin>>cats_p[i]>>cats_t[i];
    }
    int maxp=0;
    for(int i=0;i<=M;i++){
        dp[i]=0;
        for(int j=0;j<N;j++){// for each category
            int newval = 0;
            if((i-cats_t[j])>=0) {
                newval=cats_p[j]+dp[i-cats_t[j]];
            }
            if(newval>dp[i]){
                dp[i] = newval;
                dp2[i] = j;
            }
        }
        if(dp[i]>maxp){
            maxp = dp[i];
        }
    }
/*    for(int i=0;i<=M;i++){
        printf("%d-(%d)  ",dp2[i],i);

    }
    printf("\n");*/
    fout << maxp<< endl;
    return 0;
}

