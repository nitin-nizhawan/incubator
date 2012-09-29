#include<cstdio>
#define MAX 1004
int inp[MAX][MAX]={{0}};
int stc_h[MAX]={0},stc_v[MAX]={0};
int tp_h=-1,tp_v=-1;
void hs(int n){
    int val_h =0;
    int val_v=0;
    for(register int i=0;i<=n;i++){
        for(register int j=0;j<=n;j++){
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
/*        while(tp_h>-1){
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
        val_v=0; */
    } 
}
void d1s1(int n){
    int vald1s1 = 0;
    int vald1s2 = 0;
    int vald2s1 = 0;
    int vald2s2 = 0;
    int n1 = n-1;
    int ij,a,b ;
    int n1j,n1ij;
    int stid1s1[MAX],stjd1s1[MAX],stid1s1_tp=-1;
    int stid1s2[MAX],stjd1s2[MAX],stid1s2_tp=-1;
    int stid2s1[MAX],stjd2s1[MAX],stid2s1_tp=-1;
    int stid2s2[MAX],stjd2s2[MAX],stid2s2_tp=-1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            ij = i-j; n1j = n1-j; n1ij = n1-ij;
            { if(inp[ij][j]>0){ vald1s1++; stid1s1[++stid1s1_tp]=ij; stjd1s1[stid1s1_tp]=j; } else { while(stid1s1_tp>-1){ a = stid1s1[stid1s1_tp]; b = stjd1s1[stid1s1_tp--]; if(inp[a][b]<vald1s1){ inp[a][b] = vald1s1; } } vald1s1 = 0; } };
            if(i<(n1)){
               { if(inp[n1j][n1ij]>0){ vald1s2++; stid1s2[++stid1s2_tp]=n1j; stjd1s2[stid1s2_tp]=n1ij; } else { while(stid1s2_tp>-1){ a = stid1s2[stid1s2_tp]; b = stjd1s2[stid1s2_tp--]; if(inp[a][b]<vald1s2){ inp[a][b] = vald1s2; } } vald1s2 = 0; } };
            }
            { if(inp[j][n1ij]>0){ vald2s1++; stid2s1[++stid2s1_tp]=j; stjd2s1[stid2s1_tp]=n1ij; } else { while(stid2s1_tp>-1){ a = stid2s1[stid2s1_tp]; b = stjd2s1[stid2s1_tp--]; if(inp[a][b]<vald2s1){ inp[a][b] = vald2s1; } } vald2s1 = 0; } };
            if(i<(n1)){
              { if(inp[n1ij][j]>0){ vald2s2++; stid2s2[++stid2s2_tp]=n1ij; stjd2s2[stid2s2_tp]=j; } else { while(stid2s2_tp>-1){ a = stid2s2[stid2s2_tp]; b = stjd2s2[stid2s2_tp--]; if(inp[a][b]<vald2s2){ inp[a][b] = vald2s2; } } vald2s2 = 0; } };
            }
        }
     /*   { while(stid1s1_tp>-1){ a = stid1s1[stid1s1_tp]; b = stjd1s1[stid1s1_tp--]; if(inp[a][b]<vald1s1){ inp[a][b] = vald1s1; } } vald1s1 = 0; };
        { while(stid1s2_tp>-1){ a = stid1s2[stid1s2_tp]; b = stjd1s2[stid1s2_tp--]; if(inp[a][b]<vald1s2){ inp[a][b] = vald1s2; } } vald1s2 = 0; };
        { while(stid2s1_tp>-1){ a = stid2s1[stid2s1_tp]; b = stjd2s1[stid2s1_tp--]; if(inp[a][b]<vald2s1){ inp[a][b] = vald2s1; } } vald2s1 = 0; };
        { while(stid2s2_tp>-1){ a = stid2s2[stid2s2_tp]; b = stjd2s2[stid2s2_tp--]; if(inp[a][b]<vald2s2){ inp[a][b] = vald2s2; } } vald2s2 = 0; }; */
    }
}
int main(){
    int n;
    char c;
    char cs[1002];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            scanf("%s",cs);
        for(int j=1;j<=n;j++){
            if(cs[j-1]=='X'){
                inp[i][j]=1;
            }
        }
    }
    hs(n);
    d1s1(n); 
    for(int l=1;l<=n;l++){
        for(int m=1;m<=n;m++){
            printf("%d",inp[l][m]);
            if(m<n){
                printf("%c",' ');
            }
        }
        printf("%c",'\n');
    }

}
