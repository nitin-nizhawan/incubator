/*
ID: nitin.n1
PROG: concom
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int cs[200][200];
bool controls[200][200];
int main() {
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
    int n;
    fin >>n;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            controls[i][j]=false;
            cs[i][j]=0;
        }
    }
    for(int i=0;i<100;i++){
        controls[i][i]=true;
    }
    for(int i=0;i<n;i++){
        int a,b,v;
        fin>>a>>b>>v;
        cs[a-1][b-1]=v;
        if(v>50){
            controls[a-1][b-1]=true;
        }
    }
/*    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(cs[i][j]==100){
                cs[j][i]=100;
                controls[j][i]=true;
            }
        }
    }*/
    bool changed = true;
    int T=100;
    while(T--){
        changed=false;
        for(int i=0;i<100;i++){
            int tmp[200];
            for(int k=0;k<100;k++){
                tmp[k]=0;
            }
            for(int j=0;j<100;j++){
                if(controls[i][j]){
                    for(int k=0;k<100;k++){
                        tmp[k]+=cs[j][k];
                    }
                }
            }
            for(int k=0;k<100;k++){
                if(tmp[k]>50&&controls[i][k]==false){
                    changed = true;
                    controls[i][k]=true;
                }
            }
        }
    }

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(controls[i][j]&&i!=j){
                fout<<(i+1)<<" "<<(j+1)<<"\n";
            }
        }
    }
    return 0;
}

