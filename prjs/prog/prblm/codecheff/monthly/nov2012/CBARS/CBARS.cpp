#include<stdio.h>
unsigned long long mat[100][100];
unsigned long long res[100][100];
unsigned long long t[100][100];
unsigned long long PRIME=1000000007;
bool isValid(int x,int y,int a){
     
     for(int i=0;i<a-1;i++){
             if(((x&y)&(1<<i))&&((x&y)&(2<<i))){
                 return false;
             }
             if((((~x)&(~y))&(1<<i))&&(((~x)&(~y))&(2<<i))){
                 return false;
             }
     }
     return true;
}
void genmat(int a){
     int up = 1<<a;
     for(int i=0;i<up;i++){
             for(int j=0;j<up;j++){
                     res[i][j]=((i==j)?1:0);
                     if(isValid(i,j,a)){
                         mat[i][j]=1;
                     } else {
                         mat[i][j]=0;
                     }
             }
     }
}
unsigned long long pow2(unsigned long long n){
   unsigned long long r=1;
   unsigned long long b=2;
   while(n>0){
        if(n%2==1){
            r = (r*b)%PRIME;
            n--;
        }
        b = (b*b)%PRIME;
        n=n/2;
   }
   return r;
}
void rWithb(int a){
     int up = 1<<a;
     for(int i=0;i<up;i++){
         for(int j=0;j<up;j++){
              t[i][j] = 0;   
              for(int k=0;k<up;k++){
                      t[i][j] = (t[i][j] + (res[i][k]*mat[k][j])%PRIME)%PRIME;
              }   
         }
     }
     for(int i=0;i<up;i++){
             for(int j=0;j<up;j++){
                     res[i][j]=t[i][j];
             }
     }
}
void bWithb(int a){
     int up = 1<<a;
     for(int i=0;i<up;i++){
         for(int j=0;j<up;j++){
              t[i][j] = 0;   
              for(int k=0;k<up;k++){
                      t[i][j] = (t[i][j] + (mat[i][k]*mat[k][j])%PRIME)%PRIME;
              }   
         }
     }
     for(int i=0;i<up;i++){
             for(int j=0;j<up;j++){
                     mat[i][j]=t[i][j];
             }
     }
}
void raisePow(unsigned long long p,int a){
     while(p>0){
         if(p%2==1){       
             rWithb(a); p--;
         }
          bWithb(a);
          p=p/2;
     }

}
int main(){
    int a;
    unsigned long long b;
    scanf("%d %llu",&a,&b);
    if(a==1||b==1){
        printf("%llu\n",pow2(a==1?b:a));
    } else {
        genmat(a);
        raisePow(b-1,a);
        int up = 1<<a;
        unsigned long long ans=0;
        for(int i=0;i<up;i++){
                for(int j=0;j<up;j++){
                    ans = (ans+res[i][j])%PRIME;
                }
        }   
        printf("%llu\n",ans);
    }
   // int p;
   //scanf("%d",&p);
}
