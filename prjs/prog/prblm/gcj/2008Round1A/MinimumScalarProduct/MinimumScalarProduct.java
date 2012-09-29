import java.util.StringTokenizer;
import java.util.Arrays;
import java.math.BigInteger;
public class MinimumScalarProduct extends BaseSolution {  
   public static void main(String args[]) throws Exception { 
      new MinimumScalarProduct().start(args[0]);  
   } 
// solution logic 
public String solveTestCase() throws Exception { 
   //TODO: write your logic here 
  int dim = Integer.parseInt(readLine());
  long vA[] = new long[dim];
  long vB[] = new long[dim];
  StringTokenizer st = new StringTokenizer(readLine());
  StringTokenizer st2 = new StringTokenizer(readLine());
  for(int i=0;i<dim;i++){
	  vA[i] = Long.parseLong(st.nextToken());
	  vB[i] = Long.parseLong(st2.nextToken());
  }
  Arrays.sort(vA);
  Arrays.sort(vB);
  BigInteger sum=new BigInteger("0");
  for(int j=0;j<dim;j++){
     sum=sum.add(new BigInteger(vA[j]*vB[dim-j-1]+""));
  }
  return ""+sum.toString();
 } 
} 
