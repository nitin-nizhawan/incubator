/*
ID: nitin.n1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<algorithm>
bool visited[21][21][21] = {false};

using namespace std;
vector<int> anss;
    int A, B, C;
void dfs(int a, int b, int c){
    if(!visited[a][b][c]){
        visited[a][b][c]=true;
        if(a==0){
            anss.push_back(c);
        }
        // try pouring c to a and b
        if(c>0){
          // to a 
             if( a < A){
                 if((A-a)>=c){
                     dfs(a+c,b,0);
                 } else {
                     dfs(A,b,c-(A-a));
                 }
             }
          // to b
             if(b<B){
                 if((B-b)>=c){
                     dfs(a,b+c,0);
                 } else {
                     dfs(a,B,c-(B-b));
                 }
             }
        }

        // try pouring a to b and c
     if(a>0){
          // to b 
             if( b < B){
                 if((B-b)>=a){
                     dfs(0,b+a,c);
                 } else {
                     dfs(a-(B-b),B,c);
                 }
             }
          // to c
             if(c<C){
                 if((C-c)>=a){
                     dfs(0,b,c+a);
                 } else {
                     dfs(a-(C-c),b,C);
                 }
             }
        }


        // try pouring b to a and c
     if(b>0){
          // to a 
             if( a < A){
                 if((A-a)>=b){
                     dfs(a+b,0,c);
                 } else {
                     dfs(A,b-(A-a),c);
                 }
             }
          // to c
             if(c<C){
                 if((C-c)>=b){
                     dfs(a,0,c+b);
                 } else {
                     dfs(a,b-(C-c),C);
                 }
             }
        }

    }
}
bool mcomp(int a, int b){
    return a<b;
}
int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    fin >> A >> B>>C;
    dfs(0,0,C);
    sort(anss.begin(),anss.end(),mcomp);
    int ld =anss[0];
    fout<<ld;
    for(int i=1;i<anss.size();i++){
        int n= anss[i];
        if(n!=ld){
             fout<<" "<<n;
             ld = n;
        }
    }
    fout<<"\n";
    return 0;
}

