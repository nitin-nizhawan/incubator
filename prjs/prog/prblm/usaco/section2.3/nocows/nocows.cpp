/*
ID: nitin.n1
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
long long dp[500][500];
long long MOD=9901;
void solvefor(int n){
    if(n==1){
        dp[0][0]=1;
    }
    int p1,p2;
    /*
     Logic is that left and right sub-trees of root node are also trees.
     therefore a tree with N node can be costructed by taking two trees with number of node p1 and p2 , such that l+m+ 1(root) = N. 
     The first loop finds pairs p1,p2
     for all such pairs
         f(N,K) = sum of all f(p1,k1)*f(p2,k2) such that max(k1,k2)+1 = K
         we find f(N,1), f(N,2) ... f(N,(N+1)/2)  where (N+1)/2 is maxposible heright of tree with N nodes.
         in matrix dp element dp[i][j] represent number of trees with height i+1, and number of nodes i*2+1;
         */
    for(int p1=1;p1<=(p2=(n-1-p1));p1+=2){
        int maxh_p1=(p1+1)/2;
        int maxh_p2=(p2+1)/2;
        for(int i=0;i<maxh_p1;i++){
            for(int j=0;j<maxh_p2;j++){
                int r_height = max(i,j)+1;
                long long val = (dp[i][(p1-1)/2]*dp[j][(p2-1)/2])%MOD;
                dp[r_height][(n-1)/2]=(dp[r_height][(n-1)/2]+val)%MOD;
                if(p1!=p2){ // add once more for p2,p1 pair
                    dp[r_height][(n-1)/2]=(dp[r_height][(n-1)/2]+val)%MOD;
                }
            }
        }
    }
}
int main() {
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    int a, b;
    fin >> a >> b;
    for(int i=1;i<=a;i+=2){
        solvefor(i);
    }
/*    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%lld ",dp[i][j]);
        }
        printf("\n");
    } */
    if(a%2==0){
        fout<<0<<"\n"; // no tree with even number of trees are possible
    } else {
        fout <<dp[b-1][(a-1)/2]<< endl;
    }
    return 0;
}

