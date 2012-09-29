/*
ID: nitin.n1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int getMax(int p, int a, char b[]){
  int i=0;
  char last=b[p];
  char type='w';
  int cur;
    //cout<<"\nFWD:"<<p<<"\n";
    for(i=0;i<a;i++){
        cur = (p+i)%a;
        //cout<<b[cur];
        if(b[cur]=='w'){
        } else if(b[cur]=='r'){
            if(type=='b'){
                break;
            } else {
                type='r';                
            }
        } else if(b[cur]=='b'){
            if(type=='r'){
               break;
            } else {
               type='b';
            }
        }
    }
    int f = i;
    int lcur=(cur-1+a)%a;
    if(i==a){
        return a;
    }
    type='w';
     //cout<<"\nBACK:"<<p<<"\n";
    for(i=0;i<a;i++){
         int cur = (p-i-1+a)%a;
         if(lcur==cur) break;
          //cout<<b[cur];
        if(b[cur]=='w'){
        } else if(b[cur]=='r'){
            if(type=='b'){
                break;
            } else {
                type='r';                
            }
        } else if(b[cur]=='b'){
            if(type=='r'){
               break;
            } else {
               type='b';
            }
        }
    }
    int r = i;
    return r+f;
}
int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int a ;
     char b[400];
    fin >> a >> b;
    int max=0,maxi;
    for(int i=0;i<a;i++){
        int tmp = getMax(i,a,b);
        if(tmp>max){
            max = tmp;
            maxi = i;
        }
    }
    fout <<max<<endl;
    return 0;
}

