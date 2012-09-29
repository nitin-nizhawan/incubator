#include<stdio.h>
char inpbuff[10005];
int INFINITY=1<<25;
unsigned long long intstr[2000];
int lcp[1005][1005];
int CNT,LEN;
int min1(int a,int b){
    return a<b?a:b;
}
int max1(int a,int b){
    return a<b?a:b;
}
int getlcp(int s,int t){
    if(s==t){
        return N-max1(t,s);
    }
    int lcpv = 10*lcp[s][t];
    int retVal = lcpv;
    int maxidx = max1(s,t);
    int diff = maxidx - min(s,t);
    for(int i=maxidx+lcpv;i<maxidx+lcpv+10&&i<LEN;i++){
        if(inpstr[i]==inpstr[i-diff]){
            retVal++;
        } else {
            break;
        }
   }
   return retVal;
}
int minstr(int a, int b){
    int lcp1 = getlcp(a,b);
    if(lcp1<(LEN-b)){
    } else {
    }
    int lcp2 = getlcp(0,b-a);
    int lcp3 = getlcp(0,b);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",inpbuff);
        cnt=0;
        LEN=0;
        while(inpbuff[LEN]!='\0'){
            intstr[cnt]=0;
            for(int j=0;j<10&&inpbuff[LEN]!='\0';j++,LEN++){
                intstr[cnt]=intstr[cnt]*27+(inpstr[LEN]-'a'+1);
            }
            cnt++;
        }
        for(int i=0;i<CNT;i++) lcp[i][i]=0;
        for(int i=CNT-1;i>0;i--){
            for(int diff=1;diff<CNT;diff++){
                if(i-diff>=0){
                    if(intstr[i]!=intstr[i-diff]){
                        lcp[i][i-diff]=0;
                        lcp[i-diff][i]=0;
                    } else if(i+1<CNT) {
                        lcp[i][i-diff]=lcp[i+1][i-diff+1]+1;
                        lcp[i-diff][i]=lcp[i-diff+1][i+1];
                    } else {
                        lcp[i][i-diff]= 1; 
                        lcp[i-diff][i]= 1;
                    }
                }
            }
        }
        int min=0;
        for(int i=1;i<LEN;i++){
            min = minstr(min,i); 
        }
        printf("%d\n",min+1);
    }
}
