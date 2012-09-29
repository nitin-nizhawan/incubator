#include<iostream>
#include<vector>
#include<stack>
#define VVI vector<vector <int> >
#define VI vector<int>
#define STACK stack<int>
using namespace std;

void emptyStacks(VVI &inp,STACK &sti,STACK &stj,int &val){
    while(!sti.empty()){
        int i = sti.top(); sti.pop();
        int j = stj.top(); stj.pop();
        if(inp[i][j]<val){
            inp[i][j] = val;
        }
    }
    val = 0;
}
void update(VVI & inp,STACK &sti,STACK &stj,int i, int j,int &val){
    if(inp[i][j]>0){
        val++;
        sti.push(i);
        stj.push(j);
    } else {
        emptyStacks(inp,sti,stj,val);
    }
}
/*void hs(VVI &inp){
    int valh = 0;
    int valv = 0;
    int n=inp.size();
    STACK stih,stjh;
    STACK stiv,stjv;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            update(inp,stih,stjh,i,j,valh);
            update(inp,stiv,stjv,j,i,valv);
        }
        emptyStacks(inp,stih,stjh,valh);
        emptyStacks(inp,stiv,stjv,valv);
    }
}*/
void hs(VVI &inp){
    int n = inp.size();
    STACK stc_h; 
    STACK stc_v; 
    int val_h =0;
    int val_v=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(inp[i][j]>0){
                val_h++;
                stc_h.push(j);
            } else {
                while(!stc_h.empty()){
                    int j_h = stc_h.top(); stc_h.pop();
                    if(inp[i][j_h]<val_h){
                        inp[i][j_h]=val_h;       
                    }
                }
                val_h=0;
            }   
            if(inp[j][i]>0){
                val_v++;
                stc_v.push(j);
            } else {
              while(!stc_v.empty()){
                  int j_v = stc_v.top(); stc_v.pop();
                  if(inp[j_v][i]<val_v){
                      inp[j_v][i] = val_v;
                  }
              }
              val_v=0;
            }  
        }
        while(!stc_h.empty()){
            int j_h = stc_h.top(); stc_h.pop();
            if(inp[i][j_h]<val_h){
                inp[i][j_h]=val_h;
            }
        }
        val_h=0;
        while(!stc_v.empty()){
           int j_v = stc_v.top(); stc_v.pop();
           if(inp[j_v][i]<val_v){
                inp[j_v][i] = val_v;
           }
        }
        val_v=0;
    }
}
void d1s1(VVI &inp){
    int vald1s1 = 0;
    int vald1s2 = 0;
    int vald2s1 = 0;
    int vald2s2 = 0;
    int n=inp.size();
    int n1 = n-1;
    int ij ;
    STACK stid1s1,stjd1s1;
    STACK stid1s2,stjd1s2;
    STACK stid2s1,stjd2s1;
    STACK stid2s2,stjd2s2;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            ij = i-j;
            update(inp,stid1s1,stjd1s1,ij,j,vald1s1);
            if(i<(n1)){
               update(inp,stid1s2,stjd1s2,n1-j,n1-ij,vald1s2);
            }
            update(inp,stid2s1,stjd2s1,j,n1-ij,vald2s1);
            if(i<(n1)){
               update(inp,stid2s2,stjd2s2,n1-ij,j,vald2s2);
            }
        }
        emptyStacks(inp,stid1s1,stjd1s1,vald1s1);
        emptyStacks(inp,stid1s2,stjd1s2,vald1s2);
        emptyStacks(inp,stid2s1,stjd2s1,vald2s1);
        emptyStacks(inp,stid2s2,stjd2s2,vald2s2);
    }
}
/*void d1s2(VVI &inp){
    int val = 0;
    int n=inp.size();
    STACK sti,stj;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
        }
        emptyStacks(inp,sti,stj,val);
    }
}
void d2s1(VVI &inp){
    int val = 0;
    int n=inp.size();
    STACK sti,stj;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
        }
        emptyStacks(inp,sti,stj,val);
    }
}
void d2s2(VVI &inp){
    int val = 0;
    int n=inp.size();
    STACK sti,stj;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
        }
        emptyStacks(inp,sti,stj,val);
    }
}*/
int main(){
    int n;
    char c;
    cin>>n;
    VVI inp;
    inp.resize(n);
    for(int i=0;i<n;i++){
        inp[i].resize(n);
        for(int j=0;j<n;j++){
            cin>>c;
            if(c=='.'){
                inp[i][j]=0;
            } else {
                inp[i][j]=1;
            }
        }
    }
    // horizontal scan;
    hs(inp);
    d1s1(inp); //s2(inp); d2s1(inp);d2s2(inp);
    for(int l=0;l<n;l++){
        for(int m=0;m<n;m++){
            cout<<inp[l][m];
            if(m<n-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }

}
