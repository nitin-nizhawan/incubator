#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;


#define VI vector<int>
void print_r(VI v){
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<", ";
  } cout<<"\n";
}
VI iterativeMergeSort(VI &v){
    VI t;
    t.resize(v.size());
  
    for(int k=1;k<=v.size();k*=2){ // starting with two element subarray
        for(int i=0;i<v.size();i+=2*k){
          int  p=i, q=i+k-1;
          int  r= i+2*k-1;  
            if(r>=v.size()){
                r=v.size()-1;
            }
            if(q>=v.size()){
               q=v.size()-1;
            }
            // copy to aux
            for(int l=p;l<=r;l++){
                t[l]=0+v[l];
            }
            int t1 = p, t2=q+1, f=p;
            while(t1<=q&&t2<=r){
                if(t[t1]<t[t2]){
                    v[f++]=t[t1++];
                } else {
                    v[f++]=t[t2++];
                }
            }
            while(t1<=q){
                v[f++]=t[t1++];
            }
            while(t2<=r){
                v[f++]=t[t2++];
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
int main(){
  int max_size = 10;
  int test_cases = 10;
  for(int i=0;i<test_cases;i++){
      VI t = createRandomArray(10);
      cout<<endl<<"test case "<<i+1<<" : ";
      print_r(t); cout<<endl;
      cout<<"Solution : "; print_r(iterativeMergeSort(t)); cout<<endl;
  }
}
