/*
ID: nitin.n1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool c[300]={false};
class Stall {
    public:
      int s,e,len,S;
};
bool mcomp(Stall a, Stall b){
 /*   if(a.s==0||a.e==(a.S-1)){
        return true;
    }
    if(b.s==0||b.e==(b.S-1)){
        return false;
    } */
    return a.len>b.len;
}
Stall nonCow[300];
int count1=0;
int nonCowsInit(int min,int max){
    int s=0,e=0;
    int S=7;
    bool in=true;
    for(int i=min;i<=max;i++){
        if(in==true&&c[i]==false){
            in=false;
            nonCow[count1].s=i;
            nonCow[count1].S=S;
        } else if(i>0&&in==false&&c[i]==true){
            in=true;
            nonCow[count1].e=i-1;
            nonCow[count1].len = nonCow[count1].e-nonCow[count1].s+1;
            count1++;
        }
    }
    if(in==false){
        nonCow[count1].e=S-1;
        nonCow[count1].len = nonCow[count1].e-nonCow[count1].s+1;
            count1++;
    }
     
}
int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int M, S, C;
    fin >> M >> S >> C;
    int min=S-1,max=0;
    for(int i=0;i<C;i++){
        int p;
        fin>>p;
        if((p-1)>max){
            max=p-1;
        } 
        if((p-1)<min){
            min = p-1;
        }
        c[p-1]=true;
    }
   // using min, max  as starting nd ending cow stalls as starting ending stalls never need to be covered
    nonCowsInit(min,max);
    vector<Stall> mvec(nonCow,nonCow+count1);
    sort(mvec.begin(),mvec.end(),mcomp);
    int unblocked=0;
    for(int i=0;i<mvec.size();i++){
        //cout<<mvec[i].s<<","<<mvec[i].e<<","<<mvec[i].len<<endl;
    }
    //cout<<"=============\n";
    int b=1;
    for(int i=0;i<mvec.size()&&b<M;i++){
        //cout<<mvec[i].s<<","<<mvec[i].e<<endl;
        unblocked+=mvec[i].len;  
          b++;
       /* if(mvec[i].s!=0&&mvec[i].e!=S-1){
            b++;
        } */
    }

    fout << (max-min-unblocked+1) << endl;
    return 0;
}

