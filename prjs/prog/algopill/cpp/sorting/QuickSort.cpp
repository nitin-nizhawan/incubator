#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;


#define VI vector<int>
void print_r(VI v){
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<", ";
  }
}
int partition(VI &v,int s, int e){
    while(s!=e){
        while(s!=e&&v[e]>=v[s]){ e--; }
        if(s!=e){
            int tmp = v[e];
            v[e] = v[s];
            v[s]=tmp;
        }
        while(s!=e&&v[s]<=v[e]){ s++ ;}
        if(s!=e){
            int tmp=v[e];
            v[e] = v[s];
            v[s] = tmp;
        }
    }
    return s;
}
void  quickSort(VI &v,int n, int q){
  if(n<q){
      int p = partition(v,n,q);
      quickSort(v,n,p-1);
      quickSort(v,p+1,q);
  }
}
VI quickSort(VI &v){
    quickSort(v,0,v.size()-1);
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
int main(){
  int max_size = 10;
  int test_cases = 10;
  for(int i=0;i<test_cases;i++){
      VI t = createRandomArray(10);
      cout<<endl<<"test case "<<i+1<<" : ";
      print_r(t); cout<<endl;
      cout<<"Solution : "; print_r(quickSort(t)); cout<<endl;
  }
}
