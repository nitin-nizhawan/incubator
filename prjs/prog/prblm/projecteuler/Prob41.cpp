#include<stdio.h>

bool isprime(long long n){
   if(n<2) return false;
   if(n==2) return true;
   long long  d = 3;
   while(d < n){
         if(n%d == 0) return false;
         d+=2LL;
   }
   return true;
}
long long getNum(long long n[],int cnt){
    long long num=0;
    for(int i=0;i<cnt;i++){
       num = n[i] + num*10LL;
    }
    return num;
}
void swap(long long& a,long long &b ){
   int tmp = a;
   a = b;
   b = tmp;
}
int perm_next( long long n[],int count) {
    int tail, i, j;

    if (count <= 1)
        return 0;

    /* Find all terms at the end that are in reverse order.
       Example: 0 3 (5 4 2 1) (i becomes 2) */
    for (i=count-1; i>0 && n[i-1] >= n[i]; i--);
    tail = i;

    if (tail > 0) {
        /* Find the last item from the tail set greater than
            the last item from the head set, and swap them.
            Example: 0 3* (5 4* 2 1)
            Becomes: 0 4* (5 3* 2 1) */
        for (j=count-1; j>tail && n[j] <= n[tail-1]; j--);

        swap(n[tail-1], n[j]);
    }

    /* Reverse the tail set's order */
    for (i=tail, j=count-1; i<j; i++, j--)
        swap(n[i], n[j]);

    /* If the entire list was in reverse order, tail will be zero. */
    return (tail != 0);
}
long long fact(long long n){
  long long f=1;
  for(long long i=1;i<=n;i++){
      f = f*i;
  }
  return f;
}
void check(long long n[], int cnt){
   long long total = fact(cnt); 
while(total>0){
long long num = getNum(n,cnt);
//      printf("Testing: %lld\n",num);
  if(isprime(num)){
      printf("prime: %lld\n",num);
 //     break;
  }
  perm_next(n,cnt);   
  total--;
}

}
int main(){
   long long n[] = {1,2,3,4,5,6,7,8,9};
for(int i=2;i<=9;i++){
  check(n,2); 
  check(n,3); 
   check(n,4); 
   check(n,5); 
   check(n,6); 
   check(n,7); 
  check(n,8); 
   check(n,9); 
}
}
