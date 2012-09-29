#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;


#define VI vector<int>
VI bubbleSort(VI &v){
  int numPairs = v.size();
  bool swapped = true;
  while(swapped){
      numPairs--;
      swapped=false;
      for(int i=0;i<numPairs;i++){
           if(v[i]>v[i+1]){
               int tmp = v[i];
               v[i] = v[i+1];
               v[i+1] = tmp;
                swapped = true;
           }
      }
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
      cout<<"Solution : "; print_r(bubbleSort(t)); cout<<endl;
  }
}
