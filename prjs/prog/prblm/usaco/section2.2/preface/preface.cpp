/*
ID: nitin.n1
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int I[40000];
int V[40000];
int X[40000];
int L[40000];
int C[40000];
int D[40000];
int M[40000];
ofstream fout ("preface.out");
void printi(const char* str,int v){
    if(v>0){
        fout<<str<<" "<<v<<"\n";
    }
}
int main() {
    ifstream fin ("preface.in");
    int a, b;
    fin >> a;
    for(int j=1;j<=a;j++){
        int i = j;
        M[j]=M[j-1];
        D[j]=D[j-1];
        C[j]=C[j-1];
        L[j]=L[j-1];
        X[j]=X[j-1];
        V[j]=V[j-1];
        I[j]=I[j-1];
       if((i/1000)>0){
           int d = i/1000;
          M[j]+= d; // d times M, (M, MM,MMM)
       }
       i = i%1000;
       if((i/500)>0){
           int d = i/100;
           if(d==9) {
               C[j] += 1;
               M[j] += 1;
           } else {
               D[j] +=  1;
               C[j] +=  (d-5);
           }
       } else if((i/100)>0){
           int d = i/100;
           if(d == 4){
               C[j] += 1;
               D[j] += 1;
           } else {
               C[j] += d;
           }
       }
       i = i%100;
       if((i/50)>0){
           int d = i/10;
           if(d == 9){
               C[j] += 1;
               X[j] += 1;
           } else {
               L[j] += 1;
               X[j] += (d - 5);
           }
       } else if((i/10)>0){
           int d = i/10;
           if(d==4){
               L[j] += 1;
               X[j] += 1;
           } else {
               X[j] += d;
           }
       }
       i = i%10;
       if((i/5) > 0){
           int d = i/1;
           if(d ==9){
               X[j] += 1;
               I[j] += 1;
           } else {
               V[j] += 1 ;
               I[j] += (d-5);
           }
       } else if((i/1)>0){
           int d = i/1;
           if(d == 4){
               V[j] += 1;
               I[j] += 1;
           } else {
               I[j] += d;
           }
       }
    }
    printi("I",I[a]);
    printi("V",V[a]);
    printi("X",X[a]);
    printi("L",L[a]);
    printi("C",C[a]);
    printi("D",D[a]);
    printi("M",M[a]);
    return 0;
}

