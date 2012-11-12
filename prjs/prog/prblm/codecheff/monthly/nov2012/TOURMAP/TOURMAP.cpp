#include<stdio.h>

int gi(char* s){
    int p=0;
    int ans=0;
    while(*s!='$'){
       ans =ans*10 + (*s - '0');            
       s++;
    }
    return ans;
}
 char names[5005][100]
     int nc=0;
     int addtolist(char * b){
          
     }
int main(){
     int T;
     char fst[100];
     char sec[100];
     char val[100];
    
     int vali;
     scanf("%d",&T);
     while(T-->0){
         int N;
         scanf("%d",&N);
         long long ans=0;
         int f,s;
         for(int i=0;i<N-1;i++){
             scanf("%s",fst);
             scanf("%s",sec);
             scanf("%s",val);
             ans+ = gi(val);
             f=addtolist(fs);
             s=addtolist(fs);
             
         }
         printf("%d$\n",ans);
     }
     return 0;
}
