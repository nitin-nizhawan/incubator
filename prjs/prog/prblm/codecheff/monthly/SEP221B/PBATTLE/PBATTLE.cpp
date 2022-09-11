#include <iostream>
#include<algorithm>
#include<set>
#define READ_ARR(X,NUM) {for(int i=0;i<NUM;i++) { cin>>X[i]; }}
#define FORI(MAX) for(int i=0;i<MAX;i++) 
#define FORRI(MAX) for(int i=(MAX)-1;i>=0;i--)
#define PARR(X,MAX) {FORI(MAX){ cout<<X[i]<<", "; } cout<<endl;}
using namespace std;
int N;
class Node {
  public:
    long aval;
    long bval;
    int pos;
};
class BSTNode {
  public:
  BSTNode* left;
  BSTNode* right;
  BSTNode* parent;
  long leftCount;
  long val;
};
BSTNode BN[100005];
int nextNode=1;
long A[100005];
long B[100005];
long S[100005];
Node P[100005];
long MIN[100005];
long MAX[100005];
long BSCORE[100005];
set<long> setA[10005];
set<long> setB[10005];
long myfunction(Node a,Node b){
	return a.aval < b.aval;
}
void print_winners(){
long max=S[0];
FORI(N){
  if(max < S[i]){
    max=S[i];
  }
}
long maxcnt=0;
FORI(N){
  if(S[i]==max){
    maxcnt++;
  }
}
cout<<maxcnt<<endl;

}
long bstAdd(BSTNode* node,long val){
  if(val < node->val){
    node->leftCount++;
    if(!node->left){
      node->left=(BN+nextNode);
      node->left->parent = node;
      node->left->val = val;
      nextNode++;
      return 0;
    } else{
      return  bstAdd(node->left,val);
    }
  } else {
    if(!node->right){
      node->right = (BN+nextNode);
      node->right->parent = node;
      node->right->val = val;
      nextNode++;
      return node->leftCount+1;
    } else {
       long rv = bstAdd(node->right,val);
       rv += node->leftCount + 1;
       return rv;
    } 
  }
}
long bstAdd(long val){
   if(BN[0].val==-1){
     BN[0].val = val;
     return 0;
   }
   return bstAdd(BN,val);
   
}
void clearBST(){
  FORI(nextNode){
    BN[i].val=-1;
    BN[i].parent=nullptr;
    BN[i].left=nullptr;
    BN[i].right=nullptr;
    BN[i].leftCount =0;
  }
  nextNode=1;
}
void printTree(int pos,char LR,BSTNode* node){
  if(node!=nullptr){
    for(int i=0;i<pos;i++){
      cout<<" ";
    }
    cout<<LR;
    cout<<"("<<node->val<<", "<<node->leftCount<<")"<<endl;
    printTree(pos+1,'L',node->left);
    printTree(pos+1,'R',node->right);
  }
}
void solve(){
  BN[0].val = -1;
 cin>>N;

 READ_ARR(A,N)
 READ_ARR(B,N)
 FORI(N){
	 P[i].aval=A[i];
	 P[i].bval=B[i];
	 P[i].pos=i;
 }
 
sort(P,P+N,myfunction);
/*
FORI(N){
  cout<<"("<<P[i].aval<<","<<P[i].bval<<","<<P[i].pos<<")";
}
cout<<endl;
*/
MIN[N-1]=P[N-1].bval;
MAX[N-1]=P[N-1].bval;
BSCORE[N-1]=bstAdd(P[N-1].bval);
FORRI(N-1){
  BSCORE[i]=bstAdd(P[i].bval);
/*  BSCORE[i]=0;
   MIN[i] = MIN[i+1]; 
   MAX[i] = MAX[i+1];
   if(MIN[i] > P[i].bval){
     MIN[i]=P[i].bval;
   }

   if(MAX[i] < P[i].bval){
     MAX[i] = P[i].bval; }
     for(int j=i+1;j<N;j++){
      if(P[i].bval > P[j].bval){
       if(P[j].bval == MAX[j]){
            BSCORE[i]+=BSCORE[j]+1;
            break;
        }else{
            BSCORE[i]++;
        }
      } 
      if(P[i].bval < MIN[j]){
         break;
      }
   }
*/

}
//printTree(0,' ',BN);
clearBST();

// PARR(BSCORE,N)





// calculate scores
FORI(N){
  S[P[i].pos]=i+BSCORE[i];
}
// PARR(S,N)
print_winners();
}

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T-- >0){
		solve();
	}
	return 0;
}

