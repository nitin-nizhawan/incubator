#include<iostream>

using namespace std;
typedef unsigned long long ull;
unsigned long long vals[150000];
unsigned int gencount=0;
unsigned int a,b;
bool isPresent(ull val){
    for(unsigned int i=0;i<gencount;i++){
        if(vals[i]==val){
            return true;
        }
    }
    return false;
}
ull gennew(ull inp,unsigned int pi,int pj){
    ull initval=inp;
    for(unsigned int i=0;i<a;i++){
        initval^=(1<<(i*b+pj));
    }
    for(unsigned int j=0;j<b;j++){
        initval^=(1<<(pi*b+j));
    }
    initval^=(1<<(pi*b+pj));
    return initval;
}
unsigned int generate(){
    unsigned int c=0;
    for(unsigned int k=0;k<gencount;k++){
        ull cur = vals[k];
        for(unsigned int i=0;i<a;i++){
            for(unsigned int j=0;j<b;j++){
                ull mnew = gennew(cur,i,j);
                if(!isPresent(mnew)){
                    vals[gencount++]=mnew;
                    c++;
                }
            }
        }
    }
    return c;
}
int main(){

    cin>>a>>b;
    int s = (a>>1)<<2;
    int v;
    if(a%2==0){
        v = s*(b>>1) + b%2 + a%2;
    } else {
        v = s*(b>>1) + a%2;;
    }
//    int v = (b/2)*s + (b%2);
//    cout<<"s:"<<s<<", v:"<<v<<"\n";
    cout<<"Sol:"<<(1<<v)<<"\n";
    // set init
    ull initval=0;
    for(unsigned int i=0;i<a;i++){
        for(unsigned int j=0;j<b;j++){
              initval|=(1<<(i*b+j));
        }
    }
    vals[gencount++]=initval;
    while(generate());
    cout<<gencount<<"\n";
}
