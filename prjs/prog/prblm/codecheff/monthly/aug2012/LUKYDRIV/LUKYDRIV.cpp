#include<stdio.h>
char buff[11000];
long long f[10];
long long PRIME=1000000007;
int pats2[]={9,18,27,36,45,99};
int pats3[]={ 9 ,18 ,27 ,36 ,45 ,99 ,117 ,126 ,135 ,144 ,189 ,225 ,234 ,279 ,288 ,333 ,369 ,378 ,459 ,468 ,477 ,558 ,567 ,666 ,999 };
int pats4[]={9 ,18 ,27 ,36 ,45 ,99 ,117 ,126 ,135 ,144 ,189 ,225 ,234 ,279 ,288 ,333 ,369 ,378 ,459 ,468 ,477 ,558 ,567 ,666 ,999 ,1116 ,1125 ,1134 ,1179 ,1188 ,1224 ,1233 ,1269 ,1278 ,1359 ,1368 ,1377 ,1449 ,1458 ,1467 ,1557 ,1566 ,1899 ,2223 ,2259 ,2268 ,2277 ,2349 ,2358 ,2367 ,2448 ,2457 ,2466 ,2556 ,2799 ,2889 ,3339 ,3348 ,3357 ,3366 ,3447 ,3456 ,3555 ,3699 ,3789 ,3888 ,4446 ,4455 ,4599 ,4689 ,4779 ,4788 ,5589 ,5679 ,5688 ,5778 ,6669 ,6678 ,6777 ,9999};
/*int T2(){
    int data[]={acc[0]*acc[9],
                acc[1]*acc[8],
                acc[2]*acc[7],
                acc[3]*acc[6],
                acc[4]*acc[5],
                (acc[9]*(acc[9]-1))/2 
               };
    int res=0;
    for(int i=0;i<6;i++){
        res = (res + (data[i]%PRIME))%PRIME;
    }
    return res;
}
*/
long long C(long long r, int ni){
    long long int n = f[ni];
//    printf("(%d,%d,%d)\n",r,n,ni);
    if(n<r) return 0;
    if(n==r) return 1;
    if(r==1) return n;
    if(r==2) return ((n*(n-1))/2)%PRIME;
    long long p = 1;
    long long fact = 1;
    for(int i=0;i<r;i++){
       fact=fact*(i+1);
       p =p*(n-i);
      // if(p>PRIME) printf("p=%lld\n",p);
    }
    p = p/fact;
    return p%PRIME;
}
long long TR(int *pats,int size,int len){
    long long total=0;
    for(int i=0;i<len;i++){
       int codeword = pats[i];        
       int cnt=0;
       int last=-1;
       long long t=1;
       for(int j=0;j<size;j++){
           int d = codeword%10;
           if(d==last) cnt++;
           if(d!=last&&last!=-1){
               t*=C(cnt+1,last);
               cnt=0;
               last=d;
           } else if (d!=last) {
               last=d;
           }
           codeword/=10;
       }
       t=(t*C(cnt+1,last))%PRIME;
       cnt=0;
       total = (total + t)%PRIME;
    }
    return total;
}
int main(){
   int T;
   scanf("%d",&T);
   while(T-->0){
       scanf("%s",buff);
       for(int a=0;a<10;a++) f[a]=0;
       int i=0;
       while(buff[i]!='\0'){
           int d = buff[i]-'0';
           f[d]++;
           i++;
       }
           long long ans = f[9];
           ans = (ans + TR(pats2,2,6))%PRIME;
           ans = (ans + TR(pats3,3,25))%PRIME;
           ans = (ans + TR(pats4,4,sizeof(pats4)/sizeof(int)))%PRIME;
       printf("%lld\n",ans);
   }
}
