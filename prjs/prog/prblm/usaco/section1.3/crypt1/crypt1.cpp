/*
ID: nitin.n1
PROG: damu
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int d[10];
bool b[12]={false};
bool checkit(int u, int v, int w, int x, int y){
//cout<<"ch: "<<d[u]<<","<<d[v]<<","<<d[w]<<"*"<< y<<","<<x<<endl;
  int prod1[] = {d[w],d[v],d[u],0,0};
  int prod2[] = {d[w],d[v],d[u],0};
  int c=0;
  for(int i=0;i<3;i++){
      int prod = d[x]*prod1[i]+c;
      c = prod/10;
      prod1[i] = prod%10;
      if(!b[prod1[i]]) return false;
  }
  if(c>0) return false;
  c=0;
  for(int i=0;i<3;i++){
      int prod = d[y]*prod2[i]+c;
      c = prod/10;
      prod2[i] = prod%10;
      if(!b[prod2[i]]) return false;
  }
  if(c>0) return false;
  c=0;
  
  for(int i=0;i<3;i++){
      int sum = prod1[i+1]+prod2[i]+c;
      c = sum/10;    
      prod1[i+1] = sum%10;
      if(!b[prod1[i+1]]) return false;
  }
  if(c>0) return false;
  return true;
}
int main() {
    ofstream fout ("damu.out");
    ifstream fin ("damu.in");
    int n;
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>d[i];
        b[d[i]]=true;
    }
    int count=0;
    for(int u=0;u<n;u++){
        for(int v=0;v<n;v++){
            for(int w=0;w<n;w++){
                for(int x=0;x<n;x++){
                    for(int y=0;y<n;y++){
                        bool passed=true;
                        if(!checkit(u,v,w,x,y)){
                            passed=false;
                        }
                        if(passed){
                            count++;
                        }         
                    }
                }
            }
        }
    }
    fout<<count<<endl;
    return 0;
}

