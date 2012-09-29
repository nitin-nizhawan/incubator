import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.math.BigInteger;
public class Prob13{
	public static void main(String args[]) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BigInteger sum= new BigInteger("0");
		
		for(int i=1;i<=100;i++){
		   BigInteger num = new BigInteger(br.readLine());
		   sum=sum.add(num);
		}
		System.out.println(sum.toString());
		br.close();
	}
}
