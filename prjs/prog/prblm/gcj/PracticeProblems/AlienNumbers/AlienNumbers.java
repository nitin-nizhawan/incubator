import java.util.StringTokenizer;

public class AlienNumbers extends BaseSolution{
	public static void main(String args[]) throws Exception{
	     new AlienNumbers().start(args[0]);
	}
	public String solveTestCase() throws Exception{
		StringTokenizer st = new StringTokenizer(readLine());
		String numberStr = st.nextToken();
		String sourceStr = st.nextToken();
		String targetStr = st.nextToken();
		long decimal = convertToDecimal(numberStr,sourceStr);
		String solution = convertFromDecimal(decimal,targetStr);
		return solution;
	}
	private long convertToDecimal(String numberStr,String sourceStr){
		long retVal = 0;
		for(int i=0;i<numberStr.length();i++){
			long base = sourceStr.length();
                        long placeValue = Math.round(Math.pow(base,i));
			long symbolValue = sourceStr.indexOf(numberStr.charAt(numberStr.length()-1-i)+"");
			retVal+=placeValue*symbolValue;
		}
		return retVal;
	}
	private String convertFromDecimal(long decimal,String targetStr){
		String retVal="";
		long base = targetStr.length();
		if(decimal==0){
			return targetStr.charAt(0)+"";
		}
                while(decimal>0){
                   long remainder = decimal%base;
		   retVal=targetStr.charAt((int)remainder)+retVal;
		   decimal=decimal/base;
		}
		return retVal;
	}
}
