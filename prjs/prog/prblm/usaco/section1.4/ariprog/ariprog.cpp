/*
ID: nitin.n1
PROG: ariprog
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
bool exists[125001]={false};
int ms2[30000];
int ms2c=0;
vector<int> ms;
map<pair<int,int>,int> dp;
class Ans{
    public:
        int x,d;
        Ans(int X,int D){
            x = X;
            d = D;
        }
};
vector<Ans*> anss;
bool mcomp(int a,int b){
    return a<b;
}
bool mcomp2(Ans* a, Ans* b){
    int ad = a->d;
    int bd = b->d;
    if(ad<bd){
        return true;
    } else if(ad==bd){
        return (a->x)<(b->x);
    }
    return false;
}
void solve(int N,int M){
    ofstream fout ("ariprog.out");
//cout<<"kjlkjlkj";
    for(int i=0;i<=M;i++){
        int i2 = i*i;
        for(int j=i;j<=M;j++){
            int j2 = j*j;
            exists[i2+j2]=true;
            ms.push_back(i2+j2);
        }
    }
    sort(ms.begin(),ms.end(),mcomp);
    int sz = ms.size();
    int lsq = -1;
    for(int i=0;i<sz ;i++){
        int nxt = ms[i];
        if(nxt!=lsq){
            ms2[ms2c++]= nxt;
            lsq = nxt;
        }
    }
    sz = ms2c;
    int st=0;
    for(int i=0;i<sz;i++){
        st = ms2[i];
            for(int j=i+1;j<sz;j++){
                bool present = true;
                int sum = ms2[j];
                int d = sum-st;
                int count =1;
                if(st+(N-1)*d>125001) break;
                while(count<N&&exists[sum]){ count++; sum+=d; }
                if(count>=N){
                    anss.push_back(new Ans(st,d));
                }
                  
            }
    }


    sort(anss.begin(),anss.end(),mcomp2);
    if(anss.size()<1){
        fout<<"NONE\n";

    }
    int lx=-1,ld=-1; // memory for removing duplicates
    for(int i=0;i<anss.size();i++){
        int x = anss[i]->x;
        int d = anss[i]->d;
        if(x!=lx||d!=ld){
            fout<<x<<" "<<d<<"\n";
            lx = x; ld = d;
        }
    }

}
int main() {
    ifstream fin ("ariprog.in");
    int N, M;
    fin >> N >> M;
//    printf("-1th\n");
    solve(N,M);
    return 0;
}

