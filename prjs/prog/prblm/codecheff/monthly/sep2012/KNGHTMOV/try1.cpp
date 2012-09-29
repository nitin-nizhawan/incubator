#include<stdio.h>
#define MAXSTEPS 500000
int Ax,Ay,Bx,By,X,Y,K;
bool hashk[1001][1001];
int kxs[16];
int kys[16];
long long board[MAXSTEPS];
long long  PRIME=1000000007;
void printans(long long ans){
    printf("%lld\n",ans);
}

void solve(){
    if(Ax==0&&Ay==0&&Bx==0&&By==0){
        printans(0); return;
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
    for(int i=0;i<K;i++){
        hashk[kxs[i]+500][kys[i]+500]=true;
    }
    int curx=0;
    int cury=0;
    if(sA>=MAXSTEPS){
//         printans(0); return; 
    }
    for(int i=0;i<=sA;i++){
        board[i]=0;
    }
    for(int i=0;i<=sB;i++){
	int j=0;
	curx = j*Ax + i*Bx;
	cury = j*Ay + i*By;
	if(curx>=-500&&curx<=500&&cury>=-500&&cury<=500&&hashk[curx+500][cury+500]){
	    board[0]=0;
	} else {
	    board[0]=1;
	} 
	j++;
	for(;j<=sA;j++){
	    curx = j*Ax + i*Bx;
	    cury = j*Ay + i*By;
	    if(curx>=-500&&curx<=500&&cury>=-500&&cury<=500&&hashk[curx+500][cury+500]){
		board[j]=0;
	    } else {
		board[j]=(board[j]+board[j-1])%PRIME;
	    } 
	}
    }
    printans(board[sA]);
    // clear map
    for(int i=0;i<K;i++){
        hashk[kxs[i]+500][kys[i]+500]=false;
    }
}    
int main(){
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
