#include<stdio.h>
int n;
int nums[50];
bool isMagicNum(int num){
    if(!num){
        return false;
    }
    while(num){
        int d = num%10;
        if(d!=4&&d!=7){
            return false;
        }
        num/=10;
    }
    return true;
}
int addMagic(int res, int num){
    int cp1 = res;
    int cp2 = num;
    int ret1=0;
    while(cp1||cp2){
        int d1 = cp1%10;
        int d2 = cp2%10;
        ret1 = ret1*10 + (d1>d2?d1:d2);
        cp1/=10;
        cp2/=10;
    }
    int ret=0;
    while(ret1){
        ret = ret*10 + ret1%10;
        ret1/=10;
    }
    return ret;
}
bool isMagic(long long mask){
    int res=0;
    for(int i=0;i<n;i++){
        if(mask&(1<<i)){
            res = addMagic(res,nums[i]);
        }
    }
    return isMagicNum(res);
}
void brute_force(){
    long long mask=0;
    long ans=0;
    while(!(((mask-1)&mask)&&(mask&1<<n))){
        if(isMagic(mask)){
            ans++;
        }
        mask++;
    }
    printf("%ld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
        }
        brute_force();
    }
}
