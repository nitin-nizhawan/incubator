#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
#define MAXM 20
#define MAXN 1007
int ranks[MAXN][MAXM]={{0}};
int invs [MAXN]={0};
long inversions(int v[],int n){
    int t[MAXM];
    long inv = 0;
    for(int k=1;k<=n;k*=2){ // starting with two element subarray
        for(int i=0;i<n;i+=2*k){
          int  p=i, q=i+k-1;
          int  r= i+2*k-1;  
            if(r>=n){
                r=n-1;
            }
            if(q>=n){
               q=n-1;
            }
            // copy to aux
            for(int l=p;l<=r;l++){
                t[l]=0+v[l];
            }
            int t1 = p, t2=q+1, f=p; if(t2>=n){ t2=n-1; }
            while(t1<=q&&t2<=r){
                if(t[t1]>t[t2]){
                    v[f++]=t[t2++];
                    inv+=q-t1+1;
                } else {
                    v[f++]=t[t1++];
                }
            }
            while(t1<=q){
                v[f++]=t[t1++];
            }
            while(t2<=r){
                v[f++]=t[t2++];
            }
        }
    }
   return inv; 
    //turn inv;
}
void inputData(){
 char tmp[200];
// scanf("%s",tmp);
// cout<<"tmp :: "<<tmp<<endl;
 scanf("%d %d",&n,&m);
int cp[MAXM];
int keys[MAXN];
int keycnt=0;
//cout<<"n , m"<<n<<","<<m<<endl;
 long long sum=0;
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>ranks[i][j];
        cp[j]=ranks[i][j];
    }
    invs[i]=inversions(cp,m);
  //cout<<"invs : "<<invs[i]<<endl;
   sum+=(long long)invs[i];
 }
//cout<<"tsum"<<sum<<endl;
 int min = 1<<14;
 int mini=0;
 for(int k=0;k<n;k++){
     invs[k]=sum-invs[k]*n;
     if(invs[k]<0){ invs[k]=0-invs[k]; }
//   cout<<"invs[k]"<<invs[k]<<" , min "<<min<<" , mini"<<mini<<endl;
     if(min>invs[k]){
       min = invs[k];
       mini = k;
     }
 }
cout<<"All equals\n";
for(int f=0;f<n;f++){
    if(min==invs[f]){
    keys[keyscnt++]=f;
    }
} 
 

 cout<<sum<<":";
 for(int l=0;l<m;l++){
   cout<<ranks[keys[minkey]][l]<<" ";

 }
  cout<<endl;
}
void solveTestcase(){
 inputData();
}
int main(){
 int T;
  scanf("%d",&T);
  while(T--){
   solveTestcase();
  }
 
}
