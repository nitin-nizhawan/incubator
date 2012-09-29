#include<stdio.h>
#include<stdlib.h>


int main(int argc, char* argv[]){

   int T = atoi(argv[1]);
   int N=atoi(argv[2]);
   int V = atoi(argv[3]);
  
   printf("%d\n",T);
   while(T--){
       printf("%d\n",N);
       for(int i=0;i<N;i++){
          if(i>0){
              printf(" ");
          } 
          printf("%d",rand()%V + 1);
       }
       printf("\n");
   }


}
