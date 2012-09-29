/*
ID: nitin.n1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int perm[24][4] = {
                  {0,1,2,3}, {1,0,2,3}, {2,0,1,3}, {3,0,1,2},
                  {0,1,3,2}, {1,0,3,2}, {2,0,3,1}, {3,0,2,1},
                  {0,2,1,3}, {1,2,0,3}, {2,1,0,3}, {3,1,0,2},
                  {0,2,3,1}, {1,2,3,0}, {2,1,3,0}, {3,1,2,0},
                  {0,3,1,2}, {1,3,0,2}, {2,3,0,1}, {3,2,0,1},
                  {0,3,2,1}, {1,3,2,0}, {2,3,1,0}, {3,2,1,0} 
};
unsigned gmin=1<<30;
class Node {
    public:
    int l,b,a;
    Node(int b1,int l1,int a){
       this->a = a;
       this->l = (l1>b1?l1:b1);
       this->b = (l1<b1?l1:b1);
    }
};
vector<Node> mvec;
bool mcomp(Node a,Node b){
    if(a.a==b.a){
        return a.b<b.b;
    } else {
        return a.a<b.a;
    }
}
    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");

void solve(int b1[],int l1[]){
    unsigned minl,minb,min=1<<30,ltmp,btmp,mintmp;
    for(int i=0;i<24;i++){
        for(int j=0;j<16;j++){
            int l[4],b[4];
            for(int k=0;k<4;k++){
                if(j&(1<<k)){
                    l[k] = l1[perm[i][k]];
                    b[k] = b1[perm[i][k]];
                } else {
                    l[k] = b1[perm[i][k]];
                    b[k] = l1[perm[i][k]];
                }
            }
            for(int m=0;m<6;m++){
                
                ltmp = max(max(l[0],l[1]),max(l[2],l[3]));
                btmp = b[0]+b[1]+b[2]+b[3];
                Node tmp1(ltmp,btmp,ltmp*btmp);
                mvec.push_back(tmp1);

                ltmp = max(max(l[0],l[1]),l[2])+b[3];
                btmp = max(b[0]+b[1]+b[2],l[3]);
                Node tmp2(ltmp,btmp,ltmp*btmp);
                mvec.push_back(tmp2);

                ltmp =max(max(l[0],l[1])+b[3],l[2]);
                btmp = max(b[0]+b[1],l[3])+b[2];
                Node tmp3(ltmp,btmp,ltmp*btmp);
                mvec.push_back(tmp3);


                ltmp = max(max(l[0],l[1]+l[2]),l[3]);
                btmp = b[0]+max(b[1],b[2])+b[3];
                Node tmp4(ltmp,btmp,ltmp*btmp);
                mvec.push_back(tmp4);

                ltmp = max(max(l[0]+l[1],l[2]),l[3]);
                btmp = max(b[0],b[1])+b[2]+b[3];
                Node tmp5(ltmp,btmp,ltmp*btmp);
                mvec.push_back(tmp5);

                ltmp =max( l[0]+l[1], l[2]+l[3]);
                btmp =max( b[1]+b[2], b[0]+b[3]);


                int btmp=b[0]+b[3];

                if (l[0]<l[3])
                    btmp=max(b[0]+b[3],b[1]+b[3]);
                if (l[0]+l[1]>l[3])
                    btmp=max(btmp,b[1]+b[2]);
                if (l[0]>l[3])
                    btmp=max(btmp,b[0]+b[2]);
                btmp=max(max(btmp,b[1]),b[2]);

                int ltmp = max(l[0]+l[1],l[2]+l[3]);
                Node tmp6(ltmp,btmp,ltmp*btmp);
                mvec.push_back(tmp6);


            }
        }
    }
    sort(mvec.begin(),mvec.end(),mcomp);
    mintmp=mvec[0].a;
    ltmp=1<<30; btmp=1<<30;
    fout<<mvec[0].a<<endl;
    for(int i=0;i<mvec.size();i++){
//        cout<<mvec[i].a<<" , "<<mvec[i].b<<" , "<<mvec[i].l<<endl;
    }
    for(int i=0;i<mvec.size()&&mvec[i].a==mintmp;i++){
       
        if(ltmp!=mvec[i].l&&btmp!=mvec[i].b){
            fout<<mvec[i].b<<" "<<mvec[i].l<<endl;
             ltmp = mvec[i].l; btmp = mvec[i].b;
        }
    }

}
int main() {
    int l[4], b[4];
    for(int i=0;i<4;i++){
        fin>>b[i]>>l[i];
    }
    solve(l,b);
    return 0;
}

