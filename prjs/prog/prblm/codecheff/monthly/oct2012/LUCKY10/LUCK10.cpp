#include<stdio.h>
char A[20005];
char B[20005];
int Acnt[200019];
int Bcnt[200019];
int tc=0;
void input(){
    scanf("%s",A);
    scanf("%s",B);
    int i=0;
   int t = tc*10;
    while(A[i]!='\0'){
	Acnt[t+A[i]-'0']++;
	Bcnt[t+B[i]-'0']++;
	i++;
    }
    // see how many 7s you can get
   int cp=t+6;
   int ct=t+7;
   while(Acnt[ct]>0&&cp>=t){
       if(Bcnt[cp]>0){
         Bcnt[cp]--;
         Acnt[ct]--;
         printf("7");
       } else {
         cp--;
         if(cp==t+4) cp--; // skip 4
       }
    } 
    while(Acnt[ct]>0&&Bcnt[t+4]){
        Acnt[ct]--;Bcnt[t+4]--;printf("7");
    }
    cp=t+7;ct=t+7;
    while(Bcnt[ct]>0&&cp>=t){
       if(Acnt[cp]>0){
         Acnt[cp]--;
         Bcnt[ct]--;
         printf("7");
       } else {
         cp--; if(cp==t+4) cp--; //skip 4
       }
   } 
    while(Bcnt[ct]>0&&Acnt[t+4]){
        Bcnt[ct]--;Acnt[t+4]--;printf("7");
    }
   cp=t+3;ct=t+4;
   while(Acnt[ct]>0&&cp>=t){
       if(Bcnt[cp]>0){
         Bcnt[cp]--;
         Acnt[ct]--;
         printf("4");
       } else {
         cp--;
       }
   } 
   cp=t+4;ct=t+4;
   while(Bcnt[ct]>0&&cp>=t){
       if(Acnt[cp]>0){
         Acnt[cp]--;
         Bcnt[ct]--;
         printf("4");
       } else {
         cp--;
       }
   } 
   printf("\n");
tc++;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T-->0){
      input();
    }
}
