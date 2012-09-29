#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;


#define VI vector<int>
#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)

// assumes that heaps at left(i) and right(i) are max heaps
void fixHeap(VI &v,int i,int size){
  while(i<size){
    int largest = i;
    if(LEFT(i)<size&&v[LEFT(i)]>v[largest]){
        largest = LEFT(i);
    }
    if(RIGHT(i)<size&&v[RIGHT(i)]>v[largest]){
        largest = RIGHT(i);
    }
    if(largest!=i){  // heap at i is not a proper heap as expected
        // fix it by swapping
        int tmp = v[i];
        v[i] = v[largest];
        v[largest] = tmp;
        i = largest; // now we will fix heap at larget i.e the child heap
    } else {
      break; // only way to end the loop
    }
     
  }
}
VI heapSort(VI &v){
  for(int i=(v.size()-1)/2;i>=0;i--){
      fixHeap(v,i,v.size());
  }
  int size = v.size();
  for(int i=0;i<v.size();i++){
      int tmp = v[0];
      v[0] = v[size-1];
      v[size-1]=tmp;
      fixHeap(v,0,size-1);
      size--;
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
      cout<<"Solution : "; print_r(heapSort(t)); cout<<endl;
  }
}
