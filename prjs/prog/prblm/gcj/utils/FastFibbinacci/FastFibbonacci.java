import java.math.BigInteger;
public class FastFibbonacci {
	private static final BigInteger fibMat[][] = new BigInteger[][]{
		{
			BigInteger.ONE,
			BigInteger.ONE
		},
		{
			BigInteger.ONE,
			BigInteger.ZERO
		}
	};
	public static void main(String args[]){
		System.out.println(FastFibbonacci.get(new BigInteger(args[0])));
	}
	public static BigInteger get(final int n){
                return calcFib(BigInteger.valueOf((long)n));
	}
	public static BigInteger get(final long n){
		return calcFib(BigInteger.valueOf(n));
	}
	public static BigInteger get(final BigInteger n){
		return calcFib(n);
	}
	private static BigInteger calcFib(final BigInteger n){
		if(n.compareTo(new BigInteger("3"))<0){
			if(n.compareTo(BigInteger.ONE)<0){
				return BigInteger.ZERO;
			}
			return BigInteger.ONE;
		}
		return fastExponentiate(fibMat,n.subtract(BigInteger.ONE))[0][0];
		
        }
	private static BigInteger [][] fastExponentiate(final BigInteger [][] fm,BigInteger N){
		BigInteger [][] retVal = new BigInteger[][]{
			{BigInteger.ONE,BigInteger.ZERO},
			{BigInteger.ZERO,BigInteger.ONE}
		};
		BigInteger x[][]  = fm;
		while(N.compareTo(BigInteger.ZERO)>0){
                   if(N.testBit(0)){  // if odd
			   retVal  = multiplyMatrices(retVal,x);
			   N = N.subtract(BigInteger.ONE);
		   }
		   x = multiplyMatrices(x,x);
		   N = N.shiftRight(1); // divide by two
		}
		return retVal;
	}
	private static BigInteger [][] multiplyMatrices(final BigInteger [][] A,final BigInteger [][] B){
		return new BigInteger[][]{
			{
				A[0][0].multiply(B[0][0]).add(A[0][1].multiply(B[1][0])),
				A[0][0].multiply(B[0][1]).add(A[0][1].multiply(B[1][1]))
		       	},
			{
				A[1][0].multiply(B[0][0]).add(A[1][1].multiply(B[1][0])),
				A[1][0].multiply(B[0][1]).add(A[1][1].multiply(B[1][1]))
		       	}
		};
	}
}
