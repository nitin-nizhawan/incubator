#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define LONG_VEC  vector<long>
using namespace std;
long sumOfFactors(LONG_VEC vec,long sum=0){
 for(int i=0;i<vec.size();i++){
     sum+=vec[i];
 }
 return sum;
}

LONG_VEC findAllFactors(long i){
 LONG_VEC factors;
 for(long d=1;d<i;d++){
    if(i%d==0){
      factors.push_back(d);
    }
 }
 return factors;
}
bool isAb(long i){
  LONG_VEC allFactors=findAllFactors(i);
  long factorSum = sumOfFactors(allFactors);
  if(factorSum>i){
      return true;
  }
  return false;
}
LONG_VEC  findAllAbundantNumbers(){
   LONG_VEC  vec;
   for(long i=2;i<28123;i++){
      if(isAb(i)){
        vec.push_back(i);
      }
   }
   return vec;
}
int main(){
  LONG_VEC an = findAllAbundantNumbers(); // abundant numbers  
  map<long,bool> absumMap;
  for(int i=0;i<an.size();i++){
     for(int j=0;j<an.size();j++){
         long sum=an[i]+an[j];
         if(sum<=28123){
           absumMap.insert(make_pair(sum,true));
         }
     }
  }
  long totalsum=0;
  map<long,bool>::const_iterator found;
  for(int k=1;k<=28123;k++){
     found = absumMap.find(k);
     if(found==absumMap.end()){
         totalsum+=k;
     }
  }
  cout<<totalsum<<endl;
}
