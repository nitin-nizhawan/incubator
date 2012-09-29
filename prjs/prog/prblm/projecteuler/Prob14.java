class Prob14{
static long len(long n){
long r=0;
while(n>1){
n =((n&1)==0)?n=n>>1:3*n+1;
r++;
}
return r;
}
static long maxseq(long n){
long l=0,m=0;
for(long i=3;i<n;i+=2){
long t=len(i);
if(t>l){l=t; m=i; }
}
return m;
}
public static void  main(String args[]){
	long time  = System.currentTimeMillis();
	System.out.println(maxseq(1000000)+" in "+(System.currentTimeMillis()-time)+" ms");
	
}
}

