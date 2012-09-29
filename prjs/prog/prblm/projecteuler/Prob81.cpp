#include<iostream>
using namespace std;
long long INFINITY = 1<<31;
int main(){
 long long mat[80][80];
 for(int i=0;i<80;i++){
  for(int j=0;j<80;j++){
    cin>>mat[i][j];
    
  }
 }
 for(int l=0;l<80;l++){
   for(int k=0;k<80;k++){
     long long min_parent =-1; // infinity
     if(l+k>0){
         if(l>0){
            // top parent l-1;
            min_parent = mat[l-1][k];
         } 
         if(k>0){
             // left parent;
             if(l<1||mat[l][k-1]<min_parent){ // either top parent does not exist or left parent is less than top parent
                 min_parent = mat[l][k-1];
             }
         }
             mat[l][k]+=min_parent;   
     }
   }
 }

cout<<mat[79][79];


}
