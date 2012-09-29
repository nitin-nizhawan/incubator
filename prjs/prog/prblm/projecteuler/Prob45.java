public class Prob45{
	public static void main(String args[]){
		long ts = 40755;
		for(long i=286;i<1000000;i++){
			ts=ts+i;
			long sqrt = (long) Math.sqrt(24*ts+1);
			if(isPS(24*ts+1)&&isPS(8*ts+1)){
                             long sqrth1 = (long) Math.sqrt(8*ts+1)+1;
			     long sqrtp1 = (long) Math.sqrt(24*ts+1)+1;
			     if(sqrth1%4==0&&sqrtp1%6==0){
				System.out.println(ts);
			     }
			}
		}



	}
	static boolean isPS(long n){
		long sqrt = (long) Math.sqrt(n);
		return sqrt*sqrt == n;
	}
}
