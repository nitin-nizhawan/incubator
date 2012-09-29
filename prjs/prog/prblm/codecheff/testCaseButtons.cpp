#include<iostream>
#include<cstdlib>
using namespace std;
int row[10004];
int grid[1004][1004];
void genTestCase(){
	int n =  500+rand()%500;
	cout<<n<<endl;
    // random row array
    for(int i=0;i<10001;i++){
       row[i]=rand()%2;
    }
    for(int i=0;i<n;i++){
	    grid[i][0]=rand()%2;
	    cout<<grid[i][0];
	    for(int j=1;j<n;j++){
		    grid[i][j]=rand()%2;
                cout<<" "<<grid[i][j];
	    }
	    cout<<endl;
    }
    for(int i=0;i<n;i++){
       int pattern = rand()%2;
       cout<<(grid[i][0]^(pattern^row[0]));
       for(int j=1;j<n;j++){
	       cout<<" "<<(grid[i][j]^(pattern^row[j]));
       }
       cout<<endl;
    }
}
int main(){
	int T=10;
	cout<<T<<endl;
	while(T--){
		genTestCase();
	}
}
