/*
ID: nitin.n1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int N,C;
int onlamps[200];
int onlamps_n=0;
int offlamps[200];
int offlamps_n=0;
bool lamps[16][200]={true};
class Lamp{
    public:
        unsigned long long h,l;
        Lamp(){
            h=0;l=0;
        }
};
vector<Lamp> lamps_map;
bool matches(int cfg){
    for(int i=0;i<onlamps_n;i++){
        if(lamps[cfg][onlamps[i]]==false){
            return false;
        }
    }
    for(int i=0;i<offlamps_n;i++){
        if(lamps[cfg][offlamps[i]]==true){
            return false;
        }
    }
    return true;
}
int s_b(int n){
    int  ans=0;
    for(int i=0;i<4;i++){
        if(n&(1<<i)){
            ans++;
        }
    }
    return ans;
}
bool mycomp(Lamp a, Lamp b){
    if(a.h==b.h){
        return a.l<b.l;
    }
    return a.h<b.h;
}
int main() {
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
    lamps_map.resize(16);
    fin >>N>>C;
    int tmp=0;
    fin>>tmp;
    while(tmp>=0){
        onlamps[onlamps_n++]=tmp;
        fin>>tmp;
    }
    fin>>tmp;
    while(tmp>=0){
        offlamps[offlamps_n++] = tmp;
        fin>>tmp;
    }
    // initialize config
    for(int i=0;i<16;i++){
        for(int k=0;k<162;k++){
            lamps[i][k]=true;
        }
        int cfg = i;
        if(cfg&1){
            for(int j=0;j<40;j++){
                lamps[i][3*j+1]=!lamps[i][3*j+1];
            }
        }
        if(cfg&2){ // even numbered
            for(int j=2;j<=102;j+=2){
                lamps[i][j] =!lamps[i][j];
            }
        }
        if(cfg&4){ // odd numberd
            for(int j=1;j<102;j+=2){
                lamps[i][j] =!lamps[i][j];
            }
        }
        if(cfg&8){ // all
            for(int j=1;j<102;j++){
                lamps[i][j] = !lamps[i][j];
            }
        }
    }
    // find matching cfgs;
    int matching_cfg[16], matching_n=0;
    for(int i=0;i<16;i++){
        if(matches(i)){
            matching_cfg[matching_n++]=i;
        }
    }
    int can_b_reached[16],can_b_reached_n=0;
//    int *can_b_reached = matching_cfg,can_b_reached_n = matching_n;
    // if can be reached
    for(int i=0;i<matching_n;i++){
        int n = matching_cfg[i];
        int set_bits = s_b(n);
        if((C-set_bits)>=0&&(C-set_bits)%2==0){
            can_b_reached[can_b_reached_n++]=n;
        }

    }
    unsigned long long oneN=1;
    for(int i=0;i<can_b_reached_n;i++){
        lamps_map[i].h=0;lamps_map[i].l=0;
        for(int j=1;j<=N;j++){
            if(lamps[can_b_reached[i]][j]){
                int k=N-j+1;
                if(k>64){
                    unsigned long long mask = (oneN<<(k-64));
                    lamps_map[i].h|=mask;
                } else {
                    unsigned long long mask = (oneN<<(k-1));
                    lamps_map[i].l|=mask;
                }
            }
        }
    }
    sort(lamps_map.begin(),lamps_map.begin()+can_b_reached_n,mycomp);
    for(int i=0;i<can_b_reached_n;i++){
      //  fout<<can_b_reached[i]<<" ";
        for(int j=1;j<=N;j++){
//            fout<<(lamps[can_b_reached[i]][j]?1:0);
            int k= N-j+1;
            if(k>64){
               unsigned long long mask = (oneN<<(k-64));
                fout<<((lamps_map[i].h&mask)?1:0);
            } else {
               unsigned long long mask = (oneN<<(k-1));
                fout<<((lamps_map[i].l&mask)?1:0);
            }
        }
        fout<<"\n";
    }
    if(can_b_reached_n<=0){
        fout<<"IMPOSSIBLE\n";
    }
    return 0;
}

