/*
ID: nitin.n1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Schd{
public:
  long start;
  long end;
};
bool myfunction (Schd a,Schd b) { return (a.start<b.start); }
int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n;
    fin >> n;
    Schd  scd[5000];
    
    for(int i=0;i<n;i++){
        fin>>scd[i].start>>scd[i].end;
    }
    vector<Schd> mvec(scd,scd+n);
    sort(mvec.begin(),mvec.end(),myfunction);
    int s=mvec[0].start,e = mvec[0].end;
    int maxi=e-s,maxo=0;
    for(int i=1;i<n;i++){
        if(mvec[i].start<=e){ 
            if(mvec[i].end>e){
                 e = mvec[i].end;
            }
        } else {
           if((e-s)>=maxi){
              maxi = (e-s);
           }
           if((mvec[i].start-e)>=maxo){
              maxo = (mvec[i].start-e);
           } 
           s = mvec[i].start;
           e = mvec[i].end;
        }
    }
    fout <<maxi<<" "<<maxo<< endl;
    return 0;
}

