/*
ID: nitin.n1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ofstream fout ("dualpal.out");
bool isdualpal(int n){
   int num=0;
   int  base = 2;  
   char rev[40];  
   while(num<2&&base<11){
       int nt = n;
       int i=0;
       while(nt){
           rev[i++] = nt%base;
           nt/=base;
       }
       num++;
       for(int j=0;j<i/2;j++){
           if(rev[j]!=rev[i-j-1]){
               num--; break;
           }
       }
       base++;
   }
   return (num>=2);
}
int dualpal(int n){
     while(!isdualpal(++n));
     return n;
}
void dualpal(int a, int b){
    while(a--){
      b=dualpal(b);
      fout<<b<<endl;
    }
}
int main() {
    ifstream fin ("dualpal.in");
    int a, b;
    fin >> a >> b;
    dualpal(a,b);
    return 0;
}

