#include<cstdio>
#include<cstring>
#include<iostream>
char opStack[100];
char top=-1;
void solve(){
   char str[12];
   char c;
//   while(scanf("%s[^\n]\n",str)&&str[0]!='\n'){
while ( fgets ( str, sizeof str, stdin ) != NULL&&str[0]!='\n' ) {
         c=str[0];
//         std::cout<<strlen(str)<<std::endl;
  //       str[0]='\0';
//         printf("%s",str);;
  //       printf("ab--");
    //     printf("%d",c+0);
      //   printf("---cd");
         switch(c){
             case '0':
             case '1':
             case '2':
             case '3':
             case '4':
             case '5':
             case '6':
             case '7':
             case '8':
             case '9':
                   printf("%c",c);  break;  
             case '(':
                 opStack[++top]='('; break;
             case ')':
                 while(opStack[top]!='('){
                     printf("%c",opStack[top--]);
                 }
                 //printf("%c",opStack[top--]); 
                 top--;
                 break;
             case '*': 
             case '/':
                 while((opStack[top]=='/'||opStack[top]=='*')&&top>=0&&opStack[top]!='('){
                     printf("%c",opStack[top--]);
                 }
                 opStack[++top]=c;
                 break;
             case '+':
             case '-':
                 while(top>=0&&opStack[top]!='('){
                     printf("%c",opStack[top--]);
                 }
                 opStack[++top]=c;
                 break;
             default:
                 break;
         }
   }
   while(top>=0){
       printf("%c",opStack[top--]);
   }
   printf("\n");
}
int main(){
   int T;
   scanf("%d\n",&T);
   while(T--){
       solve();
       if(T>0){
       printf("\n"); }
   }
}
