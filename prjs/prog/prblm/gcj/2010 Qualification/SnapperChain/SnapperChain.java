import java.util.StringTokenizer;

public class SnapperChain extends BaseSolution {
	public static void main(String [] args) throws Exception {
		new SnapperChain().start(args[0]);
	}
	public String solveTestCase() throws Exception{
		StringTokenizer st = new StringTokenizer(readLine());
		long N = Integer.parseInt(st.nextToken());
		long K =Integer.parseInt(st.nextToken());
		if(isON(N,K)){
                   return "ON";
		} else {
			return "OFF";
		}
	}
	private boolean isON2(long N,long K){
		if(N==0){
			return true;
		}
		if(K==0){
			return false;
		}
		long minSnaps = Math.round(Math.pow(2,N))-1;
		long q = (K/minSnaps)%minSnaps;
		long r = K%minSnaps;
		if(q == ((r+1)%minSnaps)){
			return true;
		}
		return false;
	}
	private boolean isON(long N,long K){
		log("N,K = " +N+","+K);
		if(N==0){
			return true;
		}
		if(K==0){
			return false;
		}
		long tmp=1;
		log("tmp = "+tmp);
		tmp = tmp << N;
		log("tmp = "+tmp);
		tmp = tmp - 1;
		log("tmp = "+tmp);
		log("(k+1)&tmp = "+((K+1)&tmp));
		if(((K+1)&tmp)==0){
			return true;
		}
		return false;
                
	}

}
