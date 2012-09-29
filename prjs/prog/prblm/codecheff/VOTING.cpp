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
 }
}
int partition(int v[],int s, int e){
    while(s!=e){
        while(s!=e&&invs[v[e]]>=invs[v[s]]){ e--; }
        if(s!=e){
            int tmp = v[e];
            v[e] = v[s];
            v[s]=tmp;
        }
        while(s!=e&&invs[v[s]]<=invs[v[e]]){ s++ ;}
        if(s!=e){
            int tmp=v[e];
            v[e] = v[s];
            v[s] = tmp;
        }
    }
    return s;
}
void  quickSort(int v[],int n, int q){
  if(n<q){
      int p = partition(v,n,q);
      quickSort(v,n,p-1);
      quickSort(v,p+1,q);
  }
}
void solveTestcase(){
    inputData();
 // solution
  int si[MAXN]; // to keep keys sorted according to invs
  for(int i=0;i<n;i++) si[i]=i;
  quickSort(si,0,n-1); // keys now sorted according to invs;
  int upCum[MAXN];
  int downCum[MAXN];
  upCum[0]=invs[si[0]];
  downCum[n-1]=invs[si[n-1]];
  for(int i=1;i<n;i++){
    upCum[i]=upCum[i-1]+invs[si[i]];
    downCum[n-i-1]=downCum[n-i]+invs[si[n-i-1]];
  }
 /* for(int i=0;i<n;i++){
      cout<<"up : "<<upCum[i]<<" , dCum: "<<downCum[i]<<" , si[i]:"<<si[i]<<endl;
  }*/

  // find sum(|ai-aj|)
  int totalDist[MAXN]={0};
 // cout<<"ttlDist :";
  for(int j=0;j<n;j++){
     if(j>0){
         totalDist[j]+=j*invs[si[j]]-upCum[j-1];
     }
     if(j<n-1){
         totalDist[j]+=downCum[j+1]-(n-j-1)*invs[si[j]];
     }
   //  cout<<totalDist[j]<<" ";
  }
 // cout<<endl;
  
 
 int minDist=totalDist[0];
  for(int k=1;k<n;k++){
      if(minDist>totalDist[k]){
          minDist = totalDist[k];
      }
  
}

 //cout<<"min Distance : "<<minDist<<endl;

  int minDistCands[MAXN];
  int buff[MAXN];
  int minDistCandCnt=0;
  for(int l=0;l<n;l++){
     if(minDist==totalDist[l]){
         minDistCands[minDistCandCnt++]=si[l];
     }
  }
/*cout<<"minDistCands Before sorting :";
for(int i=0;i<minDistCandCnt;i++) cout<<minDistCands[i]<<" ";
cout<<endl;*/
  // now sort these keys according to permutations :)
  // using radix sort to sort permutations
  int bucket[MAXM+2];
  for(int h=0;h<m;h++){ // for each member of parliament 
      for(int i=0;i<=m;i++) bucket[i]=0;  // 1---15, kind of
      for(int d=0;d<minDistCandCnt;d++){
          bucket[ranks[minDistCands[d]][h]]++;
      }
//    cout<<"Buckets filled "<<endl;
      for(int c=1;c<=m;c++){
          bucket[c]+=bucket[c-1];
      }
   
      for(int a=minDistCandCnt-1;a>=0;a--){
          buff[--bucket[ranks[minDistCands[a]][h]]]=minDistCands[a];
      }
      for(int x=0;x<minDistCandCnt;x++){
          minDistCands[x]=buff[x];
      }
  }
/*cout<<"minDistCands After sorting :";
for(int i=0;i<minDistCandCnt;i++) cout<<minDistCands[i]<<" ";
cout<<endl; */

  cout<<minDist<<":"<<ranks[minDistCands[0]][0];
  for(int o=1;o<m;o++){
    cout<<" "<<ranks[minDistCands[0]][o];
  }
  cout<<endl;
}
int main(){
 int T;
  scanf("%d",&T);
  while(T--){
   solveTestcase();
  }
 
}
