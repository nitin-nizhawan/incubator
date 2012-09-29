#include<cstdio>

typedef long long ll;
struct Point{
   ll l;
   ll r;
   bool operator>(struct Point & p){
       if(l>p.l){
           return true;
       } else if (l==p.l){
           if(r>p.r){
               return true;
           } else {
               return false;
           }
       } else {
          return false;
       }
   }
}points[100000];
ll count;
ll M;
void fixHeap(int i,int size){
 while(i<size){
    int largest = i;
    if(LEFT(i)<size&&points[LEFT(i)]>points[largest]){
        largest = LEFT(i);
    } 
    if(RIGHT(i)<size&&points[RIGHT(i)]>points[largest]){
        largest = RIGHT(i);
    }
    if(larest!=i){
       int tmp = points[i];
       points[i] = points[largest];
       points[largest] = tmp;
       i = largest; 
    } else {
        break;
    }
 }
}
void sortPoints(){
    for(int i=(count-1)/2;i>=0;i--){
        fixHead(i,count);
    }
    int size = count;
    for(int i=0;i<count;i++){
        struct Point tmp;
        tmp = points[0];
        points[0] = points[size-1];
        points[size-1]=tmp;
        fixHeap(0,size-1);
        size--;
    }
}
void inputProb(){
   scanf("%llu",&M);
   ll l=1,r=1;
   count=0;
   while(true){
       scanf("%ld %ld",&l,&y);
       if(l==0&&y==0){
           break;
       }
       points[count].l=l;
       points[count++].r=r;
   }
  
}
void solveProb(){
   sortPoints();
   ll left=0;
   for(int i=0;i<count;i++){
       if(points[i].l<=
   }
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
      inputProb();
      solveProb();
  }  
}
