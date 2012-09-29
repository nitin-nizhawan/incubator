/*
ID: nitin.n1
PROG: fence
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream fout ("fence.out");
ifstream fin ("fence.in");
int cp=0;
int graph[501][501];
int graphc[501][501];
int cnt[501];
int ci=1;
int tour[2000];
int mint[2000];
int revMap[1000]={0};
int fwdMap[1000]={0};
int deg[1000];
int fcnt=0;
int N;
int neighbours(int a){
	int ans=0;
	for(int i=0;i<fcnt;i++){
		if(graph[a][i]>0){
			ans++;
		}
	}
	return ans;
}
int getNeighbour(int a){
	int minw=5000;
	for(int i=0;i<fcnt;i++){
		if(graph[a][i]>0){
			if(minw>fwdMap[i]){
				minw = fwdMap[i];
			}
		}
	}
	graph[a][revMap[minw]-1]--;
	graph[revMap[minw]-1][a]--;
	return revMap[minw]-1;
}
void find_tour(int i){
	if(neighbours(i)<1){
		tour[cp++]=i;
	} else {
		while(neighbours(i)>0){
			int j = getNeighbour(i);
			// delete  edges (j,i)
			find_tour(j);
		}
		tour[cp++]=i;

	}
}
bool min_is_greater(){
	for(int i=N;i>=0;i--){
		if(fwdMap[mint[i]]>fwdMap[tour[i]]){
			return true;
		} else if(fwdMap[mint[i]]<fwdMap[tour[i]]){
                        return false;
                }
	}
	return false;
}
int main() {
	fin >>N;
	for(int i=0;i<N&&i<501;i++){
		cnt[i]=0;
	}
	for(int i=0;i<N;i++){
		int s,t;
		fin>>s;
		fin>>t;
		if(revMap[s]==0){
			revMap[s]=fcnt+1;
			fwdMap[fcnt++]=s;
		}
		if(revMap[t]==0){
			revMap[t]=fcnt+1;
			fwdMap[fcnt++]=t;
		}
		s = revMap[s]-1;
		t = revMap[t]-1;
		deg[s]++;deg[t]++;
		graphc[s][t]++;
		graphc[t][s]++;
	}
	int alleven=1;
	for(int i=0;i<fcnt;i++){
		if(deg[i]%2==1){
			alleven=0;
		}
	}
	for(int a=0;a<fcnt;a++){
                for(int i=0;i<fcnt;i++){
                   for(int j=0;j<fcnt;j++){
                         graph[i][j] = graphc[i][j];
                   }
                }
		cp=0;
		if((!alleven)&&deg[a]%2==0){
			continue;
		}
		find_tour(a);
/*
for(int i=N;i>=0;i--){
   printf("%d ",fwdMap[tour[i]]);
}
printf("\n");
*/
		if(ci==1){
			for(int i=N;i>=0;i--){
				mint[i]=tour[i];
			}
		} else {
			if(min_is_greater()){
				for(int i=N;i>=0;i--){
					mint[i]=tour[i];
				}
			}
		}
		ci++;
	}
	for(int i=N;i>=0;i--){
		fout<<(fwdMap[mint[i]])<<"\n";
	}
	return 0;
}

