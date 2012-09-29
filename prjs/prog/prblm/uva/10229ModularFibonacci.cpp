#include<cstdio>
typedef unsigned long long ull;
ull Divide_Conquer_Fib(ull n,ull mod) {
ull i,h,j,k,t; 
i = h = 1;
j = k = 0;
while (n > 0) {
	if (n%2 == 1) { // if n is odd
		t = (j*h)%mod;
		j = (((i*h)%mod + (j*k)%mod)%mod + t)%mod;
		i = ((i*k)%mod + t%mod)%mod;
	}
	t = (h*h)%mod;
	h = ((2*(k*h)%mod)%mod + t)%mod;
	k = ((k*k)%mod + t)%mod;
	n = (ull) n/2;
} 
return j%mod;
}

int main(){
  ull n,m,m2,tmp;
  while(scanf("%llu %llu",&n,&m)>0){
      m2 = 1<<m;
      printf("%llu\n",Divide_Conquer_Fib(n,m2));
  }
}
