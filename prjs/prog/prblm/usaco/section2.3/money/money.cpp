/*
ID: nitin.n1
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int M, N;
int deno[45];
long long dp[20000][45];
int main() {
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    fin >> M >> N;
    for(int i=0;i<M;i++){
        fin>>deno[i];
    }
    sort(deno,deno+M);
    for(int j=0;j<M;j++){
        dp[0][j]=1;
    }
    for(int j=0;j<M;j++){
        for(int i=1;i<=N;i++){
            if((i-deno[j])>=0){
               dp[i][j] = dp[i-deno[j]][j]; // number of ways we can make i-deno[j] 
            }
            if(j>0){
                dp[i][j]+=dp[i][j-1]; // number of ways we can make i without using jth denomination
            }

        }
    }
/*    for(int i=0;i<=N;i++){
        for(int j=0;j<M;j++){
            printf("%lld ",dp[i][j]);
        }
        printf("\n");
    }*/
    fout << dp[N][M-1]<< endl;
    return 0;
}

