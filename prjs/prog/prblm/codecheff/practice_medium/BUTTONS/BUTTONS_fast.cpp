#include<stdio.h>
bool mat[1000][1000];
int size;
int noPatterns;
int noAntiPatterns;
int noPatternBits;
bool patternRow[1000];
void solve(){
   noPatterns=1;
   noAntiPatterns=0;
   noPatternBits=0;
   patternRow[0]=true;
   for(int i=1;i<size;i++){
       bool equal=(mat[i][0]==mat[0][0]);
       for(int j=1;j<size;j++){
           if(equal!=(mat[i][j]==mat[0][j])){
               printf("%d\n",-1);
               return;
           }
       }
       if(equal){
           noPatterns++;
           patternRow[i]=true;
       } else {
           noAntiPatterns++;
           patternRow[i]=false;
       }
   }
   for(int j=0;j<size;j++){
       if(mat[0][j]){
           noPatternBits++;
       }
   }

   if((noPatterns + size - noPatternBits)<(noAntiPatterns+noPatternBits)){
       printf("%d\n",noPatterns);
       for(int i=0;i<size;i++){
           if(patternRow[i]){
               printf("%d\n",i);
           }
       }
       printf("%d\n",size-noPatternBits);
       for(int i=0;i<size;i++){
          if(!mat[0][i]){
              printf("%d\n",i);
          }
       }
   } else {
       printf("%d\n",size-noPatterns);
       for(int i=0;i<size;i++){
           if(!patternRow[i]){
               printf("%d\n",i);
           }
       }
       printf("%d\n",noPatternBits);
       for(int i=0;i<size;i++){
           if(mat[0][i]){
               printf("%d\n",i);
           }
       }
   }
}
int main(){
    int T,tmp;
    unsigned char tmpc;
    scanf("%d",&T);
    while(T--){
       scanf("%d",&size);
       for(int i=0;i<size;i++){
           for(int j=0;j<size;j++){
             scanf("%d",&tmp);
             mat[i][j]=(tmp>0?true:false);
           }
       }
       bool isdiff =  false;
       for(int i=0;i<size;i++){
           for(int j=0;j<size;j++){
               scanf("%d",&tmp);
               tmpc = (tmp>0)?true:false;
               mat[i][j]= (mat[i][j]==tmpc)?false:true;
               isdiff = isdiff || mat[i][j];
           }
       }
       if(!isdiff){
           printf("0\n");
       } else {
           solve();
       }
    }
}
