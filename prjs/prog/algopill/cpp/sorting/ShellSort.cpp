#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;


#define VI vector<int>
void incInsertionSort(VI &v,int inc){
    for(int i=inc;i<v.size();i+=inc){
        int temp = v[i];
        int j = i -inc;
        while(j>=inc&&v[j]>temp){
            v[j+inc]=v[j];
            j = j - inc;
        }
        v[j+inc]=temp;
    }
}
VI shellSort(VI &v){
    int n = v.size();
    int inc = (n%2==0)?n/2:(n+1)/2;
    while(inc > 0) {
        incInsertionSort(v,inc);
        inc = inc/2;
   }
  return v;
}

VI createRandomArray(int max_size){
  int size = 2 + rand()%(max_size-2);
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
    cout<<v[i]<<", ";
  }
}
int main(){
  int max_size = 10;
  int test_cases = 10;
  for(int i=0;i<test_cases;i++){
      VI t = createRandomArray(10);
      cout<<endl<<"test case "<<i+1<<" : ";
      print_r(t); cout<<endl;
      cout<<"Solution : "; print_r(shellSort(t)); cout<<endl;
  }
}
