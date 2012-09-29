/*
ID: nitin.n1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
void upq(int,int);
class Node{
    public:
    int l,b,a;
};
queue<Node> rq;
bool mcomp(Node a,Node b){
    return a.b<b.b;
}
int l[4],b[4];
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}
int area1(int l[],int b[]){
    int l1 = max(max(l[0],l[1]),max(l[2],l[3]));
    int b1 = b[0]+b[1]+b[2]+b[3];
    upq(l1,b1);
    return l1*b1;
}
int area2(int l[],int b[]){
    int l1 = max(max(l[0],l[1]),l[2])+b[3];
    int b1 = max(b[0]+b[1]+b[2],l[3]);
    upq(l1,b1);
    return l1*b1;
}
int area3(int l[],int b[]){
    int l1 =max(max(l[0],l[1])+b[3],l[2]);
    int b1 = max(b[0]+b[1],l[3])+b[2];
    upq(l1,b1);
    return l1*b1;
}
int area4(int l[],int b[]){
    int l1 = max(max(l[0],l[1]+l[2]),l[3]);
    int b1 = b[0]+max(b[1],b[2])+b[3];
    upq(l1,b1);
    return l1*b1;
}
int area5(int l[],int b[]){
    int l1 = max(max(l[0]+l[1],l[2]),l[3]);
    int b1 = max(b[0],b[1])+b[2]+b[3];
    upq(l1,b1);
    return l1*b1;
}
int area6(int l[],int b[]){
    int l1 =max( l[0]+l[1], l[2]+b[3]);
    int b1 = max(b[0],b[1]) + max(b[2],l[3]);
    upq(l1,b1);
    return l1*b1;
}
void upq(int l1,int b1){
if(rq.empty()){
    Node tmp ;
    tmp.l=max(l1,b1); tmp.b=min(b1,l1); tmp.a = l1*b1;
    rq.push(tmp);
} else {
    Node b = rq.back();
    if(b.a>=(l1*b1)){
    Node tmp ;
    tmp.l=max(l1,b1); tmp.b=min(b1,l1); tmp.a = l1*b1;
        rq.push(tmp);
        if(rq.front().a>tmp.a){
        rq.pop();
        }
    }
}
}
bool fl[10000]={false};
bool fb[10000]={false};
int mina(int l[],int b[]){
   int (*areas[])(int l[],int b[])  = {&area1,&area2,&area3,&area4,&area5,&area6};
   unsigned min = 1<<30;
   for(int i=0;i<6;i++){
       int a = (*areas[i])(l,b);
       if(min>a){
           min = a;
       }
   }
   return min;
}
int solve(int l[],int b[]){
    int fmin = 1<<30;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                for(int h=0;h<4;h++){
                    if(i!=j&&j!=k&&k!=h&&h!=i&&j!=h&&k!=i){
                        int l1[] = {l[i],l[j],l[k],l[h]};
                        int b1[] = {b[i],b[j],b[k],b[h]};
                        int mint = mina(l1,b1);
                        if(mint<fmin){
                            fmin = mint;
                        }
                    }
                }
            }
        }
    }
    return fmin;
}
int main() {
    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");
    for(int i=0;i<4;i++){
        fin>>b[i]>>l[i];
    }
    int mins  = 1<<30;
    for(int i=0;i<16;i++){
       int l1[4],b1[4];
        for(int j=0;j<4;j++){
            int p = i;
            if(p&(1<<j)){
                l1[j]=l[j]; b1[j]=b[j];
            } else {
                l1[j] = b[j]; b1[j] = l[j];
            }
        }
        int mint = solve(l1,b1);
        if(mint<mins){
            mins = mint;
        }
    }
    fout << mins<< endl;
    vector<Node> mvec;
    while(!rq.empty()){
        mvec.push_back(rq.front());rq.pop();
    }
    sort(mvec.begin(),mvec.end(),mcomp);
for(int i=0;i<mvec.size();i++){
    Node a =mvec[i]; 
    if(a.a==mins&&(!fl[a.l]&&!fl[a.b]&&!fb[a.l]&&!fb[a.b])){
        fl[a.l]=true; fl[a.b]=true;fb[a.l]=true; fb[a.b]=true;
        fout<<min(a.b,a.l)<<" "<<max(a.b,a.l)<<endl;
    }
}
    return 0;
}

