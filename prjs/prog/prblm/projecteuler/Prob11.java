class Prob11{
	public static void main(String args[])throws Exception {
           java.io.BufferedReader br = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
	   long data [][] = new long[20][20];
	   for(int i=0;i<20;i++){
           java.util.StringTokenizer st = new java.util.StringTokenizer(br.readLine());
	      for(int j=0;j<20;j++){
		data[i][j ] =   Long.parseLong(st.nextToken());
	      }

	   }
	   System.out.println(findMaxProd(data));
	   br.close();
	}
	static long findMaxProd(long [][] d){
		return 0;
	}
}
