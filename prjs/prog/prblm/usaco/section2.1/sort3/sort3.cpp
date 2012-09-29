/*
ID: nitin.n1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int nums[2000];
int n;
int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    fin>>n;
    int cnt2[3][3]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cnt2[i][j]=0;
        }
    }
    int cnt[]={0,0,0};
    for(int i=0;i<n;i++){
        fin>>nums[i];
        cnt[nums[i]-1]++; // count total number of 1,2,3s. this is used to find boundary
    }
    int diff=0;
    for(int i=0;i<n;i++){
        if(i>=0&&i<cnt[0]){
           cnt2[0][nums[i]-1]++; // number of 1s,2s,3s in 1s boundary
        } else if(i>=cnt[0]&&i<cnt[0]+cnt[1]){
            cnt2[1][nums[i]-1]++;
        } else {
            cnt2[2][nums[i]-1]++;
        }
    }
    int ans=0;
    // swap numbers independently as many as possible
    int tmp = min(cnt2[0][1],cnt2[1][0]);
    ans+=tmp; cnt2[0][1]-=tmp; cnt2[1][0]-=tmp;
    cnt2[0][0]+=tmp; cnt2[1][1]+=tmp;
    
    tmp  = min(cnt2[0][2],cnt2[2][0]);   
    ans+=tmp; cnt2[0][2]-=tmp; cnt2[2][0]-=tmp;
    cnt2[0][0]+=tmp; cnt2[2][2]+=tmp;


    tmp  = min(cnt2[1][2],cnt2[2][1]);   
    ans+=tmp; cnt2[1][2]-=tmp; cnt2[2][1]-=tmp;
    cnt2[1][1]+=tmp; cnt2[2][2]+=tmp;

//remaining shuffled number
    tmp =  cnt2[0][1]+cnt2[0][2] + cnt2[1][0] + cnt2[1][2] + cnt2[2][0] + cnt2[2][1];
    ans+= (2*tmp)/3;
    fout<<ans<<"\n";
    return 0;
}

