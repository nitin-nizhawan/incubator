/*
ID: nitin.n1
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int N;
int dist[200][200];
bool vnew[200]={false};
int main() {
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");
    
    fin >>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            fin>>dist[i][j];
        }
    }

    int vnewsize=0;
    int ans=0;
    vnew[0]=true;
    int vnewlist[200];
    vnewlist[vnewsize++]=0;
    while(vnewsize<N){
        int mind=(1<<30);
        int mini=-1;
        for(int i=0;i<vnewsize&&vnewsize<N;i++){
            for(int j=0;j<N;j++){
                if(!vnew[j]){
                    if(dist[vnewlist[i]][j]<mind){
                        mind = dist[vnewlist[i]][j];
                        mini = j;
                    }
                }
            }
        }
        vnew[mini]=true;
        vnewlist[vnewsize++]=mini;
        ans+=mind;
    }
    fout<<ans<<"\n";
    return 0;
}

