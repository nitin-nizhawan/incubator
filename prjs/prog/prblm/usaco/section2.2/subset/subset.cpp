/*
ID: nitin.n1
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
long long dp[50][5000]={0};
int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    int a;
    fin >> a;
    dp[1][1]=1;
    for(int i=2;i<a+10;i++){
        int sum = (i*(i-1) )/2;
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
        }
        dp[i][i]++;
        for(int j=1;j<=sum;j++){
            dp[i][j+i]+=dp[i-1][j];
        }
    }
    int psum = (a*(a+1))/2;
    if(psum%2==0){
        fout<<(dp[a][psum/2]/2);
    } else {
        fout<<"0";
    }
    fout <<endl;
    return 0;
}

