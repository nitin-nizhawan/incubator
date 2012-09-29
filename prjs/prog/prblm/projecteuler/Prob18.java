import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
public class Prob18{
	public static void main(String [] args) throws Exception {
         int size = Integer.parseInt(args[0]);
         long data [][]  = new long[size][size];	
	 long sum = 0; 
         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	 for(int i=0;i<size;i++){
		 StringTokenizer st = new StringTokenizer(br.readLine());
		 for(int j=0;j<=i;j++){
			 data[i][j] = Long.parseLong(st.nextToken());
			 if(i!=0){
			    if(j==0){
                                data[i][0]+=data[i-1][0];
			     } else if(j==i){
				     data[i][i]+=data[i-1][i-1];
			     } else {
				     data[i][j]+=Math.max(data[i-1][j-1],data[i-1][j]);
			     }
			 }   
			 if(i==(size-1)){
				 /// last row , track maxsum, we are almost done
                                 if(data[i][j]>sum){
					 sum=data[i][j];
				 }
			 }
		 }
	 }
	 System.out.println(sum);
	 br.close();

	}
}
