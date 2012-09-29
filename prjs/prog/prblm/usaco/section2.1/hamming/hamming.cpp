/*
ID: nitin.n1
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int ans[1000];
int count1=0;
int hash[1000]={0};
int tmp[1000];
char ansstr[20];
char* pbit(int a,int b){
    int len=0;
    while(len<b){
        if(a&(1<<len)){
            ansstr[len]='1';
        } else {
            ansstr[len]='0';
        }
        len++;
    }
    ansstr[len]='\0';
    for(int i=0;i<(len/2);i++){
        char tmp = ansstr[i];
        ansstr[i]=ansstr[len-i-1];
        ansstr[len-i-1] = tmp;
    }
    return ansstr;
}
int dist(int a, int b,int B){
    int xori = a^b;
//    printf("%s %s %s\n",pbit(a,B),pbit(b,B),pbit(xori,B));
    int ans=0;
    for(int i=0;i<B;i++){
        if(xori&(1<<i)){
            ans++;
        }
    }
  //  printf("returned ans %d\n",ans);
    return ans;
}
int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    int N,B,D;
    fin >>N >>B>>D;
    int maxb = 1<<B;
    for(int i=0;i<maxb;i++){
        bool flag = true;
        for(int j=0;j<count1;j++){
            if(dist(ans[j],i,B)<D){
                flag = false;
                break;
            }
        }
        if(flag){
            ans[count1++]=i;
        }
    }
    for(int i=0;i<N;i++){
        if(i>0&&i%10==0) fout<<"\n";
        fout<<ans[i];
        if((i+1)%10>0&&(i+1)<N){
            fout<<" ";
        }
    }
    fout<<"\n";
    return 0;
}

