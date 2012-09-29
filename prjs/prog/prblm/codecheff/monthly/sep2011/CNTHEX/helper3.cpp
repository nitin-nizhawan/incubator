// generate all possible invalid hexagons using brute force


#include<stdio.h>
int min(int a, int b){
    return ((a<b)?a:b);
}
int fk1(int X,int L){
  int count=0;
   for(int i=1;i<=X;i++){
       for(int j=i+1;j<=X;j++){
           for(int k=j+1;k<=X;k++){
               for(int l=k+1;l<=X;l++){
                  for(int m=l+1;m<=X;m++){
                      if((i+j+k+l+m)>L){
                          count++;
                          //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,j,k,l,m);
                      }
                  }
               }
           }
       }
   }  
  return count;
}
int fk2(int X,int L){
 int count=0;
   for(int i=1;i<=X;i++){
       for(int j=i+1;j<=X;j++){
           for(int k=j+1;k<=X;k++){
               for(int l=k+1;l<=X;l++){
	           if((2*i+j+k+l)>L){
                       count++;
                       //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,j,k,l);
                   } 
                   if((i+2*j+k+l)>L){
                       count++;
                       //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,j,j,k,l);
                   } 
                   if((i+j+2*k+l)>L){
                       count++;
                       //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,j,k,k,l);
                   }
                   if((i+j+k+2*l)>L){
                       count++;
                       //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,j,k,l,l);
                   }
               }
           }
       }
   }
  for(int i=1;i<=X;i++){
       for(int j=i+1;j<=X;j++){
           for(int k=j+1;k<=X;k++){
	           if((2*i+2*j+k)>L){
                       count++;
                       //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,j,j,k);
                   } 
                   if((2*i+j+2*k)>L){
                       count++;
                       ////printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,j,k,k);
                   }
                   if((i+2*j+2*k)>L){
                       count++;
                       //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,j,j,k,k);
                   }
           }
       }
   }


 return count;
}

int fk3(int X,int L){
int count=0;    
  for(int i=1;i<=X;i++){
       for(int j=i+1;j<=X;j++){
           for(int k=j+1;k<=X;k++){
	           if((3*i+j+k)>L){
                       count++;
                       //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,i,j,k);
                   }
	           if((i+3*j+k)>L){
                       count++;
                       //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,j,j,j,k);
                   }
	           if((i+j+3*k)>L){
                       count++;
                       //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,j,k,k,k);
                   }
           }
       }
   }

   for(int i=1;i<=X;i++){
    
      for( int j=i+1;j<=X;j++){
          if((3*i+2*j)>L){
              count++;
              //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,i,j,j);
          }
          if((2*i+3*j)>L){
              count++;
              //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,j,j,j);
          }
      }
   }

 return count;
}


int fk4(int X,int L){
   int count=0;
    for(int i=1;i<=X;i++){
    
      for( int j=i+1;j<=X;j++){
          if((4*i+j)>L){
              count++;
              //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,i,i,j);
          }
          if((i+4*j)>L){
              count++;
              //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,j,j,j,j);
          }
      }
   }
 int D1 = (L-X)/4;
 int R1 = (L-X)%4;
 int D2 =  (L-1)/4;
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
  //printf("Estimate: %d",sum);
 } else {
 //printf("Estimate(C1:%d,C2:%d,C3:%d): %d",C1,C2,C3,((C1+C2+C3-min(L/5,X))));
 }
 return count;
}


int fk5(int X,int L){
    int count=0;
   for(int i=1;i<=X;i++){
      if((5*i)>L){
          count++;
//          //printf("%d. {%d,%d,%d,%d,%d}\n",count,i,i,i,i,i);
      }
   }
 //printf("Estimate(X:%d,L/5:%d): %d",X,L/5,min(X,L/5));
  return count;
}
int main(){
// int X = 75;
 int L=100;
 for(int i=1;i<=L;i++){
   for(int j=1;j<=i;j++){
      int  p = fk1(j,i);//+fk2(j,i);//+fk3(j,i);
      printf("X=%d,L=%d val=%d\n",j,i,p);
   }
 }
}
