import java.util.StringTokenizer;
import java.util.HashMap;
import java.math.BigDecimal;
public class Numbers extends BaseSolution {
   public static void main(String args[]) throws Exception { 
      Numbers obj = new Numbers();
         obj.start(args[0]);  
         obj.setDebugMode(true);
         obj.setLogToConsole(false);
   } 
// solution logic 
//
public String solveTestCase() throws Exception {
  //TODO: write your logic here 
  long N = Long.parseLong(readLine());
  BigDecimal num = BigDecimal.valueOf(3.0+Math.pow(5.0,0.5));
  BigDecimal val = new BigDecimal(1.0);
  while(N>0){
	  if(N%2!=0){
                val = val.multiply(num);
		N = N-1;
	  }
	  num = num.multiply(num);
	  N = N/2;
	  log(N+" "+num+" "+val);
  }
  log(""+val);
  String retStr = "000"+val;
  if(retStr.indexOf(".")>-1){
	  retStr = retStr.substring(0,retStr.indexOf("."));
  }
  return retStr.substring(retStr.length()-3);
 }
 
} 
