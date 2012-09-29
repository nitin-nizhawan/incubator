import java.util.StringTokenizer;
public class CropTriangles extends BaseSolution {  
   public static void main(String args[]) throws Exception { 
      CropTriangles obj = new CropTriangles();
         obj.start(args[0]);  
         obj.setDebugMode(true);
         obj.setLogToConsole(false);
   } 
// solution logic 
public String solveTestCase() throws Exception {
  //TODO: write your logic here 

  StringTokenizer st = new StringTokenizer(readLine());
  int n = Integer.parseInt(st.nextToken());
  long A = Long.parseLong(st.nextToken());
  long B = Long.parseLong(st.nextToken());
  long C = Long.parseLong(st.nextToken());
  long D = Long.parseLong(st.nextToken());
  long []  x = new long[n];
  long []  y = new long[n];
  long []  xr = new long[]{0,0,0}; // count of how many X's are in 0,1,2 modulo 3
  long []  yr = new long[]{0,0,0};
  x[0]= Long.parseLong(st.nextToken());
  y[0] = Long.parseLong(st.nextToken());
  long M = Long.parseLong(st.nextToken());
  xr[(int)(x[0]%3)]++;
  yr[(int)(y[0]%3)]++;
  for(int i=1;i<n;i++){
     x[i] = (A*x[i-1]+B)%M;
     xr[(int)(x[i]%3)]++;
     y[i] = (C*y[i-1]+D)%M;
     yr[(int)(y[i]%3)]++;
  }
 
  long maxx=0,maxy=0;
  long ans= 0;
  for(int j=0;j<n;j++){
	  maxx+=calcMax(j,x,xr);
	  maxy+=calcMax(j,y,yr);
	  ans+=Math.min(maxx,maxy);
  } 
  return ""+ans;//Math.min(ansx,ansy);
 } 
 private long C2(long val){
    if(val<2){
	    return 0;
    }
    return (val*(val-1))/2;
 }
 private long C1(long val){
	 if(val<1){
		 return 0;
	 }
	 return val;
 }
 private long calcMax(int j,long [] p,long [] pr){
     int pvm = (int)(p[j]%3);
     pr[pvm]--; // remove this point so that its not counted twice

     return  C2(pr[pvm])+C1(pr[(pvm+1)%3])*C1(pr[(pvm+2)%3]);
 }
} 
