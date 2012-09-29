/*
ID: nitin.n1
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
ifstream fin ("ratios.in");
ofstream fout ("ratios.out");
int s1,s2,s3,g1,g2,g3;
bool isValidSum(){
    if(g1==0&&s1!=0) return false;
    if(g2==0&&s2!=0) return false;
    if(g3==0&&s3!=0) return false;
    if(g1!=0&&s1%g1!=0) return false;
    if(g2!=0&&s2%g2!=0) return false;
    if(g3!=0&&s3%g3!=0) return false;
    
    return true;
}
int main() {
    fin>>g1>>g2>>g3;
    int m[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            fin>>m[i][j];
        }
    }
    long long minsum=1LL<<40;
    int mina,minb,minc,mink;
    for(int a=0;a<100;a++){
        for(int b=0;b<100;b++){
            for(int c=0;c<100;c++){
               if(a!=0||b!=0||c!=0){
                   s1  = m[0][0]*a + m[1][0]*b + m[2][0]*c;
                   s2 =  m[0][1]*a + m[1][1]*b + m[2][1]*c;
                   s3 =  m[0][2]*a + m[1][2]*b + m[2][2]*c;
                   if(isValidSum()){
                       int k1 = -1;
                       if(g1!=0){
                          k1 = s1/g1;
                       }
                       int k2 = -1;
                       if(g2!=0){
                        k2 = s2/g2;
                       }
                       int k3 = -1;
                       if(g3!=0){
                           k3 = s3/g3;
                       }
                       int kt;
                       if(k1!=-1) kt=k1;
                       if(k2!=-1) kt=k2;
                       if(k3!=-1) kt=k3;
                       if((k1==-1||k1==kt)&&(k2==-1||k2==kt)&&(k3==-1||k3==kt)){
                           if(minsum>(a+b+c)){
                               minsum = a+b+c;
                               mina=a;
                               minb=b;
                               minc=c;
                               mink=0;
                           if(g1!=0||g2!=0||g3!=0){
                               if(k1!=-1) mink = k1;
                               if(k2!=-1) mink=k2;
                               if(k3!=-1) mink=k3;
                           }
                       
                       //printf("ks = %d,%d,%d",k1,k2,k3);
                       //printf(" abc = %d,%d,%d",a,b,c);
                       //printf(" ss = %d,%d,%d\n",s1,s2,s3);
                           }
                      }
                   }
               }
            }
        }
    }
    if(minsum<(1LL<<40)){
    fout<<mina<<" "<<minb<<" "<<minc<<" "<<mink<<"\n";
    } else {
        fout<<"NONE\n";
    }
    return 0;
}

