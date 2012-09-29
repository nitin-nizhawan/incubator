#include<stdio.h>
#include<stdlib.h>
long long A[2000];
int main(){
	int  T =10;
	printf("%d\n",T);
	while(T-->0){
		int N = rand()%10 + 10;
		printf("%d\n",N);
		int M = rand()%55 + 5;
		long long xsum=0;
		for(int i=0;i<N-1;i++){
			A[i]=rand()%(1<<M) + 1;
			xsum^=A[i];
		}
		A[N-1]=xsum;
                long long test=0;
                for(int i=0;i<N;i++){
                    test^=A[i];
                }
                if(test>0){
                     int a = 1;
                       a=a/(a-1);
                }
		for(int i=0;i<N;i++){
			if(i>0) printf(" ");
			printf("%lld",A[i]);
		}
		printf("\n");
	}
}
