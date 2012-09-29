#include<stdio.h>
int T,C,n[20],m[20];

class State {
public:
    int x[20];
    int y[20];
    int full;
};
class Node{
public:
  State s;
  int numkids;
  int val;
  Node *kids[50];
  Node(){
      numkids=0;
      val=0;
  }
};
int CHEF=1;
int BRO=-1;
int possiblemovex[]={0,1,0,2,1,2};
int possiblemovey[]={1,0,2,0,1,2};
int  solve(int C,int n[],int m[],int turn,int full,int depth){
    if(full==C){
        return -1*turn;
    }
    int lmx=-1,lmy=-1,lc=-1;
    int ret=-1*turn;
    for(int i=0;i<C;i++){
        for(int j=0;j<6;j++){
            if((possiblemovex[j])<n[i]&&possiblemovey[j]<m[i]){
                //applymove
                n[i]-=possiblemovex[j];
                m[i]-=possiblemovey[j];
                ret = solve(C,n,m,-1*turn,((n[i]==1&&m[i]==1)?full+1:full),depth+1);
                // revert the move, we will try another
                n[i]+=possiblemovex[j];
                m[i]+=possiblemovey[j];
                lmx=possiblemovex[j];
                lmy=possiblemovey[j];
                lc=i;
                // we do not need to examine others
                if(ret==turn){
               //     printf("Move No %d by %s (%d,%d) on board %d \n",depth,((turn==CHEF)?"Chef":"Bro"),possiblemovex[j],possiblemovey[j],i);
                    return ret;
                }
                
            }
        }
    }
  //  printf("Move No %d by %s (%d,%d) on board %d \n",depth,((turn==CHEF)?"Chef":"Bro"),lmx,lmy,lc);
    return ret;
}


void inputOne(){
    scanf("%d",&C);
    int i=0;
    while(i<C){
       scanf("%d",&n[i]);
       scanf("%d",&m[i]);
       i++;
    }
}

int main(){
  scanf("%d",&T);
  while(T--){
      inputOne();
      printf("Solving\n");
      printf(((solve(C,n,m,CHEF,0,0)==CHEF)?"MasterChef\n":"Football\n"));
      printf("solved\n");
  }
}
