public class Try{
	public static void main(String args[])throws Exception{

	  int nth  = Integer.parseInt(args[0]);
          long primes [] = new long[nth+5];
	  primes[1]= 2;
	  primes[2] =3;
	  
	  int count = 2;
	  
          long num = 5;
	  long p = primes[count];
		  while(count<nth){
                    if(isP(num,primes,count)){
			    primes[++count]=num;
			    p = num;
		    }
		    num+=2;
		  }
	  System.out.println(p);
	}
	public static boolean isP(long num,long primes [],int count){
		long sqrt = (long) Math.sqrt(num);
		for(int i=2;primes[i]<=sqrt;i++){
			if(num%primes[i]==0){
				return false;
			}
		}
		return true;
	}
}
