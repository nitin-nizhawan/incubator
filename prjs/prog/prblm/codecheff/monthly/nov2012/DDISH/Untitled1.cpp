#include<stdio.h>

void msrtcpy(char *s,char *t){
      while(*t=*s){s++;t++;}
}
int main(){
    char name[]="Ritin";
    
    char target[20];
    
    msrtcpy(name,target);    
    
    printf("%s\n",target);
    
    getch();
}
