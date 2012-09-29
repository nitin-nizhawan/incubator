#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
int *nums;//[400001];
int *out;//[400001];
int N,W;

struct pairs {
    int value;
    int death;
};//ring[400001];
struct pairs* ring;
void
minwindow(int *in, int *out, int n, int k)
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
    out[0] = in[0];

    for (i=1;i<n;i++) {
        if (i>=k&&minpair->value == in[i-k]) {
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
        out[i] = minpair->value;
    }
    //free(ring);
}
int soln2(){
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
//   printf("");
   return ans;
}
int soln(){
    long long sum=0;
    long long min=nums[0];
    long long pc = (W*(W-1))/2;
    int ans=0;
    for(int i=0;i<W;i++){
          sum+=nums[i];
          if(min>nums[i]){
              min = nums[i];
          }
    }
    if(min*W+pc==sum) { ans++;}
    for(int i=W;i<N;i++){
        sum-=nums[i-W];
        sum+=nums[i];
        min = nums[i-W+1];
        for(int j=0;j<W;j++){
            if(nums[i-W+j+1]<min){
                min = nums[i-W+j+1];
            }
        }
        if(min*W+pc==sum) { ans++; }
    }
    return ans;
}
int brute_force(){
     int tmp[400001];
     int ans=0;
     for(int i=0;i<=(N-W);i++){
         for(int j=0;j<W;j++){
             tmp[j]=nums[j+i];
	 }
	 std::sort(tmp,tmp+W);
	 bool flag=true;
	 for(int l=0;l<W;l++){
		 if(tmp[l]!=tmp[0]+l){
			 flag=false;
			 break;
		 }
	 }
	 if(flag){
		 ans++;
	 }

     }
     return ans;
}
void solve(){
   int br = brute_force();
   int sl = soln();
   int sl2 = soln2();
   printf("br=%d,  sol=%d,sl2=%d\n",br,sl,sl2);
if(br!=sl||sl2!=sl||sl2!=br){
  printf("error\n");
  exit(1);
 }
/*   if(sl!=br){
      sl*br/(sl*br-sl*br);
   }*/
}
int main(){
   int T;
   //scanf("%d",&T);
  // while(T-->0){
       scanf("%d",&N);
       scanf("%d",&W);
       nums =(int*) malloc(N*sizeof(int));
       out = (int*) malloc(N*sizeof(int));
       ring = (pairs*) malloc(W*sizeof(*ring));
       for(int i=0;i<N;i++){
           scanf("%d",&nums[i]);
       }
/*	printf("%d %d\n",N,W);
	for(int i=0;i<N;i++){
		printf("%d ",nums[i]);
	}
	printf("\n"); */

//       solve();
          printf("%d\n",soln());
  // }
   free(nums);
   free(out);
   free(ring);
}
int main1(){
    int     T=5000;
    while(T-->0){
        N = 200 + 1;
        W = rand()%(N/10+1) + 1;
        for(int i=0;i<N;i++){
            nums[i]=i+1;
        }
        for(int i=0;i<N;i++){
            int swp = rand()%(N-i);
            int tmp = nums[i];
            nums[i] = nums[i+swp];
            nums[i+swp]=tmp;
        }
	printf("%d %d\n",N,W);
	for(int i=0;i<N;i++){
		printf("%d ",nums[i]);
	}
	printf("\n");
        solve();
    }
    
}
