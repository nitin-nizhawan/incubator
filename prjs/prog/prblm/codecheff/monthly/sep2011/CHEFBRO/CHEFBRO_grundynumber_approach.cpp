#include<stdio.h>
#include<stdlib.h>
int n[20];
int m[20];
int C;

bool isWinnerUsingGrundy(int C, int n[], int m[]){
  unsigned int num = 0;
   for(int i=0;i<C;i++){
       num^=((n[i]+m[i]-2)%3);
   }
   return (num>0);
}
bool isWinnerUsingFormula(int C,int n[],int m[]){
   int f=0;
   for(int i=0;i<C;i++){
       if((n[i]+m[i]-2)%3) f++;
   }
   return f%2;
}
int main(){
   int T=40;
   while(T--){
       int C = (rand()%2)+1;
       for(int i=0;i<C;i++){
           n[i]=(rand()%4)+2;
           m[i]= (rand()%4)+2;
       }
       if(isWinnerUsingGrundy(C,n,m)!=isWinnerUsingFormula(C,n,m)){
           printf("Mistake %d,[ [%d,%d]",C,n[0],m[0]);
           for(int i=1;i<C;i++){
               printf(",[%d,%d]",n[i],m[i]);
           }
           printf("  ]\n");
       }
   } 
}
