#include<cstdio>
typedef int type_int;
void inputProb(){
   type_int curt = 0;
   type_int n,m,t;
   scanf("%d %d %d",&n,&t,&m);
   type_int sttime;
   type_int tm = 0;
   type_int backlog=0;
   type_int trips=0;
   for(int i=0;i<m;i++){
       scanf("%d",&sttime);
       backlog++;
       if(sttime>=tm){
       // make a trip 
           if(backlog<n){
              // backlog=0;
              // tm=sttime+2*t; //next availablity;
           } else {
           trips++;
               backlog-=n;
               tm=sttime+2*t;
           }
               
       }
//      printf("{%d %d %d}\n",sttime, backlog,tm);
   }
   while(backlog>0){
       trips++;
       backlog-=n;
       tm+=2*t;
   }
   if(tm>0) tm = tm - t;
   printf("%d %d\n",sttime+t,trips);
}
void solveProb(){
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        inputProb();
        solveProb();
    }
}
