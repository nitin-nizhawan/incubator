#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;


#define VI vector<int>
VI insertionSort(VI &v){
  for(int i =1;i<v.size();i++){
      int location =i - 1;
      int val = v[i];
      while(location>=0&&v[location]>val){
           v[location+1] = v[location];
           location --;
      }
      v[location+1]=val;
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
      cout<<"Solution : "; print_r(insertionSort(t)); cout<<endl;
  }
}
