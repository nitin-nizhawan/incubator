/*
ID: nitin.n1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Farmer {
public:
   int cost;
   int c;
};
bool mcomp(Farmer a, Farmer b){
    return a.cost<b.cost;
}
Farmer f[5000];
int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int a, b;
    fin >> a >> b;
    for(int i=0;i<b;i++){
        fin>>f[i].cost>>f[i].c;
    }
    vector<Farmer>  mvec(f,f+b);
    sort(mvec.begin(),mvec.end(),mcomp);
    int cost=0;
    for(int i=0;(i<b)&&a;i++){
//cout<<mvec[i].cost<<","<<mvec[i].c<<endl;        
        if(mvec[i].c<=a){
            cost+= (mvec[i].c*mvec[i].cost);
            a = a - mvec[i].c;
        } else {
            cost+=(mvec[i].cost*a);
            a=0;
        }
    }
    fout <<cost<< endl;
    return 0;
}

