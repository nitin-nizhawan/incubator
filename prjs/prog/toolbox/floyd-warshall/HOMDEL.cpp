#include<stdio.h>
int path[300][300];
int N,M;
int min2(int a,int b){
	return a<b?a:b;
}
void fv(){
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				path[i][j] = min2 ( path[i][j], path[i][k]+path[k][j] );
			}
		}
	}

}
int main(){
   scanf("%d",&N);
   for(int i=0;i<N;i++){
       for(int j=0;j<N;j++){
           scanf("%d",&path[i][j]);
       }
   }
   fv();
   scanf("%d",&M);
   int S,G,D;
   while(M-->0){
 
       scanf("%d",&S);
       scanf("%d",&G);
       scanf("%d",&D);
       int cost = path[S][G]+path[G][D];
       printf("%d %d\n",cost,cost-path[S][D]);
   }
}
