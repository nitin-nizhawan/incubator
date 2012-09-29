#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
#define VI vector<int>

VI createRandomArray(int max_size){
  int size =max_size;//2 + rand()%(max_size-2);
  VI vec;
  for(int i=0;i<size;i++){
      vec.push_back(i);
  }
  for(int j=0;j<size-1;j++){
      int tmp = vec[j];
      int ri = j+1+rand()%(size-j-1);
      vec[j] =  vec[ri];
      vec[ri]=tmp;
       
  }
  return vec;
}
void print_r(VI v){
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }
}
int main(){
  int max_size = 10;
  int test_cases = 125;
  srand(time(NULL));
  cout<<test_cases<<endl;
  for(int i=0;i<test_cases;i++){
      cout<<endl;
      int m=1+rand()%18;
      int n=1+rand()%1005;
      cout<<n<<" "<<m<<endl;
      for(int j=0;j<n;j++){
          VI t = createRandomArray(m);
          print_r(t); cout<<endl;
      }
  }
}
