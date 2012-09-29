/*
ID: nitin.n1
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ofstream fout ("checker.out");
int pos[14];
bool placed[14]={false};
bool diag_up[28]={false}; // there are twice as many diagonals as many rows or cols
bool diag_down[28]={false};
long numSol=0;// number of solutions
int a; // checkboard size
int printed=0;
void printsol(){
    fout<<(pos[0]+1);
    for(int i=1;i<a;i++){
       fout<<" "<<(pos[i]+1);
    }
    fout<<"\n";
}
void solve(int col){
    if(col>=a){
        if(printed<3){
            printsol(); printed++;
        }
        numSol++;
        return;
    }
    for(int i=0;i<a;i++){
        if(!placed[i]&&!diag_up[col+i]&&!diag_down[a+col-i]){
                pos[col]=i;

                placed[i]=true; // place in ith row
                diag_up[col+i]=true; // occupy col+i th / diagonal
                diag_down[a+col-i] = true; //occupy col-i \ th diagonal 

                solve(col+1);

                // reset ( remove piece )
                diag_up[col+i]=false;
                diag_down[a+col-i]=false;
                placed[i]=false; // reset it
        }



    }
}

int main() {
    ifstream fin ("checker.in");
    fin >> a;
    solve(0);// start at col 0
    fout <<numSol<< endl;
    return 0;
}

