#include<stdio.h>

int CMAX=100000009;
int RMIN=-1; 
int main(){
    int R,C;
    int tab[101][101];
    int rowmin[101];
    int colmax[101];
    scanf("%d",&R);
    scanf("%d",&C);
    for(int i=0;i<R;i++){ rowmin[i]=CMAX;}
    for(int i=0;i<C;i++){ colmax[i]=-1; }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            scanf("%d",&tab[i][j]);
            if(rowmin[i]>tab[i][j]){
                rowmin[i]=tab[i][j];
            }
            if(colmax[j]<tab[i][j]){
                colmax[j]=tab[i][j];
            }
        }
    }
    int ccost=-1;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
             if(tab[i][j]==rowmin[i]&&tab[i][j]==colmax[j]){
                 ccost = tab[i][j];
            }
        }
    }
    if(ccost<0){
        printf("GUESS\n");
    } else {
        printf("%d\n",ccost);
    }
    
}
