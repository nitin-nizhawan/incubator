#include<stdio.h>
#include<stdlib.h>
int sum_z(int s,int e){
    int n4=0;
    int n7=0;
    for(int i=s;i<=e;i++){
        int t = i;
        while(t>0){
            int d = t%10;
            if(d==4){
                n4++;
            }
            if(d==7){
                n7++;
            }
            t/=10;
        }
    }
    return n4-n7;
}
int findit(int N){
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            if(sum_z(j,i)==0){
                ans++;
            }
        }
    }
    return ans;
}
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
int main(int argc, char* argv []){
int N = atoi(argv[1]);
int ans=1;
int tans=0;
int tmpj=0;
int t4s=0;
int t7s=0;
for(int i=1;i<=N;){
   printf("%10d%10d%10d%10d%10d\n",i,ans,tans,t4s,t7s);
   i++;
   t4s+=n_d_s(i,4);
   t7s+=n_d_s(i,7);
   tans=0;
   tmpj=0;
   for(int j=i;j>=1;j--){
       tmpj+= (n_d_s(j,4)-n_d_s(j,7));
       if(tmpj==0){
           tans++;
       }
   }
   ans+=tans;
}
printf("\n");
}
