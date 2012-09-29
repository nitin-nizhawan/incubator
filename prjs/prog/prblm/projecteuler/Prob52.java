public class Prob52{
	public static void main(String args[]){
		for(long i=1;i<10000000;i++){
		  long val [] =new long[] {2*i,3*i,4*i,5*i,6*i};
		  long ss [] = new long[5] ;
		  for(int k=0;k<5;k++){
			  ss[k] = d(val[k]);
		  }
	          if(ss[0]%9==ss[1]%9&&ss[1]%9==ss[2]%9&&ss[2]%9==ss[3]%9&&ss[3]%9==ss[4]%9){
		   	  
			  System.out.println(val[0]+" "+val[1]+" "+val[2]+" "+val[3]+" "+val[4]);
		  }
		}
	}
	static long d(long n){
		long sum=0;
                while(n>0){
			sum+=n%10;
			n/=10;
		}
		return sum;
	}
}
