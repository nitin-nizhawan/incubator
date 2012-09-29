#include <iostream>
using namespace std;
long sign [101][101];

void setsign(int n){
	int val = n;
	for(int i=2;n>1;i++){
		sign[val][i]=0;
		while(n%i==0){
			sign[val][i]++;
			n/=i;
		}
	}

}
bool equal(int i,int j){
	long isign[101];
	long jsign[101];
	for(int k=0;k<101;k++){
		isign[k]=sign[i][k]*j;
		jsign[k]=sign[j][k]*i;
	}
	for(int l=2;l<=100;l++){
		if(isign[l]!=jsign[l]){
			return 0;
		}
	}
	return true;
}
long prodsign[99*99][101];
long [] calcsign(int i,int j){
        for(int k=2;k<101;k++){
		ijsign[i*99+j][k] = sign[i][k]*j;
	}

}
int main(){
	for(int k =2;k<=100;k++){
	setsign(k);
	}
	// find pairs
	int count = 0;
	for(int i=2;i<=100;i++){
		for(int j=2;j<=100;j++){
			calcsign(i,j); // calc sign of i^j;

		}
	}
	cout<<99*99-count<<endl;
}
