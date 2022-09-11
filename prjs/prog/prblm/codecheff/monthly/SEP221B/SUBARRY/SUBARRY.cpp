#include <iostream>
using namespace std;
int N;
long A[100005];
void solve(){
 cin>>N;
 int i=0;
 long min,max;
 while(i<N){
	 cin>>A[i];
	 if(i==0){
		 min = A[i];
		 max = A[i];
	 } else {
		 if(A[i] < min){
			 min = A[i];
		 }else if(A[i]>max){
                       max = A[i];
		 }
	 }
	 i++;
 }
 long max_pos = min*min;
 if(max*max > max_pos){
   max_pos = max*max;
 }
 
 long min_pos = min*min;
 if(min*max < min_pos){
    min_pos = min*max;
 }
 if(max*max < min_pos){
    min_pos = max*max;
 }
 cout<<min_pos<<"  "<<max_pos<<endl;
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

