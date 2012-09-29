#include<stdio.h>
#define MAX_HEIGHT 20
#define MAX_NODES 200001

int M,N;
int x[200001];
int y[200001];
int z[200001];
int segm[MAX_HEIGHT][MAX_NODES]={0};
int coeffs[200001]={0};
long long z_sum=0;

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




int initialize_coeffs(){
    for(int i=0;i<M;i++){
        for(int j=x[i]-1;j<y[i];j++){
            coeffs[j]++;
        }
    }
}

void solve_eqn(){
    long long  xi[200001];
    long long yi[200001];
    long long glast = coeffs[0];
    for(int i=1;i<N;i++){
        glast = egcd(glast,coeffs[i],&xi[i-1],&yi[i-1]);
    }
    if(z_sum%glast>0){
        printf("-1\n");
        return;
    } 
    long long cumx[200001];
    long long xplast = 1;
    for(int i=N-2;i>=0;i--){
        cumx[i]=xi[i]*xplast;
        xplast = cumx[i];
    }
    cumx[N-1]=1;
    long long ans[200001];
    for(int i=0;i<N;i++){
        if(i==0){
            ans[i] = cumx[i];
        } else {
            ans[i] = cumx[i]*yi[i-1];
        }
    }
    for(int i=0;i<N;i++){
        if(i>0){
            printf(" %lld",ans[i]);
        } else {
            printf("%lld",ans[i]);
        }
    }
    printf("\n");

}
int calc_z_sum(){
    for(int i=0;i<M;i++){
        z_sum+=z[i];
    }
}
int main(){
    scanf("%d",&N);
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
        scanf("%d",&z[i]);
    }
    // initialize seg tree
    // iniditialze coeffs
    initialize_coeffs();
    calc_z_sum();
    solve_eqn();
}
