/*
ID: nitin.n1
PROG: numtri
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int numtri[1001][1001];
int D;
int maxsum=-1;
void dfs(int i,int j,int sum){
    if(j<=i){
        if(i<D){
            sum = sum + numtri[i][j];
            if(i==(D-1)){
                if(maxsum<sum){
                    maxsum = sum;
                }
            }
            dfs(i+1,j,sum);
            dfs(i+1,j+1,sum);
        }
    }
}
int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    fin >> D;
    for(int i=0;i<D;i++){
        for(int j=0;j<=i;j++){
            fin>>numtri[i][j];
        }
    }
    //    dfs(0,0,0);
    for(int i=0;i<D;i++){
        for(int j=0;j<=i;j++){
            if(i!=0){
                if(j==0){
                    numtri[i][j] += numtri[i-1][j];
                } else if(j==i){
                    numtri[i][j] +=numtri[i-1][j-1];
                } else {
                    numtri[i][j] += max(numtri[i-1][j-1],numtri[i-1][j]);

                }
            }
            if(i==D-1){
                if(maxsum<numtri[i][j]){
                    maxsum = numtri[i][j];
                }
            }
        }
    }
    fout<<maxsum<<endl;
    return 0;
}

