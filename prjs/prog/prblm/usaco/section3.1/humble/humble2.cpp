/*
ID: nitin.n1
PROG: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#define MAX 200000
using namespace std;

int a, b;
int mprimes[200];
//bool isHumble[MAX]={false};
//int isHumble[MAX]={0};
map<int,int> isHumble;
int main() {
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");
    fin >> a >> b;
    for(int i=0;i<a;i++){
        fin>>mprimes[i];
        isHumble[mprimes[i]]=1;
  //      printf("dfdfas\n");
    }
    int cnt=0;
    int start = mprimes[0];
//    printf("staart = %d \n",start);
    for(int i=start;cnt<b;i++){
    //    if(i<20)
      //  printf("%d ",isHumble[i]);
        if(isHumble[i]==1){
            cnt++;
            if(cnt==b){
                fout<<i<<"\n";
                break;
            }
            for(int j=0;j<a;j++){
               long long num = ((long long)mprimes[j])*((long long)i);
               if(num<MAX){
                   isHumble[(int)num]=1;
               }
            }

        }

    }
    return 0;
}

