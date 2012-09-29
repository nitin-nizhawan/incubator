#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;


#define VI vector<int>

int max_val(VI v){
 int max  = 0;
 for (int i=0;i<v.size();i++){
     if(v[i]>max){
         max = v[i];
     }
 }
 return max;
}

int num_digits(int n,int b){
    int retVal = 0;
    while(n>0){
        n/=b; 
        retVal++;
    }
    return retVal;
}

/**
 * Sorting algo traced
 * input:  [23,17,56,98,1,6,13,33,27], max_num = 56, max_num_digits=2;
 * first pass for ones place
 *     bucket[0-9] = [0,1,0,3,0,0,2,2,1,0], cumulative = [0,1,1,4,4,4,6,8,9,9]
 *                         27, nth_digit = 7, --bucket[nth_digit] :: 7
 *                         33, nth_digit = 3, --bucket[nth_digit] :: 3
 *                         13, nth_digit = 3, --bucket[nth_digit] :: 2
 *                         6,  nth_digit = 6, --bucket[nth_digit] :: 5
 *                         1,  nth_digit = 1, --bucket[nth_digit] :: 0
 *                         98, nth_digit = 8, --bucket[nth_digit] :: 8
 *                         56, nth_digit = 6, --bucket[nth_digit] :: 4
 *                         17, nth_digit = 7, --bucket[nth_digit] :: 6
 *                         23 ,nth_digit = 3, --bucket[nth_digit] :: 1
 *                         after buff[--bucket[nth_digit]] = v[i] for all, buff = [1,23,13,33,56,6,17,27,98] --  sorted by ones digit
 * first pass for ones place ends
 * sec pass for tens place
 *     bucket[0-9] = [2,2,2,1,0,1,0,0,0,1], cumulative = [2,4,6,7,7,8,8,8,8,9]
 *                         98, nth_digit = 9, --bucket[nth_digit] :: 8
 *                         27, nth_digit = 2, --bucket[nth_digit] :: 5
 *                         17, nth_digit = 1, --bucket[nth_digit] :: 3
 *                          6, nth_digit = 0, --bucket[nth_digit] :: 1
 *                         56, nth_digit = 5, --bucket[nth_digit] :: 7
 *                         33, nth_digit = 3, --bucket[nth_digit] :: 6
 *                         13, nth_digit = 1, --bucket[nth_digit] :: 2
 *                         23, nth_digit = 2, --bucket[nth_digit] :: 4
 *                          1, nth_digit = 0, --bucket[nth_digit] :: 0
 *                         after buff[--bucket[nth_digit]] = v[i] for all, buff = [1,6,13,17,23,27,33,56,98] --  sorted by ones digit, sorting complete
 *
 * sec pass for tens place ends
 */
VI radixSort(VI &v){
  int base = 10;
  VI bucket;
  bucket.resize(base);
  VI buff;
  buff.resize(v.size());
  int exp =1;
  int max_num = max_val(v);
  int max_num_digits = num_digits(max_num,base);
  while(max_num_digits>0){ // for each decimal place
     // clear bucket
     for(int i=0;i<base;i++){
         bucket[i]=0;
     }
     for(int i=0;i<v.size();i++){  // fill bucket
         int nth_digit =(v[i]/exp)%base;
         bucket[nth_digit]++;
     }
    
     for(int i=1;i<base;i++){ // cumulative bucket sizes from 0-9
         bucket[i]+=bucket[i-1];
     }
  
     for(int i=v.size()-1;i>=0;i--){ // sort, place in buff
         int nth_digit =(v[i]/exp)%base;
         buff[--bucket[nth_digit]]=v[i];
     }
     // copy from buffer

     for(int i=0;i<v.size();i++){
         v[i] = buff[i];
     }
     
     exp*=base;
     max_num_digits--;
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
      cout<<"Solution : "; print_r(radixSort(t)); cout<<endl;
  }
}
