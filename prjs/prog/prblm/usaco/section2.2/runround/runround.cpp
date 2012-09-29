/*
ID: nitin.n1
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
ull getans(ull n){
    int digits[34];
    int size=0;
    ull cpy_n=n;
    while(cpy_n>0){
        digits[size++] = cpy_n%10;
        cpy_n/=10;
    }

}
bool nums[10]={false};
bool posi[10]={false};
int number[10];
int list[5000];
int list_n=0;
void gennums(int size,int current,int rem){
    for(int i=1;i<=9;i++){
        int mod = (i+current)%size;
        if(!nums[i]&&mod!=current){ // if digit has not been used
            if(rem==1&&mod==0){
                number[current]=i;
                int n=0;
                for(int j=0;j<size;j++){
                    n = n*10+number[j];
                }
                list[list_n++] = n;
//                printf("%d %d %d %d\n",n,size,current,rem);
            } else if(rem>1&&!posi[mod]) {
              posi[current]=true;
              nums[i]=true;
              number[current]=i;
              gennums(size,mod,rem-1);
              nums[i]=false;
              posi[current]=false;
            } 
        }
    }
}
int d_s(int n){
    int cnt=0;
    while(n>0){
        cnt++;
        n/=10;
    }
    return cnt;
}
int solve(int a){
   int n = d_s(a);
   gennums(n,0,n);
   sort(list,list+list_n);
   if(a>=list[list_n-1]){
       list_n=0;
       gennums(n+1,0,n+1);
       sort(list,list+list_n);
       return list[0];
   } else {
       // linear search
       if(a<list[0]){
           return list[0];
       }
       for(int i=0;i<(list_n-1);i++){
           if(list[i]<=a&&list[i+1]>a){
              return list[i+1];
           }
       }
   }
}
int main() {
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    int a;
    fin >> a ;
    fout<<solve(a)<<"\n";
/*    for(int i=0;i<list_n;i++){
        printf("%d\n",list[i]);
    }*/
    return 0;
}

