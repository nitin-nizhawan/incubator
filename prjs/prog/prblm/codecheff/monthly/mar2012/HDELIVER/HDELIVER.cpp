#include<stdio.h>

int N,M;
bool fw[200][200];
int main(){
    int T;
    scanf("%d",&T);
    int ti,tj;
    while(T--){
        scanf("%d",&N);
        scanf("%d",&M);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                fw[i][j]=false;
            }
        }
        for(int i=0;i<M;i++){
            scanf("%d",&ti);
            scanf("%d",&tj);
            fw[ti][tj]=true;
            fw[tj][ti]=true;
        }
        // fw
        
        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(fw[i][k]&&fw[k][j]){
                        fw[i][j]=true;
                    }
                }
            }
        }
        int colors[200];
        int color=0;
        colors[0]=color;
        for(int i=1;i<N;i++){
            colors[i]=-1;
            for(int j=0;j<i;j++){
                if(fw[i][j]||fw[j][i]){
                    colors[i]=colors[j];
                    break;
                }
            }
            if(colors[i]<0){
                colors[i]=++color;
            }
        }
        int Q;
        scanf("%d",&Q);
        while(Q--){
            scanf("%d",&ti);
            scanf("%d",&tj);
            if(colors[ti]==colors[tj]){
                printf("YO\n");
            } else {
                printf("NO\n");
            }
        }
    }
}
