import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class WelcomeToCodeJam
{
   String probs[];
   String sols[];
   String tStr = "welcome to code jam";
   public static void main(String args []) throws Exception
   {
      WelcomeToCodeJam  wtcj = new WelcomeToCodeJam();
      wtcj.readProblem(args[0]);
      wtcj.solve();
      wtcj.writeSolution("Output.txt");
   }
   public void writeSolution(String flname) throws Exception
   {
      PrintWriter pw = new PrintWriter(new FileWriter(flname));
      for(int i=0;i<sols.length;i++)
      {
         pw.println(sols[i]);
      }
      pw.close();
   }
   public void solve(){
      for(int i=0;i<probs.length;i++)
      {
         int num = solveCase(probs[i].toLowerCase());
         System.out.println("Case #"+(i+1)+": "+num);
         sols[i] = "Case #"+(i+1)+": "+getFourDigits(num);
      }
   }
   private void initSubProbs(int [][] sp){
     for(int i=0;i<sp.length;i++){
        for(int j=0;j<sp[i].length;j++){
          
           sp[i][j] = 0;
           if(i == sp.length - 1)
           {
             sp[i][j] = 1;
           }
        }
     }
     
   }
   private int solveCase(String prob){
     // we have to use dynamic programming
    int sol_arr[][] = new int[tStr.length()+1][prob.length()+1];
    initSubProbs(sol_arr);
    for(int i = tStr.length() -1 ;i>=0;i--)   // traverse target str in reverse
    {
       int currentVal = 0;//sol_arr[i][prob.length()];

       for(int j  = prob.length()-1 ;j>=0;j--)  // traverse now problem in reverse and fill the table;
       {
         if(tStr.charAt(i) == prob.charAt(j))
         {
            currentVal = (currentVal + sol_arr[i+1][j+1])%10000;
         }
         sol_arr[i][j] = currentVal;
       }
    }
    
    return sol_arr[0][0];
   }
   private int solveCase2(String prob)
   {
      int ptr = 0;
      int result = 0;
      ptr = prob.indexOf(tStr.charAt(0));
      System.out.println("Problem: "+ prob);
      while(ptr<prob.length()&&ptr>-1)
      {
          int ptr2 = ptr;
          boolean flag = true;
          for(int i=1;i<tStr.length();i++)
          {
              
              ptr2 = prob.indexOf(tStr.charAt(i)+"",ptr2+1); 
              System.out.println("Finding: "+tStr.charAt(i)+", found: "+ptr2);
              if(ptr2<0) 
              {
                flag = false;
                break;
              }         
          }
          if(flag==true)
          {
              result = result +1;
          }
          ptr = prob.indexOf(tStr.charAt(0),ptr+1);
      }
      return result;
   }
   public String getFourDigits(int n)
   {
      String strInt  = "0000"+n;
      strInt = strInt.substring(strInt.length()-4);
      return strInt;
   }
   public void readProblem(String path) throws Exception{
        BufferedReader br=null;
        br =  new BufferedReader(new FileReader(path));
        String numtestcaseStr = br.readLine();
        int num_test_cases = Integer.parseInt(numtestcaseStr);
        probs = new String[num_test_cases];
        sols = new String[num_test_cases];
        for(int i=0;i<probs.length;i++)
        {
           probs[i] = br.readLine().trim();
        }
        
   }
}