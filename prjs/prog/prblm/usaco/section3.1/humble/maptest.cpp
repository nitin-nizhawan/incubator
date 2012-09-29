#include<map>
#include<stdio.h>
using namespace std;


int main(){


   map<int,int> mymap;


   mymap[2]=13;
   mymap[7]=29;

   for(int i=0;i<10;i++){
       printf("%d ",mymap[i]);
   }

}
