#include<stdio.h>

typedef unsigned long long ull;
typedef long long lld;

ull factorials[] ={1,1,2,6,24,120, 720, 5040, 40320, 362880, 128737, 416089, 492987, 408723, 222023, 330291, 284566, 337541, 75630, 436952, 238887, 16537, 363814, 367578, 321719, 42831, 113588, 66822, 370989, 258492, 254625, 393240, 83455, 253970, 134827, 218864, 378969, 21601, 320829}; 
ull MOD = 500009;
int num_factors(int n){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            ans++;
        }
    }
    return ans;
}
ull calcAns(ull bucket[],ull size){
    ull ans=1;
    for(int i=0;i<size;i++){
        ans = (ans*factorials[bucket[i]])%MOD;
    }
    return ans%MOD;
}
int main(){
    int N,A=400;
    ull pans=1;
//    scanf("%d",&A);
    for(int N=1;N<=A;N++){
        ull bucket[40];
        for(int i=0;i<40;i++){
            bucket[i]=0;
        }
        int max = 1;
        for(int i=1;i<=N;i++){
            int num = num_factors(i);
            if(num>max){
                max=num;
            }
            bucket[num-1]++;
        }
        ull ans = calcAns(bucket,max);
        int k=-1;
        
        for(int z=1;z<=40;z++){
            if(ans == ((pans*z)%MOD)){
                k=z;
                break;
            }
        }
        printf("%d %llu %d",N,calcAns(bucket,max),k);
        pans = ans;
        printf("\n");
    }
}
