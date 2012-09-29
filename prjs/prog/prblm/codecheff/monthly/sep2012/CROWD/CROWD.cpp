#include<stdio.h>

/**
 * this problem is same as finding number of bit strings 
 * of length N which 3 of more consecutive 1's
 * let a[n] be the number of such bit string of length
 * then for n>=3 , there are 4 cases to be considered
 * 1) strings of length n ending with a 0, then number of such strings which have 
 * three bits set  is a[n-1] because we fixed one bit to 0
 * 2) string of length n ending with a 01, the number of such strings which have
 * three bits set is a[n-2], this time we fixed two bits to 01
 * 3) strings of length n ending with a 011, the number of such strings which 
 * have three bits set is a[n-3], this time we fixed three bits to 011
 * 4) string of length n ending with a 111, the number of such strings which
 * have three bits set is 2^(n-3) because now remaining (n-3) bits can be anything
 * so it follows that a[n] = a[n-1] + a[n-2] + a[n-3] + 2^(n-3)
 */
long long N;
long long PRIME = 1000000007;
long long initmat[4][4]={
                           {1,1,1,1},
                           {1,0,0,0},
                           {0,1,0,0},
                           {0,0,0,2}
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
void printBase(){
#ifdef MY_DEBUG
  printf("----Base -----\n");
   for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
          printf("%10lld  ",base[i][j]);
       }
    printf("\n");
   }
  
