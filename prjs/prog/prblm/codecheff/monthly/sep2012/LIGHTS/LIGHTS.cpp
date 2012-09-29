#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int N;
double L,R;
double X[50001],Y[50001],Z[50001];
double S[50001],E[50001];

bool iscovered(double p){
   int cnt=0;
   for(int i=0;i<N;i++){
       if(p<Y[i]){
           double len = (Y[i]-p)*Z[i];
           //printf("%lf, ",len);
           S[cnt]=X[i]-len;
           E[cnt]=X[i]+len;
           cnt++;
       }
   }
   //printf("\n");
/*   for(int i=0;i<cnt;i++){
      printf("( %lf,%lf ) ",S[i],E[i]);
   }
   printf("\n"); */
   sort(S,S+cnt);
   sort(E,E+cnt);
/*   printf("S :");
   for(int i=0;i<cnt;i++){
        printf("%lf , ",S[i]);
   }
   printf("\n");
   printf("E :");
   for(int i=0;i<cnt;i++){
        printf("%lf , ",E[i]);
   }
   printf("\n"); */
   if(S[0]>L||E[cnt-1]<R){
       return false;
   }
   int k=1;
   if(S[0]>E[0]){
      printf("Error\n");
   }
   int pp=1,ep=0;
   while(pp<cnt&&ep<cnt){
//   printf("pp=%d,ep=%d,k=%d\n",pp,ep,k);
       if(S[pp]<E[ep]){
           k++;pp++;
       } else if(E[ep]<S[pp]){
           k--; if(E[ep]>=L&&E[ep]<=R&&k<1) return false;
          ep++;
       } else {
          pp++;ep++;
       }
   }
   while(ep<cnt){
           k--; if(E[ep]>=L&&E[ep]<=R&&k<1) return false;
          ep++;
   }
   return true;
}
int f(double p){
   bool iscov = iscovered(p);
   bool iscov2 = iscovered(p+0.0000001);
  // printf("icov: %d %d\n",iscov,iscov2);
   if(iscov&&!iscov2){
       return 0;
   } else if(iscov) {
       return -1;
   } else {
       return 1;
   }
   
}
double bisearch(double m){
     double left=0;
     double right = m;
     while(true){
	     double middle=(left+right)/2;
             int fm = f(middle);
             //printf("%d at %lf\n",fm,middle);
	     if(fm==0){
                 return middle;
             } else if(fm>0){
                 right = middle;
             } else {
                 left = middle;
             }
     }
}
int main(){
   scanf("%d",&N);
   scanf("%lf",&L);
   scanf("%lf",&R);
   double maxy=0;
//   printf("PI is %lf\n",M_PI);
   for(int i=0;i<N;i++){
       scanf("%lf",&X[i]);
       scanf("%lf",&Y[i]);
       scanf("%lf",&Z[i]);
       Z[i] = tan((M_PI*Z[i])/180);
       if(Y[i]>maxy){ maxy = Y[i] ; };
   }
   printf("%.10lf\n",bisearch(maxy));
}
