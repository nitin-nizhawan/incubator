/*
ID: nitin.n1
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int getcode(char a){
    if('a'<=a&&a<='z'){
        return a-'a';
    } else {
        return (a-'A')+26;
    }
}
long long map[56][56]={1<<29};
int main() {
    ofstream fout ("comehome.out");
    ifstream fin ("comehome.in");
    int a;
    fin >>a;
    for(int i=0;i<52;i++){
        for(int j=0;j<52;j++){
            map[i][j]=(1<<29);
        }
    }
    for(int i=0;i<a;i++){
        char f,t;
        int v;
        fin>>f>>t>>v;
        int fi=getcode(f),ti=getcode(t);
       if( map[fi][ti]>v){
           map[fi][ti]=v;
       }
       if(map[ti][fi]>v){
           map[ti][fi]=v;
       }
    }
    for(int k=0;k<52;k++){
        for(int i=0;i<52;i++){
            for(int j=0;j<52;j++){
                if(map[i][k]+map[k][j]<map[i][j]){
                    map[i][j] = map[i][k]+map[k][j];
                }
            }
        }
    }
    int min_past=100;
    int min_path=1<<29;
    for(int i=26;i<51;i++){
        if(map[i][51]<min_path){
            min_past=i;min_path=map[i][51];
        }
        if(map[51][i]<min_path){
            min_past = i; min_path=map[51][i];
        }
    }
    fout <<(char)(min_past-26+'A')<<" "<<min_path<< endl;
    return 0;
}

