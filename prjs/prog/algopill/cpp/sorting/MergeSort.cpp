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
void merge(VI &v,int st, int ed, int st2, int ed2,VI &c){
    int top1=st;
    int top2=st2;
    int top = st;
    while(top1<=ed&&top2<=ed2){
        if(v[top1]<v[top2]){
            c[top++]=v[top1++];
        } else {
            c[top++]=v[top2++];
        }
    }
    while(top1<=ed){
        c[top++]=v[top1++];
    }
    while(top2<=ed2){
        c[top++]=v[top2++];
    }
    for(int i=st;i<=ed2;i++){
        v[i]=c[i];
    }
}
void mergeSort(VI &v,int st,int ed,VI &c){
    if(ed-st>1){
       mergeSort(v,st,(st+ed)/2,c);
       mergeSort(v,(st+ed)/2+1,ed,c);
    } 
    if(ed-st>0){
        merge(v,st,(st+ed)/2,(st+ed)/2+1,ed,c);
    } else {
        c[st]=v[st];
    }
    
}
VI mergeSort(VI &v){
  VI retVal;
  retVal.resize(v.size());
  mergeSort(v,0,v.size()-1,retVal);
  return retVal;
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
      cout<<"Solution : "; print_r(mergeSort(t)); cout<<endl;
  }
}
