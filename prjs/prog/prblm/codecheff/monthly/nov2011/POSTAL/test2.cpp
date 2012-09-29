#include<stdio.h>
#include<vector>
#include<algorithm>
#define EXPMAX 65000
#define DWORD long long
using namespace std;
class Node{
    public:
        long long pos;
        long long val;
};
bool mcomp(Node a, Node b){
    return a.val<b.val;
}
int N;
long long pos[500];
long long qT;
int qN;
int Q;
vector<Node> pos2;
bool dir[500];
void solve(){
}
long long pos2_val[500];
long long pos2_pos[500];
long long aux[500];
long long aux2[500];
void merge(long long *lst,long long *lst2,int beg1, int end1,int beg2,int end2,long long *aux,long long *aux2){
    int c = beg1; // counter for auxiliary array
    int beg= beg1; // copy beg and end
    int end = end2;
    while(beg1<=end1&&beg2<=end2){
        if(lst[beg1]<=lst[beg2]){
            aux[c] = lst[beg1];
            aux2[c++] = lst2[beg1++];
        } else {
            aux[c] = lst[beg2];
            aux2[c++] = lst2[beg2++];
        }
    }
    // copy remaining items if any
    while(beg1<=end1){
        aux[c] = lst[beg1];
        aux2[c++] = lst2[beg1++];
    }
    while(beg2<=end2){
        aux[c] = lst[beg2];
        aux2[c++] = lst2[beg2++];
    }
    // now copy sorted elements from aux to actual list
    while(beg<=end){
        lst[beg]=aux[beg];
        lst2[beg]=aux2[beg++];
    }
}
void query(){
    for(int i=0;i<N;i++){
        pos2[i].pos = i;
        pos2_pos[i] = i;
        pos2[i].val = pos[i] + (qT+1)*((dir[i]>0)?1:-1);
        pos2_val[i] = pos[i] + (qT)*((dir[i]>0)?1:-1);
    }
    /*
    sort(pos2.begin(),pos2.begin()+N,mcomp);
    for(int m=1;m<=N;m=m*2){ // list sizes of 1,2,4,8,16 etc.
        for(int i=0;i < N-m;i+=2*m){ // for each alternative list of size m
            //merge list [i...i+m-1] and [i+m....i+2*m-1]
            merge(pos2_val,pos2_pos,i,i+m-1,i+m,min(i+2*m-1,N-1),aux,aux2);
        }
    }
    int key;
    int key_;
    int numcol_;
    for(int i=0;i<N;i++){
        if(pos2_pos[i]==qN){
            numcol_ = abs(i-qN);
            break;
        }
    }
    
    for(int i=0;i<N;i++){
        if(pos2_pos[i]==key_){
            numcol_=abs(i-key_);
            break;
        }
    }
    for(int i=0;i<N;i++){
        if(pos2[i].pos==qN){
            key = i;
            break;
        }
    }
    int numcol;
    for(int i=0;i<N;i++){
        if(pos2[i].pos==key){
            numcol=abs(i-key);
            break;
        }
    }
    
    //int numcol = abs(key-pos2[qN].pos);
  //  int numcol_ = abs(key_-pos2_pos[qN]);
    long long pos_ans = pos2[qN].val;//+(dir[pos2[qN].pos]>0?-1:1);
    int correc = 0;
    for(int i=1;i<N;i++){

    }
    for(int i=1;i<N;i++){
        if(pos2_val[i]==pos2_val[i-1]){
            if(i==qN||(i-1)==qN){
                numcol_++;
            }
        }
    }
   
    if(qN-1>=0){
        if( pos2_val[qN-1]==pos2_val[qN]){
            numcol_+=1;
        } else if(pos2_val[qN+1]==pos2_val[qN]){
            numcol_+=1;
        }
    } else if((qN+1)<N){
        if(pos2_val[qN+1]==pos2_val[qN]){
            numcol_+=1;
        } else if( pos2_val[qN-1]==pos2_val[qN]){
            numcol_+=1;
        }
    }
    
    long long pos_ans_ = pos2_val[qN];//+(dir[pos2_pos[qN]]>0?-1:1);
    //    printf("%lld %d\n",pos_ans,numcol);
    */
    int numcol_=0;
    for(int i=0;i<qN;i++){

        if(pos2_val[i]>=pos2_val[qN]){
            numcol_++;
        }
       
    }
    for(int i=qN+1;i<N;i++){
        if(pos2_val[i]<=pos2_val[qN]){
            numcol_++;
        }
    }
    sort(pos2_val,pos2_val+N);
    long long pos_ans_ = pos2_val[qN];
    printf("%lld %d\n",pos_ans_,numcol_);
}
bool mcomp2(long long a, long long b){
    return a<b;
}
double abs2(double a){
    return (a<0)?(-a):a;
} 
bool equals(double a, double b){
    return (abs2(a-b)<0.001);
}
long long brute_force(){
    vector<double> cp,srt;
    cp.resize(500);
    srt.resize(500);
    bool dir2[500];
    for(int i=0;i<N;i++){
        cp [i]=pos[i];
        dir2[i] = dir[i];
    }
    double repeatvalue[500];
    long long rcnt=0;
    long long ans=0;
    for(int i=1;i<=2*qT;i++){
        for(int j=0;j<N;j++){
            if(dir2[j]>0){
                cp[j]+=0.5;
            } else {
                cp[j]-=0.5;
            }
            srt[j]=cp[j];        
            //printf("%lf ",srt[j]);
        }
        //printf("\nsorted:: ");
        sort(srt.begin(),srt.begin()+N);
        for(int i=0;i<N;i++){
            //printf("%lf ",srt[i]);
        }
        //printf("\n");
        double lastval = srt[0];
        for(int i=1;i<N;i++){
            if(equals(lastval,srt[i])){
                if(rcnt==0||!equals(repeatvalue[rcnt-1],srt[i])){
                    repeatvalue[rcnt++] = srt[i];
                }
            }
            lastval = srt[i];
        }
        for(int i=0;i<rcnt;i++){
            //printf("RPV:: %lld\n",repeatvalue[i]);
            for(int j=0;j<N;j++){
               
                if(equals(repeatvalue[i],cp[j])){
                    dir2[j] = 1 - dir2[j];
                    if(j==qN){
                        ans++;
                    }
                }
            }
        }
        rcnt = 0;
    }
    if(equals(-774.0,cp[qN])){
    printf("================================================\n");
    printf("N=%d\n",N);
    for(int i=0;i<N;i++){
       printf("%lld ",pos[i]);
    }
    printf("\n");
    for(int i=0;i<N;i++){
        printf("%d ",dir[i]);
    }
    printf("\n1\n");
        printf("%d %lld\n",qN,qT);
    }
    printf("brute_force:: %lf, %lld\n",cp[qN],ans);
}
void tester(){
    N = (rand()%5) + 1;
   // printf("================================================\n");
 //   printf("N=%d\n",N);
    for(long long i=0;i<N;i++){
        pos[i] = (i>0)?(pos[i-1]+rand()%100+1):(rand()%100);
        dir[i] = ((rand()%2)>0)?1:0;
      //  printf("%lld ",pos[i]);
    }
    //printf("\n");
    for(int i=0;i<N;i++){
  //      printf("%d ",dir[i]);
    }
    int Q=5;
  //  printf("\n1\n");
    while(Q--){
        qN = rand()%N;
        qT = rand()%1000;
//        printf("%d %lld\n",qN,qT);
        brute_force();
        query();
    }
}
int main(){

    int T,tmp;
    pos2.resize(500);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%lld",&pos[i]);
        }
        for(int i=0;i<N;i++){
            scanf("%d",&tmp);
            dir[i]=(tmp>0)?1:0;
        }
        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            scanf("%d",&qN);
            scanf("%lld",&qT);
         //   brute_force();
            query();
        }
    }
    for(int i=0;i<13;i++){
//          tester();
    }
//    N = 2; qN = 1; qT = 82; pos[0]=9; pos[1] = 17; dir[0]=1; dir[1]=0; Q=1;
  //  N = 3; qN = 1; qT = 2; pos[0]=0; pos[1] = 4;pos[2] = 5;  dir[0]=1; dir[1]=0;dir[2]=0; Q=1;
  //  brute_force();
//    query();
    //    printf("dsfs: %lld",1000000000+1000000000);
}
