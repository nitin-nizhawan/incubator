#include<stdio.h>
#include<stdlib.h>
void testcasegen(){
   int MAX_K = 50;
   int MAX_N = 100;
   int examples = MAX_K;
   int n=1;
   int maxcount=0;

        FILE *fp2 = fopen("nvsans.txt","w");
          fprintf(fp2,"X\tY\n");
   while(examples--){
     
       //int n = rand()%MAX_N;
       int k = MAX_K;//(rand()%(MAX_K-MAX_N-1)) + MAX_N+1;
       char flname[40];
       sprintf(flname,"data(%d,%d).txt",n,k);
  //     FILE *fp = fopen(flname,"w");
         
       int count=0;
    //   fprintf(fp,"X,Y\n");
       printf("Example (n=%d , k=%d)\n", n,k);
       for(int a=n+1;a<k;a++){
           for(int b=n+1;b<k;b++){
               if((a*b-n)%((a-n)*(b-n))==0){
                   count++;
        //           if(a<=b)
      //             fprintf(fp,"%d\t%d\n",a-n,b-n);
                   //if(a<=b){
                    //   printf("%d\t%d\n",a-n,b-n);
                  // }
               }
           }
       }
       fprintf(fp2,"%d\t%d\n",n,count);
       n++;
       maxcount = count>maxcount?count:maxcount;
     printf("\nMAX COUNT %d\n",maxcount);  
  //     fclose(fp);
       printf("\n Answer : %d\n",count);
       
   }
       fclose(fp2);
}
int main(){
   testcasegen();
}


