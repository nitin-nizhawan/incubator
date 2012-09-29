#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<map>
using namespace std;
map<long long,int> mymap;
int rSpeed(){
    return rand()%180 + 1;
}
long long packit(long long p1,long long p2,long long p3,long long p4,long long p5){
    long long ret=0;
    ret=p1;
    ret|=(p2<<9);
    ret|=(p3<<18);
    ret|=(p4<<27);
    ret|=(p5<36);
    return ret;
}
int main(){
     srand ( time(NULL) );
   long long  sp1 = rSpeed();
   long long  sp2 = rSpeed();
   long long  sp3 = rSpeed();
   long long  sp4 = rSpeed();
   long long  sp5 = rSpeed();
   long long count=1;
   long long pos1,pos2,pos3,pos4,pos5;
   pos1=pos2=pos3=pos4=pos5=0;
   int mcount=0;
   while(true){
       long long packed = packit(pos1,pos2,pos3,pos4,pos5);
       if(mymap[packed]!=1){
           mymap[packed]=1;
           mcount++;
       } else {
           printf("Count = %d\n",mcount);
           return 0;
       }
       printf("%lld\n",packed);
       pos1+=sp1; pos1=pos1%360;
       pos2+=sp2; pos2=pos2%360;
       pos3+=sp3; pos3=pos3%360;
       pos4+=sp4; pos4=pos4%360;
       pos5+=sp5; pos5=pos5%360;
   }

}
