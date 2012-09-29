#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
int *nums;//[400001];
int N,W;
int ans=0;
struct pairs {
    int value;
    int death;
};//ring[400001];
struct pairs* ring;
void
minwindow(int *in,  int n, int k)
{
    int i;
//    struct pairs ring[n];
    struct pairs * minpair;
    struct pairs * end;
    struct pairs * last;

 //   ring =(pairs*) malloc(k * sizeof *ring);
  //  if (!ring) exit(EXIT_FAILURE);
    end  = ring + k;
    last = ring;
    minpair = ring;
    minpair->value = in[0];
    minpair->death = k;
    long long sum=in[0];
    long long pc = (((long long)k)*((long long)(k-1)))/2;
    for (i=1;i<n;i++) {
        sum+=in[i];
        if (i>=k) {
            sum-=in[i-k]; }
	    if(minpair->death==i){
		    minpair++;
		    if (minpair >= end) minpair = ring;
	    }
        if (in[i] <= minpair->value) {
            minpair->value = in[i];
            minpair->death = i+k;
            last = minpair;
        } else {
            while (last->value >= in[i]) {
                if (last == ring) last = end;
                --last;
            }
            ++last;
            if (last == end) last = ring;
            last->value = in[i];
            last->death = i+k;
        }
         if(i>=(k-1)){
   //           printf("min %d , sum %lld \n",minpair->value,sum);
              if(((long long)minpair->value)*((long long)k) + pc==sum){
                      ans++;
              }
         }
        //out[i] = minpair->value;
    }
    //free(ring);
}
/*
int soln2(){
   if(W==1){
      ans=N;
      return;
   }
   minwindow(nums,out,N,W);
 //  printf("min win\n");
   long long  sum =0;
   int ans=0;
   long long pc = (W*(W-1))/2;
   for(int i=0;i<W;i++){
      sum+=nums[i];
   }
       if(sum==pc+((long long)out[W-1])*((long long)W)){
           ans++;
       }
   for(int i=W;i<N;i++){
       sum-=nums[i-W];
       sum+=nums[i];
       if(sum==pc+((long long)out[i])*((long long)W)){
           ans++;
       }
   }
   return ans;
}
*/
int main(){
   int T;
   scanf("%d",&N);
   scanf("%d",&W);
   nums =(int*) malloc(N*sizeof(int));
   ring = (pairs*) malloc(W*sizeof(*ring));
   for(int i=0;i<N;i++){
	   scanf("%d",&nums[i]);
   }
   if(W>1){
	   minwindow(nums,N,W);
   }

   if(W>1){
   printf("%d\n",ans);
   } else {
    printf("%d\n",N);
   }
   free(nums);
   free(ring);
}
    
