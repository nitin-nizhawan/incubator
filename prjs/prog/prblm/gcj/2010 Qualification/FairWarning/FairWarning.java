import java.util.StringTokenizer;
import java.math.BigInteger;
public class FairWarning extends BaseSolution{
	public static void main(String [] args) throws Exception{
		new FairWarning().start(args[0]);
	}
	public String solveTestCase()  throws Exception{
		setLogToConsole(true);
		StringTokenizer st  = new StringTokenizer(readLine());
		int N = Integer.parseInt(st.nextToken());
		BigInteger ti [] = new BigInteger[N];
		for(int i=0;i<N;i++){
			ti[i] = new BigInteger(st.nextToken());
		}
		BigInteger savedNum = new BigInteger(ti[0].toString());
		log("saved Num = " + savedNum);
		calcMaxPossibleGCD(ti);
		BigInteger T = calcArrayGCD(ti);
		log("max GCD = "+T);
                BigInteger remainder = savedNum.remainder(T);
		log("remainder = "+remainder);
		BigInteger y = T.subtract(remainder).remainder(T);
		return y.toString();
	}
        private void calcMaxPossibleGCD(BigInteger ti[]){
		for(int i=0;i<ti.length-1;i++){
                      ti[i] = maxPossibleGCD(ti[i],ti[i+1]);
		}
	}
	private BigInteger maxPossibleGCD(BigInteger a,BigInteger b){
		if(a.compareTo(b)>0){
			return a.subtract(b);
		}
		else
		{
			return b.subtract(a);
		}
	}
	private BigInteger calcArrayGCD(BigInteger [] ti){
		BigInteger retVal = new BigInteger("0");
		for(int i=0;i<ti.length-1;i++){
                   retVal = retVal.gcd(ti[i]);
		}
		return retVal;

	}
}
