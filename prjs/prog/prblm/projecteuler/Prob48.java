public class Prob48{
	public static void main(String args[]){
		long max = 1000;
		long mod = 10000000000l;
		long sum = 0;
		for(int i=1;i<=max;i++){
			long val=i;
			long prod = 1;
			for(int p=1;p<=i;p++){
                           prod = (prod*val)%mod;
			}
			sum=(sum+prod)%mod;
		}
		System.out.println(sum);
	}
}
