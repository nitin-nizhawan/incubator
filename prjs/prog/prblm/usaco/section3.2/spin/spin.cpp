/*
ID: nitin.n1
PROG: spin
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
ifstream fin ("spin.in");
ofstream fout ("spin.out");
int whl[5][12];
map<long long,int> mymap;
long long pos[5];
long long pack(){
    long long ret=0;
    for(int i=0;i<5;i++){
        ret|=(pos[i]<<(9*i));
    }
    return ret;
}
void inpWhl(int i){
    fin>>whl[i][0];
    fin>>whl[i][1];
    for(int j=0;j<whl[i][1];j++){
        fin>>whl[i][2+j*2];
        fin>>whl[i][3+j*2];
    }
}

bool lies(int n,int st,int ed){
    if(st<ed){
        if(n>=st&&n<=ed){
            return true;
        }
    } else {
        if((n>=st&&n<=359)||(n>=0&&n<=ed)){
            return true;
        }
    }
    return false;
}
bool isThrough(int n,int k){
    int *whlc = whl[k];
    int posc=pos[k];
    for(int j=0;j<whlc[1];j++){
        int st = (whlc[2+j*2]+posc)%360;
        int ed = (st + whlc[3+j*2])%360;
        if(lies(n,st,ed)){
            return true;
        }
    }
    return false;
}
bool isThrough(int n){
     return isThrough(n,0)&&isThrough(n,1)&&isThrough(n,2)&&isThrough(n,3)&&isThrough(n,4);
}
bool isThrough(){
    for(int i=0;i<360;i++){
        if(isThrough(i)){
          //  printf("%d\n",i);
            return true;
        }
    }
    return false;
}
int main() {
    for(int i=0;i<5;i++){
        inpWhl(i);
    }
    int sec=0;
    while(true){
        long long packed = pack();
        if(mymap[packed]==1){
            fout<<"none\n";
            break;
        }
        if(isThrough()){
            fout<<sec<<"\n";
            break;
        }
        for(int i=0;i<5;i++){
            pos[i] = (pos[i]+whl[i][0])%360;
        }
        mymap[packed]=1;
        sec++;
    }
    return 0;
}

