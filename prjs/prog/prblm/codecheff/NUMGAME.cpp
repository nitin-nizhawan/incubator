#include<cstdio>
int main(){
long T;
scanf("%ld",&T);
unsigned long long n;
while(T--){
scanf("%llu",&n);
n&1?printf("BOB\n"):printf("ALICE\n");
}
}
