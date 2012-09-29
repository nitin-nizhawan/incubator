#include<stdio.h>
int nums[400001];
int qu[400001];
int head=0,tail=0;
void add(int n){
    qu[tail]=n;
    tail=(tail+1)%400000;
}
int peek(){
    return qu[head];
}
void append(int n){
    head = (head-1+400000)%400000;
    qu[head]=n;
}
int remove(){
   int v = qu[head];
   head=(head+1)%400000;
}
int main(){
    int min=50000;
    int max=0;
    int N,W;
    scanf("%d",&N);
    scanf("%d",&W);
    long long sum = 0;
    long long partialsum = ((W-1)*W)/2;
    int tmp;
// input all elements
    for(int i=0;i<N;i++){
       scanf("%d",&nums[i]);
    }
    // create asscending min
     
    append(nums[W-1]);
    sum = nums[W-1];
    for(int i=W-2;i>=0;i--){
        if(nums[i]<peek()){
            append(nums[i]);
        }
        sum+=nums[i];
    }
    long long calcsum = W*peek() + partialsum;
    int ans=0;
    if(sum==calcsum){
        ans++;
    }
    for(int i=W;i<N;i++){
        sum+=nums[i];
        sum-=nums[i-W];
        if(peek()==nums[i-W]){
            remove();
        }
        while(nums[i]<=peek()){
            remove();
        }
        add(nums[i]);
        calcsum = W*peek()+partialsum;
       if(sum==calcsum){
            ans++;
       }
    }
   printf("%d\n",ans);


}
