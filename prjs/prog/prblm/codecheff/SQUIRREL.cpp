#include<iostream>
#include<algorithm>
#include<vector>
#define MYINT long long
using namespace std;
MYINT max_t(vector<MYINT> &T,vector<MYINT> &P,MYINT m,MYINT k){
	MYINT maxt =0;
	for(int i=0;i<m;i++){
		MYINT t = T[i]+(k-1)*P[i];
			if(t>maxt){
				maxt=t;
			}
	}
	return maxt;
}
void solveTestCase(int i){
	MYINT m,n,k,ti,pi;
	cin>>m>>n>>k;
	vector<MYINT> T,P;
	for(int i=0;i<m;i++){
		cin>>ti;
		T.push_back(ti);
	}
	for(int j=0;j<m;j++){
		cin>>pi;
		P.push_back(pi);
	}
	MYINT tMax = max_t(T,P,m,k);


}
int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		solveTestCase(i);
	}
}
