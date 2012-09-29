#include<stdio.h>
#include<algorithm>
using namespace std;

int vals[100000];
int pos=0;
bool mycomp(int a,int b){
    return b<a;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%d",&a);
        if(a==2){
           int  idx = (pos/3 -1);
           if(idx>=0){
               sort(vals,vals+pos,mycomp);
               printf("%d\n",vals[idx]);
           } else {
               printf("No reviews yet\n");
           }
        } else {
           scanf("%d",&vals[pos++]);
        }
    }
}
