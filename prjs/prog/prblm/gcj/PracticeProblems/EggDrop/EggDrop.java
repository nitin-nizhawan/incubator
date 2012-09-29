import java.util.StringTokenizer;

public class EggDrop extends BaseSolution{
	public static void main(String args[]) throws Exception{
		new EggDrop().start(args[0]);
	}
	public String solveTestCase() throws Exception{
		setLogToConsole(true);
		StringTokenizer st = new StringTokenizer(readLine());
		int F = Integer.parseInt(st.nextToken());
		int D = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		return findMaxF(D,B)+" "+findMinD(F,B)+" "+findMinB(F,D);
	}
	private int findMaxF(int D,int B){
		return 0;
	}
	private int findMinD(int F,int B){
		int ln = 31;
		for(int i = 31;getBitAt(F,i)<1;i--)
		{
			log("bit pos for F = "+F+"bits "+getBitAt(F,i));
                	ln--;
		}
		return ln;
	}
	int getBitAt(int F,int i){
		return F&(int)Math.round(Math.pow(2,i));
	}
	private int findMinB(int F,int D){
		return findMinD(F,D)-1;
	}
		
}
