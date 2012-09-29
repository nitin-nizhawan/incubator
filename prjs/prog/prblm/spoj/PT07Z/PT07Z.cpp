#include<stdio.h>
#include<vector>



using namespace std;
vector<int> tree[10001];
int maxdepth1[10001];
int maxdepth2[10001];
int  visited[10001]={0};
int visitOrder=1;
int N;
int maxans=0;
int dfs(int node){
    int depth =0;
    if(!visited[node]){
        visited[node]=visitOrder++;
        int maxi=0;
        for(int i=0;i<tree[node].size();i++){
            int childNode = tree[node][i];
            int chh = dfs(childNode);
            if(chh+1>depth){
                depth = chh+1;
            }
            if(visited[childNode]>visited[node]&&maxdepth1[childNode]+1>maxdepth1[node]){
                maxdepth1[node] = maxdepth1[childNode]+1;
                maxi=childNode;
            }
        }
        for(int i=0;i<tree[node].size();i++){
            int childNode = tree[node][i];
            if(maxi!=childNode&&visited[childNode]>visited[node]&&maxdepth2[node]<(maxdepth1[childNode]+1)){
                maxdepth2[node] = maxdepth1[childNode]+1;
            }
        }
        if(maxdepth1[node]+maxdepth2[node]>maxans){
            maxans=maxdepth1[node] + maxdepth2[node];
        }
    }
    return depth;
}
int main(){
  scanf("%d",&N);
  for(int i=1;i<N;i++){
      int a,b;
      scanf("%d",&a);
      scanf("%d",&b);
      tree[a-1].push_back(b-1);
      tree[b-1].push_back(a-1);
  }
  dfs(0);
  printf("%d\n",maxans);
}