#endif
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
void baseWithResult1(){




    tmp[2][0] = ((base[2][0]*result[0][0])%PRIME   +  ((base[2][1]*result[1][0])%PRIME + (base[2][2]*result[2][0])%PRIME)%PRIME)%PRIME;
    tmp[2][1] = ((base[2][0]*result[0][1])%PRIME   +  ((base[2][1]*result[1][1])%PRIME + (base[2][2]*result[2][1])%PRIME)%PRIME)%PRIME;
    tmp[2][2] = ((base[2][0]*result[0][2])%PRIME   +  ((base[2][1]*result[1][2])%PRIME + (base[2][2]*result[2][2])%PRIME)%PRIME)%PRIME;
   
    // last column
    tmp[0][3] = ((((base[0][0]*result[0][3])%PRIME + (base[0][1]*result[1][3])%PRIME)%PRIME + (base[0][2]*result[2][3])%PRIME)%PRIME + (base[0][3]*result[3][3])%PRIME)%PRIME;
    tmp[1][3] = ((((base[1][0]*result[0][3])%PRIME + (base[1][1]*result[1][3])%PRIME)%PRIME + (base[1][2]*result[2][3])%PRIME)%PRIME + (base[1][3]*result[3][3])%PRIME)%PRIME;
    tmp[2][3] = ((((base[2][0]*result[0][3])%PRIME + (base[2][1]*result[1][3])%PRIME)%PRIME + (base[2][2]*result[2][3])%PRIME)%PRIME + (base[2][3]*result[3][3])%PRIME)%PRIME;

    tmp[1][2] = tmp[2][0];//((base[1][0]*result[0][2])%PRIME   +  ((base[1][1]*result[1][2])%PRIME + (base[1][2]*result[2][2])%PRIME)%PRIME)%PRIME;
    tmp[1][0] = (tmp[1][2]+tmp[2][1])%PRIME;// ((base[1][0]*result[0][0])%PRIME   +  ((base[1][1]*result[1][0])%PRIME + (base[1][2]*result[2][0])%PRIME)%PRIME)%PRIME;
    tmp[1][1] = (tmp[1][2]+tmp[2][2])%PRIME ;//((base[1][0]*result[0][1])%PRIME   +  ((base[1][1]*result[1][1])%PRIME + (base[1][2]*result[2][1])%PRIME)%PRIME)%PRIME;
    
    tmp[0][2] = tmp[1][0];//((base[0][0]*result[0][2])%PRIME   +  ((base[0][1]*result[1][2])%PRIME + (base[0][2]*result[2][2])%PRIME)%PRIME)%PRIME;
    tmp[0][0] = (tmp[0][2]+tmp[1][1])%PRIME;//((base[0][0]*result[0][0])%PRIME   +  ((base[0][1]*result[1][0])%PRIME + (base[0][2]*result[2][0])%PRIME)%PRIME)%PRIME;
    tmp[0][1] = (tmp[0][2]+tmp[1][2])%PRIME;//((base[0][0]*result[0][1])%PRIME   +  ((base[0][1]*result[1][1])%PRIME + (base[0][2]*result[2][1])%PRIME)%PRIME)%PRIME;


    result[0][0] = tmp[0][0]; result[0][1]=tmp[0][1]; result[0][2]=tmp[0][2];
    result[1][0] = tmp[1][0]; result[1][1]=tmp[1][1]; result[1][2]=tmp[1][2];
    result[2][0] = tmp[2][0]; result[2][1]=tmp[2][1]; result[2][2]=tmp[2][2];
    result[0][3]= tmp[0][3]; result[1][3]=tmp[1][3]; result[2][3] = tmp[2][3];
    result[3][3] = (base[3][3]*result[3][3])%PRIME;
     
}
void baseWithBase1(){




    tmp[2][0] = ((base[2][0]*base[0][0])%PRIME   +  ((base[2][1]*base[1][0])%PRIME + (base[2][2]*base[2][0])%PRIME)%PRIME)%PRIME;
    tmp[2][1] = ((base[2][0]*base[0][1])%PRIME   +  ((base[2][1]*base[1][1])%PRIME + (base[2][2]*base[2][1])%PRIME)%PRIME)%PRIME;
    tmp[2][2] = ((base[2][0]*base[0][2])%PRIME   +  ((base[2][1]*base[1][2])%PRIME + (base[2][2]*base[2][2])%PRIME)%PRIME)%PRIME;
   
    // last column
    tmp[0][3] = ((((base[0][0]*base[0][3])%PRIME + (base[0][1]*base[1][3])%PRIME)%PRIME + (base[0][2]*base[2][3])%PRIME)%PRIME + (base[0][3]*base[3][3])%PRIME)%PRIME;
    tmp[1][3] = ((((base[1][0]*base[0][3])%PRIME + (base[1][1]*base[1][3])%PRIME)%PRIME + (base[1][2]*base[2][3])%PRIME)%PRIME + (base[1][3]*base[3][3])%PRIME)%PRIME;
    tmp[2][3] = ((((base[2][0]*base[0][3])%PRIME + (base[2][1]*base[1][3])%PRIME)%PRIME + (base[2][2]*base[2][3])%PRIME)%PRIME + (base[2][3]*base[3][3])%PRIME)%PRIME;

    tmp[1][2] = tmp[2][0];//((base[1][0]*base[0][2])%PRIME   +  ((base[1][1]*base[1][2])%PRIME + (base[1][2]*base[2][2])%PRIME)%PRIME)%PRIME;
    tmp[1][0] = (tmp[1][2]+tmp[2][1])%PRIME;// ((base[1][0]*base[0][0])%PRIME   +  ((base[1][1]*base[1][0])%PRIME + (base[1][2]*base[2][0])%PRIME)%PRIME)%PRIME;
    tmp[1][1] = (tmp[1][2]+tmp[2][2])%PRIME ;//((base[1][0]*base[0][1])%PRIME   +  ((base[1][1]*base[1][1])%PRIME + (base[1][2]*base[2][1])%PRIME)%PRIME)%PRIME;
    
    tmp[0][2] = tmp[1][0];//((base[0][0]*base[0][2])%PRIME   +  ((base[0][1]*base[1][2])%PRIME + (base[0][2]*base[2][2])%PRIME)%PRIME)%PRIME;
    tmp[0][0] = (tmp[0][2]+tmp[1][1])%PRIME;//((base[0][0]*base[0][0])%PRIME   +  ((base[0][1]*base[1][0])%PRIME + (base[0][2]*base[2][0])%PRIME)%PRIME)%PRIME;
    tmp[0][1] = (tmp[0][2]+tmp[1][2])%PRIME;//((base[0][0]*base[0][1])%PRIME   +  ((base[0][1]*base[1][1])%PRIME + (base[0][2]*base[2][1])%PRIME)%PRIME)%PRIME;


    base[0][0] = tmp[0][0]; base[0][1]=tmp[0][1]; base[0][2]=tmp[0][2];
    base[1][0] = tmp[1][0]; base[1][1]=tmp[1][1]; base[1][2]=tmp[1][2];
    base[2][0] = tmp[2][0]; base[2][1]=tmp[2][1]; base[2][2]=tmp[2][2];
    base[0][3]= tmp[0][3]; base[1][3]=tmp[1][3]; base[2][3] = tmp[2][3];
    base[3][3] = (base[3][3]*base[3][3])%PRIME;
     
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
long long solve(){
if(N<3) return 0;
 if(N==3) return 1;
 raisePow1(N-2);
   return result[0][3]%PRIME; 
}
 int main(){
 /*  for(int i=1;i<=16;i++){
       raisePow(i);
     printf("pow %d \n",i);
       printResult();     
     printf("Again \n");
      raisePow1(i);
    printResult();
   }*/
     int T;
     scanf("%d",&T);
     while(T-->0){
         scanf("%lld",&N);
         printf("%lld\n",solve());
     }
 
 }
