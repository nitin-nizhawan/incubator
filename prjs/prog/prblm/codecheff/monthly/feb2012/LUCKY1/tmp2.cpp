#include<stdio.h>

int diffi[200000]={0};
int diffi_cum[200000]={0};
int diffns[200000]={0};
int diffns_cnt=0;




int n_d_s(int a,int t){
    int ans=0;
    while(a>0){
        int d = a%10;
        if(d==t){
            ans++;
        }
        a/=10;
    }
    return ans;
}
int main(){
   for(int i=0;i<100001;i++){
        int diff = n_d_s(i,4) - n_d_s(i,7);
        diffi[i]=diff;
        if(i>0){
            diffi_cum[i] = diff + diffi_cum[i-1];
        } 
        if(diff!=0){
            diffns[diffns_cnt++]=i;
        }
   }
   printf("%d\n",diffns_cnt);
   for(int i=0;i<diffns_cnt;i++){
       printf("%d\n",diffns[i]);
   }
}
