#include<stdio.h>


bool isdel(long long n){
    int dgts[10];
    for(int i=0;i<10;i++){
            dgts[i]=false;
            }     
            while(n>0){
                       int d = n%10;
                       if(dgts[d]) return false;
                       dgts[d]=true;
                       n/=10;
            }
            return true;
}
long long tenpow[]={1,10,100,1000,10000,100000,1000000,10000000LL,100000000LL,1000000000LL,10000000000LL};
long long normalize(long long n){
   long long sub=1, n1=n;
   int hasd[10];
  
   int sz = 0; while(n1>0){ sz++; n1/=10; }
   if(sz==1) return n;
   for(int i=0;i<10;i++) hasd[i]=0;
   n1 = n;
   int iter=1;
   while(sz>0){
       int d =   (n1/tenpow[sz-1])%10;
       if(hasd[d]){
            n1 = (((n1/tenpow[sz-1])-1)*tenpow[sz-1])+ (tenpow[sz-1]-1);
            return normalize(n1);
       } 
       sz--;       
       hasd[d]=1;
   }    
   return n;
}
long long dop(long long n){
     if(n<10) return n+1;
     n = normalize(n); //printf("norm %lld\n",n);
     int sz = 0;long long n1 = n;while(n1>0) {sz++; n1/=10; } 
     if(sz==1) return n+1;
     long long cum[]={0,10,91,739,5275,32491,168571,712891,2345851,5611771,8877691};
     int digits[20];n1=n;
     long long fs[]={1,1,2,6,24,120,720,720*7,720*7*8,720*7*8*9,720*7*8*9*10};
     for(int i=0;i<sz;i++){
             digits[i] = n1%10;
             n1/=10;
     }
     int hasd[10],ds[20];
     for(int i=0;i<10;i++) { hasd[i]=0; ds[i]=0;}
     for(int i=sz-1;i>=0;i--){
           for(int j=0;j<=digits[i];j++){
                   if(hasd[j]){
                          ds[i]++;     
                   }
           }
           hasd[digits[i]]=1;  
          // printf("%d ",ds[i]);
     }
     ds[sz-1]=1;
    // printf("\n");
     long long ans=0;
     int nf=9;
     for(int i=sz-1;i>=0;i--){
         if((digits[i]-ds[i])>0){
           ans+= (digits[i]-ds[i]) *(fs[nf]/fs[10-sz]);
         
         }
           if(i==1){
                    ans+=1;
           }
           nf--;
     }
     return ans+cum[sz-1];
}
long long mn = 9999999999LL;

int main(){
    long long n ;
    long long a,b;
    int T;scanf("%d",&T);
    while(T-->0){
    scanf("%lld %lld",&a,&b);
        if(b>mn) b = mn;
            if(a>mn) a = mn;
    long long ans=0;
   /* for(long long i=a;i<=b;i++){
             if(isdel(i)){
                ans++;
             }
    }
    printf("%lld\n",ans);*/
    if(a>=mn&&b>=mn) { printf("0\n");return 0;}
    bool isa = isdel(a);
    printf("%lld\n",dop(b)-dop(a)+(isa?1:0));
}
  //  scanf("%lld",&n);
}
