
#include <stdio.h>
#define MAX 20
#define FOR(a,b) for(int a=0;a<(b);a++)
long long ctable[MAX][MAX];
int dp[400];
bool isLucky(char *b){
}
long long toBits(char *b){
	
}
long long luckyceil(long long b){
}
long long luckyfloor(char *b){
	if(isLucky(b)){
		return toBits(b);
	}
	return luckyceil(b)-1;
}
void initctab(){
	ctable[0][0]=1;
	for(int i=1;i<MAX;i++){
		ctable[i][0] = 1;
		for(int j=1;j<=i;j++){
			ctable[i][j] = ctable[i-1][j-1]+ctable[i-1][j];
		}
	}
}
void printctab(){
	FOR(i,MAX){
		FOR(j,MAX){
			printf("%lld ",ctable[i][j]);
		}
		printf("\n");
	}
}
int nsetbits(int i,int k){
	if(k==0) return 0;
	if(k==1){
		return i+1;
	}
	return ctable[i][k];
}
int fnk(int n,int k){
    int ans=0;
	int pos=10;
	int onebits=0;
	int buff[40];
	
	//int sb=k-onebits+1;
	while(pos>=0){
		if(n&(1<<pos)){
			ans+=nsetbits(pos,k);
			k--;
		}
		pos--;
		//n/=2;
		
	}
	return ans;
}
int bc(int n,int k){
	if(n==0){
		dp[0]=0;
		if(k==0) dp[0]=1;
		return dp[n];
	}
  int nb=0;
  int tn=n;
  while(n>0){
	  if(n%2) nb++;
	  n/=2;
  }
  if(nb==k){
     dp[tn] = dp[tn-1]+1;
  } else {
	  dp[tn] = dp[tn-1];
  }
  return dp[tn];
}
bool frangek(int low,int high,int k){
	int nb=0;
	int tmp=low;
	while(tmp>0){nb+=(tmp%2); tmp/=2;}
	int ans=fnk(high,k) - fnk(low,k) + (nb==k?1:0);
	return ans>=1;
}
int maxprod(int low,int high,int len){
	int max=0;
	for(int i=1;i<len;i++){
		if(frangek(low,high,i)){
			int prod=i*(len-i);
			if(prod>max){
				max=prod;
			}
		}
	}
	return max;
}

int Llen(long long a){
    int len=0;
    while(a>0){
        len++;
        a/=10;
    }
    return len;
}
long long luckciel(long long A){
    int len = Llen(A);

}
long long solve(long long L,long long R){
    long long LL,LLlen,LR,LRlen;
    LL=luckciel(L);
    LR=luckfloor(R);
}
int main(int argc, char* argv[])
{
	initctab();
	printctab();
	int k=3;
	for(int i=0;i<100;i++){
        printf("%d, %d , %d\n",i,fnk(i,k),bc(i,k));
	}

    printf("==> %d\n",maxprod(7,15,4));

    int T;
    scanf("%d",&T);
    long long  L,R;
    while(T--){
        scanf("%lld",&L);
        scanf("%lld",&R);
        printf("%lld\n",solve(L,R));
    }

	return 0;
}

