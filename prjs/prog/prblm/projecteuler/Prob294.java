import java.math.BigInteger;
public class Prob294{
	public static void main(String args[])throws Exception{
		 BigInteger mul = BigInteger.ONE;
		 int pow = Integer.parseInt(args[0]);
		 BigInteger max = new BigInteger("10").pow(pow);
		 BigInteger nine = new BigInteger("9");
		 BigInteger t3 = new BigInteger("23");
		 System.out.println("guess "+max.divide(new BigInteger("414")));
		 long count=0;
                 for(BigInteger i=new BigInteger("10");mul.compareTo(max)<0;i=i.add(nine)){
			mul=i.multiply(t3);
			if(d(mul).compareTo(t3)==0){
                              //System.out.println("i-1 "+i.subtract(BigInteger.ONE).divide(nine));                
 				count = (count+1)%1000000000l;
			}
	         }
		 System.out.println(count);

             }

	static BigInteger d(BigInteger n){
		BigInteger sum = BigInteger.ZERO;
		BigInteger  ten = new BigInteger("10");
		while(n.compareTo(BigInteger.ZERO)>0){
			sum = sum.add(n.mod(ten));
			n = n.divide(ten);;
		}
		return sum;
	}
}
