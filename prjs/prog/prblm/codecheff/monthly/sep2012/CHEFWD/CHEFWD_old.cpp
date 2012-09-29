#include<stdio.h>
long long PRIME=1000000007;
long long N;
long long initmat[4][4]={
   {1,1,5,3},
   {1,0,0,0},
   {0,0,1,1},
   {0,0,1,0}
};
long long base[4][4];
long long result[4][4];
long long tmp[4][4];
void printResult(){
#ifdef MY_DEBUG
  printf("----Result -----\n");
   for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
          printf("%10lld  ",result[i][j]);
       }
    printf("\n");
   }

#endif
  
}

void baseWithResult1(){
    tmp[0][2] = ((((base[0][0]*result[0][2])%PRIME + (base[0][1]*result[1][2])%PRIME)%PRIME + (base[0][2]*result[2][2])%PRIME)%PRIME + (base[0][3]*result[3][2])%PRIME)%PRIME;
    tmp[1][2] = ((((base[1][0]*result[0][2])%PRIME + (base[1][1]*result[1][2])%PRIME)%PRIME + (base[1][2]*result[2][2])%PRIME)%PRIME + (base[1][3]*result[3][2])%PRIME)%PRIME;

    tmp[0][3] = ((((base[0][0]*result[0][3])%PRIME + (base[0][1]*result[1][3])%PRIME)%PRIME + (base[0][2]*result[2][3])%PRIME)%PRIME + (base[0][3]*result[3][3])%PRIME)%PRIME;
    tmp[1][3] = ((((base[1][0]*result[0][3])%PRIME + (base[1][1]*result[1][3])%PRIME)%PRIME + (base[1][2]*result[2][3])%PRIME)%PRIME + (base[1][3]*result[3][3])%PRIME)%PRIME;
    tmp[2][3] = ((((base[2][0]*result[0][3])%PRIME + (base[2][1]*result[1][3])%PRIME)%PRIME + (base[2][2]*result[2][3])%PRIME)%PRIME + (base[2][3]*result[3][3])%PRIME)%PRIME;
    tmp[3][3] = ((((base[3][0]*result[0][3])%PRIME + (base[3][1]*result[1][3])%PRIME)%PRIME + (base[3][2]*result[2][3])%PRIME)%PRIME + (base[3][3]*result[3][3])%PRIME)%PRIME;
    
    result[0][2] = tmp[0][2];result[1][2]= tmp[1][2];
    result[0][3] = tmp[0][3]; result[1][3] = tmp[1][3]; result[2][3] = tmp[2][3]; result[3][3] = tmp[3][3];

    result[0][0] = (result[2][3] + result[3][3])%PRIME;
    result[0][1] = result[2][3];
    result[1][0] =  result[2][3];
    result[1][1] = result[3][3];
    result[2][2] = result[0][0];
    result[3][2] = result[2][3];
    
}
void baseWithBase1(){
    tmp[0][2] = ((((base[0][0]*base[0][2])%PRIME + (base[0][1]*base[1][2])%PRIME)%PRIME + (base[0][2]*base[2][2])%PRIME)%PRIME + (base[0][3]*base[3][2])%PRIME)%PRIME;
    tmp[1][2] = ((((base[1][0]*base[0][2])%PRIME + (base[1][1]*base[1][2])%PRIME)%PRIME + (base[1][2]*base[2][2])%PRIME)%PRIME + (base[1][3]*base[3][2])%PRIME)%PRIME;

    tmp[0][3] = ((((base[0][0]*base[0][3])%PRIME + (base[0][1]*base[1][3])%PRIME)%PRIME + (base[0][2]*base[2][3])%PRIME)%PRIME + (base[0][3]*base[3][3])%PRIME)%PRIME;
    tmp[1][3] = ((((base[1][0]*base[0][3])%PRIME + (base[1][1]*base[1][3])%PRIME)%PRIME + (base[1][2]*base[2][3])%PRIME)%PRIME + (base[1][3]*base[3][3])%PRIME)%PRIME;
    tmp[2][3] = ((((base[2][0]*base[0][3])%PRIME + (base[2][1]*base[1][3])%PRIME)%PRIME + (base[2][2]*base[2][3])%PRIME)%PRIME + (base[2][3]*base[3][3])%PRIME)%PRIME;
    tmp[3][3] = ((((base[3][0]*base[0][3])%PRIME + (base[3][1]*base[1][3])%PRIME)%PRIME + (base[3][2]*base[2][3])%PRIME)%PRIME + (base[3][3]*base[3][3])%PRIME)%PRIME;
    
    base[0][2] = tmp[0][2];base[1][2]= tmp[1][2];
    base[0][3] = tmp[0][3]; base[1][3] = tmp[1][3]; base[2][3] = tmp[2][3]; base[3][3] = tmp[3][3];

    base[0][0] = (base[2][3] + base[3][3])%PRIME;
    base[0][1] = base[2][3];
    base[1][0] =  base[2][3];
    base[1][1] = base[3][3];
    base[2][2] = base[0][0];
    base[3][2] = base[2][3];
    
}

void baseWithResult(){
   for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
              tmp[i][j] =0;
           for(int k=0;k<4;k++){
               tmp[i][j]=(tmp[i][j]+(base[i][k]*result[k][j])%PRIME)%PRIME;
           }
         
       }
   }
   for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        result[i][j] = tmp[i][j];
      }
   }
//printResult();
}
void baseWithBase(){
   for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
              tmp[i][j] =0;
           for(int k=0;k<4;k++){
               tmp[i][j]=(tmp[i][j]+(base[i][k]*base[k][j])%PRIME)%PRIME;
           }
         
       }
   }
   for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        base[i][j] = tmp[i][j];
      }
   }
}
void raisePow1(long long exp){
//  initialize 
	for(int i=0;i<4;i++) {
	  for(int j=0;j<4;j++) {
               if(i==j) result[i][j] = 1; else result[i][j]=0;
               base[i][j] =initmat[i][j];
	  }
	}
    printBase();
      while(exp>0){
             if(exp%2==1){
                 baseWithResult1();
                 exp-=1;
             }
             baseWithBase1();;
//printBase();
             exp = exp/2;
      } 

     
}

void raisePow(long long exp){
//  initialize 
	for(int i=0;i<4;i++) {
	  for(int j=0;j<4;j++) {
               if(i==j) result[i][j] = 1; else result[i][j]=0;
               base[i][j] =initmat[i][j];
	  }
	}
      while(exp>0){
             if(exp%2==1){
                 baseWithResult();
                 exp-=1;
             }
             baseWithBase();;
//printBase();
             exp = exp/2;
      } 

     
}
long long solve1(){
    raisePow1(N-2);
    return (((result[0][0]*5)%PRIME+(result[0][2]*2)%PRIME)%PRIME+result[0][3]%PRIME)%PRIME;
}

long long solve(){
    raisePow(N-2);
    return (((result[0][0]*5)%PRIME+(result[0][2]*2)%PRIME)%PRIME+result[0][3]%PRIME)%PRIME;
}
int  main(){
   int T;
   scanf("%d",&T);
   while(T-->0){
       scanf("%lld",&N);
      if(N<2){
          printf("%d\n",0);
      } else if(N==2){
           printf("%d\n",5);
       } else{

         printf("%lld\n",solve1()); 
    printResult();
     }
   }
}
