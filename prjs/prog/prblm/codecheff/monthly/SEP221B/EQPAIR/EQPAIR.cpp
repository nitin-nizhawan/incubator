#include <iostream>
#include <algorithm>
using namespace std;


int A[100005];
int N;
unsigned long C(unsigned long S){
	if(S < 2) return 0;
    if(S%2==0){
        return (S-1)*(S/2);
    } else {
        return S*((S-1)/2);
    }
}
void solve(){
    cin>>N;
    int i=0;
    while(i<N){
        cin>>A[i];
        i++;
    }
    sort(A,A+N);
    int last = 0;
    i =1;
    unsigned long ans = 0;
    while(i<=N){
        if(i==N || A[i] != A[i-1]){
          int sameCount = i - last;
          ans+= C(sameCount);
          last = i;  
        } 
        i++;
    }
    cout<<ans<<endl;
}
/*
2,5,9,12
5,9
2,5,
2,9,
5,12
*/
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T-- > 0){
	    solve();
	}
	return 0;
}


