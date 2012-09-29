#include<stdio.h>

long long x[1001];
void solve(int a, int b, int n){
    x[0]=1;
    for(int i=1;i<n;i++){
        x[i] = x[i-1]+1;
        long long st = a*x[i-1];
        for(int j=i-1;j>=0;j--){
            long long diff = st - b*x[j];
            if(diff==x[i]){
                x[i]++;
            } 
            else if(diff>x[i]){
                break;
            }
        }
        st = b*x[i-1];
        for(int j=0;j<=i-1;j++){
            long long diff = a*x[j] - st;
            if( diff == x[i]){
                x[i]++;
            }
            else if(diff>x[i]){
                break;
            }
        }

        st = a*x[i-1];
        for(int j=i-1;j>=0;j--){
            long long diff = st - b*x[j];
            if(diff==x[i]){
                x[i]++;
            } 
            else if(diff>x[i]){
                break;
            }
        }




    }


    printf("%lld",x[0]);
    for(int i=1;i<n;i++){
        printf(" %lld",x[i]);
    }
    printf("\n");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b,n;
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&n);
        solve(a,b,n);
    }
    
}
