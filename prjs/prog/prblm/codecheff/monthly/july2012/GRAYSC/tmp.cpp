#include<stdio.h>
#define FOR(x,ini,m)  for(int x=ini;x<=m;x++)

int main(){
    int lim=7;
    FOR(a,0,lim){
        FOR(b,a,lim){
            FOR(c,b,lim){
                FOR(d,c,lim){
                    if(!(a^b^c^d)){
                        printf("(%d,%d,%d,%d)\n",a,b,c,d);
                    }
                }
            }
        }
    }
}
