/*
ID: nitin.n1
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int cn[40][40];
int fdp[40][40];
ofstream fout ("kimbits.out");

int f(int n,int b){
    int ans=0;
    for(int i=0;i<=b;i++){
        ans+=cn[n][i];
    }
    //printf("f(%d,%d)= %d \n",n,b,ans);
    return ans;
}
int f2(int n,int b){
    return fdp[n][b];
}
void printBits(int n,int b,int i){
    if(n<1){
        return;
    }
    if(i<2){
        fout<<"0";
        printBits(n-1,b,i);
        return;
    }
    if(b==0){
        fout<<"0";
        printBits(n-1,b,i);
        return;
    }
    if(f(n,b)>=i&&f(n-1,b)<=i){
        fout<<"1";
        printBits(n-1,b-1,i-f(n-1,b));
    } else if(f(n,b)>i&&f(n-1,b)>i){
        fout<<"0";
        printBits(n-1,b,i);
    }/* else if(n==b){
        fout<<"1";
        printBits(n-1,b-1,i);
    } */
}
int main() {
    ifstream fin ("kimbits.in");
    int N,L,I;
    fin >>N >>L>>I;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=i;j++){
            if(i==0&&j==0){
                cn[i][j]=1;
            } else if(j==0){
                cn[i][j]=1;
            } else {
                cn[i][j] = cn[i-1][j] + cn[i-1][j-1];
            }
        }
    }
    
  /*  for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            printf("%d ",cn[i][j]);
        }
        printf("\n");
    }
    printf("\n"); */
    printBits(N,L,I);
    fout<<"\n";
  //  fout << a+b << endl;
    return 0;
}

