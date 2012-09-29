#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
long long T,A,B,X,Y,Z,P,C,Q;
long long L,R;
long long seq[125000];
long long ccnt[125000];
int pstart;
int pend;
vector<long long> factors;
bool checkPattern(long long start,int len,long maxcalc){
   // if(len>6*P){
//        return false;
   // }
    bool isPattern = true;
    for(int i=0;i<len;i++){
        if(seq[i]!=seq[len+i]){
            isPattern = false;
            break;
        }
    }
    return isPattern;

}
bool mcomp(long long a, long long b){
    return a>b;
}
void query(){
    //L--; R--; //make zero indexed;
    long long Plength = pend - pstart +1;
    long long leftMult = L/Plength;
    long long leftOffset = L%Plength;
    long long  rightMult = R/Plength;
    long long  rightOffset = R%Plength;
    long long  sum = 0;
    if(R<((L/Plength)+1)*Plength){ // L,R falls in same interval
          int l = (L-1+Plength)%Plength;
          int r = (R-1+Plength)%Plength;
          sum+=ccnt[r];
          if( l-1>=0){
              sum-=ccnt[l-1];
          }
    } else {
         int r = (R-1+Plength)%Plength;
         int l = (L-1+Plength)%Plength;
         sum+=ccnt[r];
         if(l-1>=0){
             sum -=ccnt[l-1];
         }
         sum+=((R/Plength)-(L/Plength))*ccnt[Plength-1];
    }
    printf("%lld\n",sum);
}
void process(){
    //identify period 
    // period is a factor of p^2 -1
    printf("A=%lld,B=%lld,X=%lld,Y=%lld,Z=%lld,P=%lld,C=%lld,Q=%lld\n",A,B,X,Y,Z,P,C,Q);
    long long p2_min_1 = P*P -1 ;
    long long i=1;
    long long maxcalc = 2*6*(P+1);
    seq[0]=A;
    seq[1]=B;
    for(int i=2;i<125000;i++){
        seq[i]= ((X*seq[i-1])%P + (Y*seq[i-2])%P + Z)%P;
    }
    bool isPattern = false;
    int numfac=0;
    while(i*i<=p2_min_1){
        if(p2_min_1%i==0){
            long long d1= p2_min_1/i;
            long long d2 = i;
            factors[numfac++]=d2;
            factors[numfac++]=d1;
        }
        i++;
    }
    sort(factors.begin(),factors.begin()+numfac, mcomp);
   // printf("numfac: %d\n",numfac);
//    if(P<=6){
        numfac = 6*P;
        int k=0;
        for(int i=6*P;i>0;i--){
            factors[k++]=i;
        }
  //  }
    /*for(int i=0;i<numfac;i++){

    } */
    for(int i=0;i<numfac;i++){
       isPattern=true;
       if(isPattern=checkPattern(0,factors[i],maxcalc)){
            pstart = 0;
            pend = factors[i]-1;
            break;
       }
    }
    if(isPattern){
        ccnt[0]=0;
        for(int i=pstart;i<=pend;i++){
            if(i>=maxcalc){
//                printf("limit");
            }
            if(seq[i]==C){
                ccnt[i]=1;
            } else {
                ccnt[i]=0;
            }
            if(i>0){
                ccnt[i]+=ccnt[i-1];
            }
        }

        
    } else {
//        exit(-1);
        int a =1;
        int b = 1/(a-1);
    }

}
bool isPrime(int n){
    if(n<2){
        return false;
    }
    if(n<4){
        return true;
    }
    int d=2;
    while(d*d<=n){
        if(n%d==0){
            return false;
        }
        if(d==2){
            d++;
        } else {
            d+=2;
        }
    }
    return true;
}
void tester(){
    P = rand()%10008;
     while(!isPrime(P)){
         P = rand()%10008;
     }
    A = rand()%P;
    B = rand()%P;
    X = rand()%P;
    Y = rand()%P;
    Z = rand()%P;
    C = rand()%P;
    Q = rand()%20000 + 1;
//    A=6483;B=4419;X=2330;Y=7258;Z=4643;P=8331;C=5056;Q=15901;
//    A=1541;B=1986;X=150;Y=1023;Z=1977;P=4651;C=4478;Q=7734;L=984579433;R=31917347041;
    process();
//    query();
    /*
    while(Q--){
        L = rand()%(1<<30);
        long long MAX = 1;
        MAX = MAX<<36;
        int ch = rand()%100;
        L = (ch>50) ? L : (L*L)%MAX;
        R = rand()%(1<<30);
        ch = rand()%100;
        R = (ch>50) ? R : (R*R)%MAX;
        if(L>R){
            long long tmp = L;
            L = R;
            R = tmp;
        }
        query();
    }*/
}
int main(){
    scanf("%lld",&T);
    factors.resize(125000);
    while(T--){
        scanf("%lld",&A);
        scanf("%lld",&B);
        scanf("%lld",&X);
        scanf("%lld",&Y);
        scanf("%lld",&Z);
        scanf("%lld",&P);
        scanf("%lld",&C);
        scanf("%lld",&Q);
        process();
        while(Q--){
            scanf("%lld",&L);
            scanf("%lld",&R);
            query();


        }
    }


   // test runner
for(int i=0;i<100000;i++){
    tester();
}
}
