#include<stdio.h>
typedef int myint;


myint neg[200000]={0};
int neg_cnt=0;
myint zeros=0;
myint ans[200000]={0};
myint posi[200000]={0};
int posi_cnt=0;
int n_d_s(myint a, int z){
    int ans=0;
    while(a>0){
        int d = a%10;
        if(d==z){
            ans++;
        }
        a/=10;
    }
    return ans;
}

int storage[200000]={0};
int zero_idx = 100000;
int main(){
    int ans=0;
    for(int i=1;i<100001;i++){
       int diff = n_d_s(i,4) - n_d_s(i,7);
       zero_idx=zero_idx-diff;
       storage[zero_idx+diff]++;
       ans+=storage[zero_idx];
       printf("%d %d\n",i,ans);
    }
}
int main1(){
    int last_non_zero=0;
    int ans=0;
    for(int i=1;i<100001;i++){
           int diff = n_d_s(i,4) - n_d_s(i,7);
           if(diff==0){
               zeros++;
           } else if(diff<0){
               last_non_zero=i;
               diff=0-diff;
               for(int i=neg_cnt-1;i>=0;i--){
                   neg[i+diff]+=neg[i];
                   neg[i]=0;
               }
               // handle zero
               neg[diff-1]+=zeros;zeros=0;
               for(int i=0;i<posi_cnt;i++){
                   if(i+1-diff==0){
                       zeros+=posi[i]; posi[i]=0;
                   } else if(i+1-diff<0){
                       neg[diff-i-2]+=posi[i]; posi[i]=0;
                   } else{
                       posi[i-diff]+=posi[i]; posi[i]=0;
                   }
               }
               neg_cnt+=diff;
               neg[diff-1]++;
               if(posi_cnt>=diff){
                   posi_cnt-=diff;
               } else { posi_cnt==0;}

               // update counters
           } else if(diff>0){
               last_non_zero=i;
              for(int i=posi_cnt-1;i>=0;i--){
                  posi[i+diff]+=posi[i];posi[i]=0;
              }
              // handle zero
              posi[diff-1]+=zeros;zeros=0;
              for(int i=0;i<neg_cnt;i++){
                  if(i+1-diff==0){
                      zeros+=neg[i];neg[i]=0;
                  } else if(i+1-diff<0){
                      posi[diff-i-2]+=neg[i];neg[i]=0;
                  } else {
                      neg[i-diff]= neg[i]; neg[i]=0; 
                  }
              }
              posi[diff-1]++;
              //update counters
              posi_cnt+=diff;
              if(neg_cnt>=diff){
                  neg_cnt-=diff;
              } else {
                  neg_cnt=0;
              }
           }
           ans+=zeros;
           printf("%d  %d  %d\n",i,zeros,ans);
    }
}
