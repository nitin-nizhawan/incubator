#include<stdio.h>
int H,W;
void strateg1(){
}
int main(){
   scanf("%d",&H);
   scanf("%d",&W);
   int n;
   int rs=0,cs=0,r[301],c[301];
   int rowsum=0,maxrowsum=0;
   int fc[301],fcs=0;
   int inp[301][301];
   for(int h=0;h<H;h++){
       for(int w=0;w<W;w++){
           scanf("%d",&n);inp[h][w]=n;
           if(n>0){
              c[cs++]=w;
              rowsum+=n;
           }
       }
      if(rowsum>maxrowsum){
          maxrowsum=rowsum;
          //r[0]=h;
          fcs = cs;
          for(int i=0;i<fcs;i++) fc[i]=c[i];
      }
      rowsum=cs=0;
   }
   rs=0;
   long long totalsum=0;
   for(int h=0;h<H;h++){
       long long sum=0;
       for(int j=0;j<fcs;j++){
           sum+=inp[h][fc[j]];
      //     if(sum<0) break;
       }
       if(sum>0){ r[rs++]=h;totalsum+=sum; }
   }
  long long colsum=0,maxcolsum=0;
  int r2[3000],c2[3000],rs2=0,cs2=0;
  int fr2[3000],frs2=0;
   for(int w=0;w<W;w++){
       colsum=0;
       for(int h=0;h<H;h++){
         if(inp[h][w]>0) { colsum+=inp[h][w];
              r2[rs2++]=h;
          }
       }
       if(colsum>maxcolsum) {
          maxcolsum=colsum; 
          frs2=rs2;
          for(int i=0;i<frs2;i++) fr2[i]=r2[i];
       }
       rs2=0;
       colsum=0;
   }
   
   long long totalsum2=0;
   for(int w=0;w<W;w++){
       long long sum=0;
       for(int j=0;j<frs2;j++){
          sum+=inp[fr2[j]][w];
       }
       if(sum>0){
          totalsum2+=sum;
          c2[cs2++]=w;
       }
   }
if(totalsum>=totalsum2){
   printf("%d %d\n",rs,fcs);
   for(int i=0;i<rs;i++){
    if(i) printf(" ");
        printf("%d",r[i]);
   }
   printf("\n");
   for(int i=0;i<fcs;i++){
       if(i) printf(" ");
       printf("%d",fc[i]);
   }
   printf("\n");
  } else {
    printf("%d %d\n",frs2,cs2);
    for(int i=0;i<frs2;i++){
	if(i) printf(" ");
	printf("%d",fr2[i]);
    }
    printf("\n");
   for(int i=0;i<cs2;i++){
        if(i) printf(" ");
        printf("%d",c2[i]);
   }
   printf("\n");
  }
   return 0;
}
