import java.math.BigInteger;
import java.util.StringTokenizer;
public class ThemePark extends BaseSolution {
	public String solveTestCase() throws Exception{
                setLogToConsole(true);
		StringTokenizer st = new StringTokenizer(readLine());
		long R = Long.parseLong(st.nextToken());
		long k = Long.parseLong(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(readLine());
		long groups[] = new long[N];
		for(int i=0;i<N;i++){
			groups[i] = Long.parseLong(st.nextToken());
		}
		BigInteger totalRevenue = new BigInteger("0");
		long maxPerRound = k;
		int cGroup = 0;
		long moneyThisRound = 0;
		long cacheVal[]  = new long[N];
		int cacheIndex [] = new int[N];
		prepareCache(cacheVal,cacheIndex,k,groups);
		for(long r=0;r<R;r++){
		  	// for each round
		  moneyThisRound = 0;
                  moneyThisRound+=cacheVal[cGroup];
		  cGroup = cacheIndex[cGroup];
		  totalRevenue = totalRevenue.add(new BigInteger(moneyThisRound+""));
	            
		}
                log(totalRevenue.toString());
		return totalRevenue.toString();
	}
	private void prepareCache(long [] cv, int[] ci, long k,long [] groups){
		int N = groups.length;
		for(int i=0;i<cv.length;i++){
			   int tmp=i;
                           long val = 0;
		   int counter=0;
                   while(val<k&&counter<cv.length){
			   if((val+groups[tmp%N])<=k){
                                val+=groups[tmp%N];
				tmp = (tmp+1)%N;
				counter++;
			   }
			   else{
				   break;
			   }

		   }
		   cv[i]=val;
		   ci[i]=tmp;
		}
	}
}
