#include<cstdio>
typedef unsigned long long ull;
	void multiplyMatrices(ull A[2][2],ull B[2][2],ull mod){
		ull t00 = (A[0][0] * B[0][0])%mod  +  (A[0][1] * B[1][0])%mod;
		ull t01 = (A[0][0] * B[0][1])%mod  +  (A[0][1] * B[1][1])%mod;
		ull t10 = (A[1][0] * B[0][0])%mod  +  (A[1][1] * B[1][0])%mod;
		ull t11 = (A[1][0] * B[0][1])%mod  +  (A[1][1] * B[1][1])%mod;
                A[0][0]=t00%mod; 
                A[1][0]=t10%mod; 
                A[0][1]=t01%mod; 
                A[1][1]=t11%mod;
	}

	void fastExponentiate(ull x[2][2],ull N,ull mod){
		ull  retVal[2][2] = {
			{1,0},
			{0,1}
		};
		while(N>0){
                   if(N&1){  // if odd
			   multiplyMatrices(retVal,x,mod);
			   N--;
		   }
		   multiplyMatrices(x,x,mod);
		   N = N>>1; // divide by two
		}
                x[0][0]=retVal[0][0]; 
                x[1][0]=retVal[1][0]; 
                x[0][1]=retVal[0][1]; 
                x[1][1]=retVal[1][1]; 
	}
ull calcFib(ull n,ull mod){
    if(n<3){
        if(n<1){
	    return 0;
	}
	return 1;
    }
    ull fibMat[2][2]= {{1,1},{1,0}};
    fastExponentiate(fibMat,n-1,mod);
    return fibMat[0][0];
}


int main(){
  ull n,m,m2,tmp;
  while(scanf("%llu %llu",&n,&m)>0){
      m2 = 1<<m;
      printf("%llu\n",calcFib(n,m2));
  }
}
