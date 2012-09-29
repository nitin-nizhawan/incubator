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
void buildTree(Node *node,int turn){
    if(node->s.full==C){
        node->val = -1*turn; 
        return;
    }
    Node *child;
    for(int i=0;i<C;i++){
        // generate all possible moves for board i
        int cx = node->s.x[i],cy = node->s.y[i];
        int ni=n[i],mi = m[i];
        for(int j=0;j<6;j++){
           if((cx+possiblemovex[j])<ni&&(cy+possiblemovey[j])<mi){
               Node *child  = new Node();
               child->numkids=0;
               // copy
               for(int k=0;k<C;k++){
                   child->s.x[k]= node->s.x[k];
                   child->s.y[k]= node->s.y[k];
               }
               // apply the move
               child->s.full = node->s.full;
               child->s.x[i]+=possiblemovex[j];
               child->s.y[i]+=possiblemovey[j];
               if(child->s.x[i]==(ni-1)&&child->s.y[i]==(mi-1)){
                   child->s.full++;
               }
               node->kids[node->numkids++] = child;
           }    
        }
    }
// recursively build remaining tree
 
    for(int i=0;i<node->numkids;i++){
        buildTree(node->kids[i],-1*turn);
    }
    if(turn==CHEF){
      node->val=BRO;
      for(int i=0;i<node->numkids;i++){
          if(node->kids[i]->val==CHEF){
            node->val=CHEF;
          }
      }
    } else {
      node->val=CHEF;
      for(int i=0;i<node->numkids;i++){
         if(node->kids[i]->val==BRO){
             node->val=BRO;
         }
      }
    }
    
}
void solve(){
  // build min-max tree
  Node *root = new Node();
 for(int i=0;i<C;i++){
      root->s.x[i]=0;
      root->s.y[i]=0;
 }
 root->s.full=0;
 root->numkids=0;
 buildTree(root,CHEF);
 if(root->val==CHEF){
     printf("MasterCheff\n");
 } else {
    printf("Football\n");
}
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
      solve();
      printf("solved\n");
  }
}
