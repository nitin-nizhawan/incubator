#include<cstdio>
#define MAX 1002


#define update(sti,stj,i,j,val,sti_tp)  {\
    if(inp[i][j]>0){ \
        val++;  \
        sti[++sti_tp]=i; \
        stj[sti_tp]=j;  \
    } else {   \
        while(sti_tp>-1){ \
            int a = sti[sti_tp]; \
            int b = stj[sti_tp--]; \
            if(inp[a][b]<val){ \
                inp[a][b] = val; \
            }  \
        }            \
        val = 0;  \
    }  \
}
#define emptyStacks(sti,stj,val,sti_tp) { \
    while(sti_tp>-1){ \
        int i = sti[sti_tp]; \
        int j = stj[sti_tp--]; \
        if(inp[i][j]<val){  \
            inp[i][j] = val; \
        } \
    } \
    val = 0; \
}


int inp[MAX][MAX]={{0}};
int stc_h[MAX]={0},stc_v[MAX]={0};
int tp_h=-1,tp_v=-1;
void emptyStacks2(int *sti,int *stj,int &val,int &sti_tp){
    while(sti_tp>-1){
        int i = sti[sti_tp];//sti.top(); sti.pop();
        int j = stj[sti_tp--];//stj.top(); stj.pop();
        if(inp[i][j]<val){
            inp[i][j] = val;
        }
    }
    val = 0;
}
void update2(int *sti,int *stj,int i, int j,int &val,int &sti_tp){
    if(inp[i][j]>0){
        val++;
        sti[++sti_tp]=i;
        stj[sti_tp]=j;
    } else {
        while(sti_tp>-1){
            int i = sti[sti_tp];//sti.top(); sti.pop();
            int j = stj[sti_tp--];//stj.top(); stj.pop();
            if(inp[i][j]<val){
                inp[i][j] = val;
            }
        }
        val = 0;
    }
}
void hs(int n){
    int val_h =0;
    int val_v=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(inp[i][j]>0){
                val_h++;
                stc_h[++tp_h]=j;
            } else {
                while(tp_h>-1){
                    int j_h = stc_h[tp_h--];
                    if(inp[i][j_h]<val_h){
                        inp[i][j_h]=val_h;       
                    }
                }
                val_h=0;
            }   
            if(inp[j][i]>0){
                val_v++;
                stc_v[++tp_v]=j;
            } else {
              while(tp_v>-1){
                  int j_v = stc_v[tp_v--];
                  if(inp[j_v][i]<val_v){
                      inp[j_v][i] = val_v;
                  }
              }
              val_v=0;
            }  
        }
        while(tp_h>-1){
            int j_h = stc_h[tp_h--]; 
            if(inp[i][j_h]<val_h){
                inp[i][j_h]=val_h;
            }
        }
        val_h=0;
        while(tp_v>-1){
           int j_v = stc_v[tp_v--]; 
           if(inp[j_v][i]<val_v){
                inp[j_v][i] = val_v;
           }
        }
        val_v=0;
    }
}
void d1s1(int n){
    int vald1s1 = 0;
    int vald1s2 = 0;
    int vald2s1 = 0;
    int vald2s2 = 0;
    int n1 = n-1;
    int ij ;
    int stid1s1[MAX],stjd1s1[MAX],stid1s1_tp=-1;
    int stid1s2[MAX],stjd1s2[MAX],stid1s2_tp=-1;
    int stid2s1[MAX],stjd2s1[MAX],stid2s1_tp=-1;
    int stid2s2[MAX],stjd2s2[MAX],stid2s2_tp=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            ij = i-j;
            update(stid1s1,stjd1s1,ij,j,vald1s1,stid1s1_tp);
            if(i<(n1)){
               update(stid1s2,stjd1s2,n1-j,n1-ij,vald1s2,stid1s2_tp);
            }
            update(stid2s1,stjd2s1,j,n1-ij,vald2s1,stid2s1_tp);
            if(i<(n1)){
              update(stid2s2,stjd2s2,n1-ij,j,vald2s2,stid2s2_tp);
            }
        }
        emptyStacks(stid1s1,stjd1s1,vald1s1,stid1s1_tp);
        emptyStacks(stid1s2,stjd1s2,vald1s2,stid1s2_tp);
        emptyStacks(stid2s1,stjd2s1,vald2s1,stid2s1_tp);
        emptyStacks(stid2s2,stjd2s2,vald2s2,stid2s2_tp);
    }
}
int main(){
    int n;
    char c;
    char cs[1002];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
            scanf("%s",cs);
        for(int j=0;j<n;j++){
            if(cs[j]=='.'){
                inp[i][j]=0;
            } else {
                inp[i][j]=1;
            }
        }
    }
    hs(n);
    d1s1(n); 
    for(int l=0;l<n;l++){
        for(int m=0;m<n;m++){
            printf("%d",inp[l][m]);
            if(m<n-1){
                printf("%c",' ');
            }
        }
        printf("%c",'\n');
    }

}
