#include<iostream>
using namespace std;



// function to generate FareySeries
void genFareySeries(long long n){
    long long a=0,b=1,c=1,d=n;
   while(c<n){
    long long k = (n+b)/d;
    long long tc = c;
    long long td = d;
    c = k*c - a;
    d = k*d - b;
    a = tc;
    b = td;
    cout<<a<<"/"<<b<<" ";
   }
}


// solve the prob

long long gcd(long m,long n){
   long long r = m%n;
   while(r>0){
       m = n; n = r;
       r = m%n;
   }
   return n;
}

void solve(long long n){
// at n = 8 , fraction just before 3/7 is 2/5

long long tn = 3;
long long td = 7; 
long long ln = 2; //last numerator
long long ld = 5; // last denominator
long long tmpln, tmpld;
long long reducer;
for(long long i=9;i<=n;i++){

tmpln = ln + tn;
tmpld = ld + td;
reducer = gcd(tmpln,tmpld);
tmpln = tmpln/reducer;
tmpld = tmpld/reducer;
if(tmpld<=i){
ln = tmpln;
ld = tmpld;
}
cout<<ln<<"/"<<ld<<endl;

}

}

int main(){
   long long max_num = 1000000l;
   solve(max_num);  

  //for(int i=3;i<21;i++){
//  cout<<endl;  genFareySeries(i);
 // }
}
