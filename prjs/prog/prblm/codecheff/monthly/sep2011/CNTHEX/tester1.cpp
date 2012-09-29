#include<stdio.h>
#include<stdlib.h>

//////////////////////////// UTIL COMMON ////////////////////////
int min(int a , int b){
  return a<b?a:b;
}



////////////////////////////// INVALID HEXAGONS WITH K=5 ///////////////////////////////////////

int bruteforce_invalidHex_k_5(int X,int L){
   int count=0;
   for(int i=1;i<=X;i++){
      if((5*i)<=L){
          count++;
//          printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,i,i,i);
      }
   }
   return count;
}
int fast_invalidHex_k_5(int X,int L){
   return min(L/5,X);
}
void test_invalidHex_k_5(){
int T=750;
int d=0;
  while(T--){
  int X=rand()%150;
  int L = X+1+rand()%150;
   if(fast_invalidHex_k_5(X,L)!=bruteforce_invalidHex_k_5(X,L)){
      d+=(fast_invalidHex_k_5(X,L)-bruteforce_invalidHex_k_5(X,L));
      printf("invalidHex_k_5 Testfailed(X=%d,L=%di)\n",X,L);
   }
 }
  printf("Total Diff %d\n",d);
  
}

/////////////////////////// INVALID HEXAGONS WITH K=4 //////////////////////////////

int bruteforce_invalidHex_k_4(int X,int L){
      int count=0;
    for(int i=1;i<=X;i++){
    
      for( int j=i+1;j<=X;j++){
          if((4*i+j)<=L){
              count++;
  //            printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,i,i,j);
          }
          if((i+4*j)<=L){
              count++;
    //          printf("%d. {%d,%d,%d,%d,%d}\n",count,i,j,j,j,j);
          }
      }
   }
   return count;

}
int fast_invalidHex_k_4(int X,int L){
 int D1 = (L-X)/4;
 int R1 = (L-X)%4;
 int D2 = (L-1)/4;
 int R2 = (L-1)%4;
 int C1 = D1*(4-R1);
 int C2 = (R2+1)*D2;
 int s1 = (D1*(D1+1))/2;
 int s2 = (D2*(D2-1))/2;
 int C3 = 4*(s2-s1);
 if(X<=4){
  int sum=0;
  for(int i=X;i>0;i--){
      sum+=min(X,((L-i)/4));
  }
  sum = sum - min(L/5,X);
  return sum;
 } else if(((L-1)/4)<=X){ 
    return C1+C2+C3-min(L/5,X);
 } else if(((L-X)/4)>=X){
    return X*X - min(L/5,X);
 } else {
    // the case where (L-a)/4 is greater than X lies somewhere in between (L-1) and (L-X)  
    int dg = (L-(X+1)*4 )*X;
    int s3  = ((X+1)*X)/2;
    int C4 = 4*(s3-s1);
    return C1+C4 + dg - min(L/5,X);
 } 
 
}
int test_invalidHex_k_4(){
int T=780;
int d=0;
  while(T--){
  int X=rand()%500;
  int L = X+1+rand()%500;
//if((X<=4)||(((L-1)/4)<=X)||( ( (L-X)/4   )>=X   ) ) {} else {continue;}
   if(fast_invalidHex_k_4(X,L)!=bruteforce_invalidHex_k_4(X,L)){
      d+=(fast_invalidHex_k_4(X,L)-bruteforce_invalidHex_k_4(X,L));
      printf("invalidHex_k_4 Testfailed(X=%d,L=%d)\n",X,L);
   }
 }
  printf("Total Diff %d\n",d);

}


/////////////////////////// INVALID HEXAGONS WITH K=3 //////////////////////////////

int bruteforce_invalidHex_k_3(int X,int L){
int count=0;    
  for(int i=1;i<=X;i++){
       for(int j=i+1;j<=X;j++){
           for(int k=j+1;k<=X;k++){
	           if((3*i+j+k)<=L){
                       count++;
//                       printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,i,j,k);
                   }
	           if((i+3*j+k)<=L){
                       count++;
  //                     printf("%d. {%d,%d,%d,%d,%d}\n",count,i,j,j,j,k);
                   }
	           if((i+j+3*k)<=L){
                       count++;
    //                   printf("%d. {%d,%d,%d,%d,%d}\n",count,i,j,k,k,k);
                   }
           }
       }
   }

   for(int i=1;i<=X;i++){
    
      for( int j=i+1;j<=X;j++){
          if((3*i+2*j)<=L){
              count++;
      //        printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,i,j,j);
          }
          if((2*i+3*j)<=L){
              count++;
        //      printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,j,j,j);
          }
      }
   }

 return count;
}


int fast_invalidHex_k_3(int X,int L){

int imax = min(X,(L-2)/3); printf("sdsd");
int sum = 0;
for(int i=1;i<=imax;i++){
  int L_minus_3i = L-3*i;
  int L_minus_3i_by_2 = L_minus_3i/2;
  int minn = min(L_minus_3i_by_2,X);
  sum+= (minn*(minn+1))/2;
  if(X>L_minus_3i_by_2){
      sum+=  min(X,L)-L_minus_3i_by_2;
  }
}
return sum;


/* 
int x = (L-2)/3;
int y = 3*x+1;
return (x*(x+1)*(x+2))/6;
*/
// aaabb type
   
}
int test_invalidHex_k_3(){
int T=50;
int d=0;
  while(T--){
  int X=rand()%500;
  int L = X+1+rand()%500;
   int imax = (L-2)/3;
//   if(X<((L-3*imax)/2))
   int f = fast_invalidHex_k_3(X,L);
   int b = bruteforce_invalidHex_k_3(X,L);
   if(f!=b){
      d+=(f-b);
      printf("invalidHex_k_3 Testfailed(X=%d,L=%d)(F=%d,B=%d)\n",X,L,f,b);
   }
 }
  printf("Total Diff %d\n",d);

}
int main(){

  
test_invalidHex_k_3();
test_invalidHex_k_4();
test_invalidHex_k_5();


}
