#include<stdio.h>
char lbuff[200],hbuff[200];
long long hn,ln;
int llen,hlen;

int getdigit(long long n,int len,int i){
    int ri = len-i-1;
    if(ri<0){
        int doi=0;
        int pi = 1/doi;
    }
     long long pow10 = 1;
     for(int i=0;i<ri;i++){
         pow10=10*pow10;
     }
     return (n/pow10)%10;
}
long long floorit(long long n, int len, int i){
    int ri = len -i -1;
    if(ri<0){
        int doi = 0;
        int pi = 1/doi;
    }
    long long pow10 =1 ;
    for(int i=0;i<ri;i++){
        pow10 = pow10*10;
    }
    return (n/pow10)*pow10;
}
long long cielit(long long n,int len,int i1){
    int ri=len -i1 -1;
    if(ri<0){
        int doi=0;
        int pi=1/doi;
    }
    long long tmp = n;
    int len1=0;
    while(tmp>0){
        len1++;
        tmp/=10;
    }
    long long pow10 =1;
    long long s9 =9;
    for(int i=0;i<ri;i++){
        pow10 = 10*pow10;
        if(i<(ri-1)&&i<(len1-1)){
            s9 = s9*10+9;
        }
    }
    if(i1==len-1){
        s9=0;
    }
    return floorit(n,len,i1) + s9;
}

/*
int solve(int pos,int c4,int c7){
    if(pos>=hlen){
        return c4*c7;
    }
    if(lbuff[pos]==hbuff[pos]){
        if(lbuff[pos]=='4'){
            return solve(pos+1,c4+1,c7);
        } else if(lbuff[pos]=='7'){
            return solve(pos+1,c4,c7+1);
        } else {
            return solve(pos+1,c4,c7);
        }
    }
    if(lbuff[pos]+1==hbuff[pos]){

    }

}*/
int solve(int pos,int c4, int c7){
    if(pos>=hlen){
        return c4*c7;
    }
    int chd = getdigit(hn,hlen,pos);
    int cld = getdigit(ln,hlen, pos);
    if(chd==cld){
        if(cld==4){
            return solve(pos+1,c4+1,c7);
        } else if(cld==7){
            return solve(pos+1,c4,c7+1);
        } else {
            return solve(pos+1,c4,c7);
        }
    }
    int max  =0;

}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
       /* scanf("%s",lbuff);
        scanf("%s",hbuff);
        llen=0;hlen=0;
        while(lbuff[llen]!='\0') llen++;
        while(hbuff[hlen]!='\0') hlen++;
        for(int i=hlen;i>=0;i--){
            if((i-(hlen-llen))>=0){
                lbuff[i]=lbuff[i-(hlen-llen)];
            } else {
                lbuff[i]='0';
            }
        }*/
        scanf("%lld",&hn);
        scanf("%lld",&ln);
        long long tmp=hn;
        hlen=0; whlile(tmp>0){ hlen++; tmp/=10; };
        tmp = ln; llen =0; while(tmp>0){llen++; tmp/=10};
        printf("%d\n",solve(0,0,0));
    }
}
