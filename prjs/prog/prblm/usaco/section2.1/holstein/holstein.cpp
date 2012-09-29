/*
ID: nitin.n1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int V,G;
int vc[25];
int feeds[15][25];
int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    int a, b;
    fin >>V;
    for(int i=0;i<V;i++){
        fin>>vc[i];
    }
    fin>>G;
    for(int i=0;i<G;i++){
        for(int j=0;j<V;j++){
            fin>>feeds[i][j];
        }
    }
    unsigned long long bitvec=0;
    unsigned long long largest =  1<<G;
    int start[25];
    int numbits;
    int minfeeds=45;
    int minbitvec=0;
    while(bitvec<largest){
        numbits=0;
        for(int i=0;i<V;i++){
            start[i]=0;
        }
        for(int i=0;i<G;i++){
            unsigned long long mask = 1<<i;
            if(mask&bitvec){
                numbits++;
                for(int j=0;j<V;j++){
                    start[j]+=feeds[i][j];
                }
            }
        }
        bool flag=true;
        for(int i=0;i<V;i++){
            if(start[i]<vc[i]){
                flag=false;
                break;
            }
        }
        if(flag){
            if(numbits<minfeeds){
                minbitvec = bitvec;
                minfeeds = numbits;
            }
        }
        bitvec++;
    }

    fout<<minfeeds;
        for(int i=0;i<G;i++){
        unsigned long long mask = 1<<i;
        if(mask&minbitvec){
            fout<<" "<<(i+1);
        }
    }
    fout<<"\n";
    return 0;
}

