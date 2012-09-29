/// codes at  http://codepad.org/Nj993pNT 

long runLoop(int d, int times, long num);
long powTen[7] ={1,10,100,1000,10000,100000,1000000}; 
int isCyclicPrime(long num,int d);
int isPrime(long num);
long compute(int d){
  long sum = 0;
  for(int i=1;i<=d;i++){ // calc circular primes in 1,2,3,4,5... digit numbers,
    sum+=runLoop(i,i,0); // run loop i times, for total d digits
  }
  return sum; // we did not count 2, but we counted 1;
}
long runLoop(int d,int times,long num){
  long sum = 0;
  long digits[5] = {1,3,5,7,9};
  
  if(times>0){
   for(int i=0;i<5;i++) {
     sum+=runLoop(d,times-1,num+digits[i]*powTen[d-times]);
   }
  }
  else {
   if(isCyclicPrime(num,d)){
     sum++;
   }
  }
  return sum;
}
int isCyclicPrime(long num,int d){
   
   long max = powTen[d-1];
   for(int i=0;i<d;i++){
     if(!isPrime(num)){
      //cout<<num<<"  is not a circular prime\n";
      return 0;
     } 
     int firstdigit = num%10;
     num= num/10;
     num=num+max*firstdigit;
   }
   //cout<<num<<"  is circular prime\n";
   return 1;
}
int isPrime(long num){
 long sqrtv = (long) sqrt(num);
 for(long i = 3;i<=sqrtv;i+=2){
   if(num%i==0){
     return 0;
   }
 }
 return 1;
}
int main(){
 
 cout<<compute(6);
}

