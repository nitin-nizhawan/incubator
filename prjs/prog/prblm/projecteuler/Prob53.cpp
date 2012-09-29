#include<iostream>
using namespace std;
long sign [101][101];
void setsign(int n){
	int p=n;
	for(int i=2;i<=100;i++) { sign[n][i]=0; }
	for(int j=2;n>1;j++){
		while(n%j==0){
			n/=j;
			sign[p][j]++;
		}
	}
}

long long pow(long long i,long long n){
	if(i<2) return 1;
	if(n<1) return 1;
	if(n<2) return i;
	long long pown=1;;
	for(int k=1;k<=n;k++){
		pown*=i;
	}
	return pown;
}

long long C(long long N,long long R){
	long long prod=1;
	long sign1[101]  = {0};
	for(int s=R+1;s<=N;s++){
		for(int t=2;t<=100;t++){
			sign1[t] = sign1[t]+sign[s][t];// product is sum;
		}
	}
	long sign2[101] ={0};
        for(int u=2;u<=N-R;u++){
		for(int v=2;v<=100;v++){
                      sign2[v] = sign2[v] + sign[u][v];
		}
	}
	for(int i=2;i<=100;i++){
		sign1[i] = sign1[i]-sign2[i]; // division is subraction of powers  
	//	find final product also here
	   prod=prod*pow(i,(long long)sign1[i]);
	if(prod>1000000||prod<0){
		return prod;
	}
	}
	return prod;
	
}
int main(){
	for(int k=2;k<=100;k++){
	setsign(k);
	}
	long count=0;
	for(int N=20;N<=100;N++){
		for(int R=2;R<N-2;R++){ // skipping some values of R and N as they cannot be more than 1 million;
			long long val = C(N,R);
			cout<<"C("<<N<<" ,"<<R<<") = "<<val<<endl;
			if(val>1000000||val<0){
				count++;
			}
		}
	}
	cout<<count<<endl;
}
