#include<stdio.h>
#include<algorithm>
using namespace std;
long long fact[1000001];
long long finv[1000001];
long long  PRIME=1000000007;
int fcnt=0;
long long egcd(long long A, long long B, long long *X, long long *Y){
    long long x, y, u, v, m, n, a, b, q, r;
 
    /* B = A(0) + B(1) */
    x = 0; y = 1;
 
    /* A = A(1) + B(0) */
    u = 1; v = 0;
 
    for (a = A, b = B; 0 != a; b = a, a = r, x = u, y = v, u = m, v = n)
    {
        /* b = aq + r and 0 <= r < a */
        q = b / a;
        r = b % a;
 
        /* r = Ax + By - aq = Ax + By - (Au + Bv)q = A(x - uq) + B(y - vq) */
        m = x - (u * q);
        n = y - (v * q); 
    }   
 
    /* Ax + By = gcd(A, B) */
    *X = x; *Y = y;
 
    return b;
}

long long  modinv(long long a, long long m){
    long long x ; long long y;
    long long g;
    g = egcd(a, m,&x,&y);
        return ((x % m)+m)%m;
}
long long cfact(long long n){
    if(n>fcnt){
        for(int i=fcnt;i<=n;i++){
            fact[i] = (fact[i-1]*i)%PRIME;
            finv[i]=(finv[i-1]*modinv(i,PRIME))%PRIME;
        }
        fcnt = n;
    }
    return fact[n];
}

int Ax,Ay,Bx,By,X,Y,K;
class Node{
public:
   int a,b;
}stops[16];
int scnt=0;
int kxs[16];
int kys[16];
void printans(long long ans){
    printf("%lld\n",ans);
}
bool isReachable(int D,int sx,int sy,int ex,int ey,int c){
    int dx = ex - sx;
    int dy = ey - sy;
    int DA = dx*By - dy*Bx;
    int DB = Ax*dy - Ay*dx;
    if(DA%D!=0||DB%D!=0){
        return false;
    }
    int sA = DA/D;
    int sB = DB/D;
    if(sA<0||sB<0){
        return false;
    }
    stops[c].a=sA;
    stops[c].b=sB;
    return true;
}
bool mycomp(Node n1, Node n2){
    if(n1.b==n2.b){
        return n1.a>n2.a;
    }
    return n1.b>n2.b;
}

long long C(int n,int r){
//   int fact[]={1,1,2,6,24,120,720,720*8};
//   return fact[n]/(fact[r]*fact[n-r]);
    long long ans = cfact(n);
    ans = (ans*finv[r])%PRIME;
    ans = (ans*finv[n-r])%PRIME;
    return ans;
}
long long dist(int a1,int b1,int a2,int b2){
   //printf("dist from %d,%d to %d,%d\n",a1,b1,a2,b2);
    int da = a2-a1;
    int db = b2-b1;
    if(da<0||db<0){
        return 0;
    }
    return C(da+db,da);
}
void fpError(){
   int a=1;
   a=a/(a-1);
  int c=a*a;
exit(-1);
}

void step2(int D,int sA,int sB){
    //printf("Begin step2 D=%d,sA=%d,sB=%d\n",D,sA,sB);
    scnt=0;
    for(int i=0;i<K;i++){
  //     if(isReachable(D,kxs[i],kys[i],X,Y,scnt)){
          if(isReachable(D,0,0,kxs[i],kys[i],scnt)){
             scnt++;
          }
  //     }
    }
    sort(stops,stops+scnt,mycomp);
    /*for(int i=0;i<scnt;i++){
        printf("(%d,%d) ",stops[i].a,stops[i].b);
    }
    printf("\n"); */
    long long sums[16];
    long long  sum = dist(0,0,sA,sB);
    for(int i=0;i<scnt;i++){
        sums[i]=dist(stops[i].a,stops[i].b,sA,sB);
        for(int j=0;j<i;j++){
            sums[i]=(sums[i]+PRIME-(sums[j]*dist(stops[i].a,stops[i].b,stops[j].a,stops[j].b))%PRIME)%PRIME;
        }
        sum=(sum+PRIME-(sums[i]*dist(0,0,stops[i].a,stops[i].b))%PRIME)%PRIME;
    }    
    if(sum<0){

      fpError();
    }
    printans(sum%PRIME);
   
}
void handleSingle(int Ax,int Ay){
if(Ax==0||Ay==0){
   fpError();    
}
     
        if(X%Ax!=0||Y%Ay!=0||X/Ax<0||Y/Ay<0||(X/Ax)!=(Y/Ay)){
            printans(0);return;
        }
        int sA = X/Ax;
        bool stopreachable=false;
        for(int i=0;i<K;i++){
            if(kxs[i]%Ax==0&&kys[i]%Ay==0&&kxs[i]/Ax>=0&&kys[i]/Ay>=0&&(kxs[i]/Ax)==(kys[i]/Ay)){
               int ksA = kxs[i]/Ax;
               if(ksA>0&&ksA<sA){
                    stopreachable=true;break;
               }
            }
        }
        if(stopreachable){
                 fpError();
            printans(0); return;
        } else {
            if(X!=0||Y!=0){
            printans(1); return;
            } else {
                printans(0); return;
            }
        }
    
}
void solve(){
if(X==0||Y==0){
    fpError();
} 
    if(Ax==0&&Ay==0&&Bx==0&&By==0){
        printans(0); return;
    }
    if((Ax==0&&Ay==0)||(Bx==0&&By==0)){
        fpError();
        handleSingle(Ax+Bx,Ay+By);return;
    }
    if((Ax==Bx&&Ay==By)){
        handleSingle(Ax,Ay);return;
    }
    int D = Ax*By-Ay*Bx;
    if(D==0){
        printans(-1); return;
    }
    int DA = X*By - Y*Bx;
    int DB = Ax*Y - Ay*X;
    if(DA%D!=0||DB%D!=0){
        printans(0); return;
    }
    int sA = DA/D;
    int sB = DB/D;
    if(sA<0||sB<0){
         printans(0); return;
    }
    step2(D,sA,sB);
}    
int main(){
    fact[0]=1;finv[0]=1;fcnt=1;
    fact[1]=1;finv[1]=1;fcnt=1;
    int T;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&X);
        scanf("%d",&Y);
        scanf("%d",&K);
        scanf("%d",&Ax);
        scanf("%d",&Ay);
        scanf("%d",&Bx);
        scanf("%d",&By);
        for(int i=0;i<K;i++){
            scanf("%d",&kxs[i]);
            scanf("%d",&kys[i]);
        }
        solve();

    }
}
