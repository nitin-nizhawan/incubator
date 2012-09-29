/*
ID: nitin.n1
PROG: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include<vector>
#include <map>
#define MAX 200000
using namespace std;
unsigned int max_int = 0x00FFFFFF;
int a, b;
unsigned pows[110][40];
unsigned mprimes[110];
unsigned len[110]={0};
//unsigned humbles[700000];
vector<unsigned> humbles;
int hcnt=0;
int main() {
    humbles.resize(2000000);
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");
    fin >> a >> b;
    for(int i=0;i<a;i++){
        fin>>mprimes[i];
        pows[i][0]=1; len[i]=1;
        for(int j=1;pows[i][j-1]<(max_int/mprimes[i]);j++){
            pows[i][j] = pows[i][j-1]*mprimes[i];
            len[i]++;
        }
    }
    for(int i=0;i<len[0];i++){
        humbles[hcnt++]=pows[0][i];
    }
    int start=0;
    for(int i=1;i<a;i++){
        int hcnt_cpy = hcnt;
        for(int j=1;j<len[i];j++){
            for(int k=0;k<hcnt;k++){
                if((max_int/pows[i][j])>humbles[k]){
                    humbles[hcnt_cpy++]=humbles[k]*pows[i][j];
                }
            }
        }
        hcnt = hcnt_cpy;
        printf("%d ",hcnt);
    }

    sort(humbles.begin(),humbles.begin()+hcnt);
    fout<<humbles[b]<<"\n";
    return 0;
}

