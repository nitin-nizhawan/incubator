import java.util.StringTokenizer;
import java.util.Arrays;
public class MilkShakes extends BaseSolution {  
   public static void main(String args[]) throws Exception { 
      MilkShakes obj = new MilkShakes();
	 obj.start(args[0]);  
         obj.setDebugMode(true);
         obj.setLogToConsole(false);
   } 
// solution logic 
public String solveTestCase() throws Exception {
  //TODO: write your logic here 
  int N = Integer.parseInt(readLine());
  int M = Integer.parseInt(readLine());
  boolean [] satisfied = new boolean[M];
  int flavorlist [] [] = new int [M][];
  int unsatisfiedCustomers = M; // all customers are unsatified
  boolean malted [] =  new boolean[N];
  for(int i=0;i<M;i++){
	  StringTokenizer  st = new StringTokenizer(readLine());
	  int likesflavors = Integer.parseInt(st.nextToken());
	  flavorlist[i] = new int[likesflavors];
	  for(int j=0;j<likesflavors;j++){
		 int flavor = Integer.parseInt(st.nextToken());
		 int maltedornot = Integer.parseInt(st.nextToken());
		 flavorlist[i][j]=(1-2*maltedornot)*flavor;
		 if(maltedornot>0){
		       if(likesflavors==1){
			       malted[flavor-1]=true;
			       unsatisfiedCustomers--;
			       satisfied[i] = true;
		       }
		 }
	  }
  }
  for(int l=0;l<M;l++){
	  if(!satisfied[l]){ // if it is not already satisfied by malted
	     for(int m=0;m<flavorlist[l].length;m++){
		     int flavor = flavorlist[l][m];
		     if(flavor<0&&malted[(-1*flavor)-1]==true){ // likes malted and we have malted
                        satisfied[l] = true;
			unsatisfiedCustomers--;
			break;
                       
		     } else if(flavor>0&&malted[flavor-1]==false) {
                        satisfied[l] = true;
			unsatisfiedCustomers--;
			break;
		     }
	     }
	  }
  }
  if(unsatisfiedCustomers>0){
  return "IMPOSSIBLE";
  } else {
	  String retVal = "";
	  for(int k=0;k<malted.length;k++){
		  if(malted[k]){
			  retVal+="1 ";
		}
		else{
			retVal+="0 ";
		}
	  }
	  return retVal.trim();
  }
 }
} 
