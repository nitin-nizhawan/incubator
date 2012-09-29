import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class ReverseWords
{
   public static void main(String [] args) throws Exception
   {
    ReverseWords rw = new ReverseWords();
    rw.readProblem(args[0]); 
   }
   public void readProblem(String path) throws Exception
   {
      BufferedReader br=null;
     br =  new BufferedReader(new FileReader(path));
PrintWriter pw = new PrintWriter(new FileWriter("Output.txt"));

     String numtestcaseStr = br.readLine();
     int num_tests = Integer.parseInt(numtestcaseStr);
      System.out.println("num_tests "+num_tests);
     for(int i=0;i<num_tests;i++)
     {
          String prob = br.readLine().trim();
          String sol = solve(prob);
          pw.println("Case #"+(i+1)+": "+sol);
     }
     pw.close();
   }
   private void swap(byte [] in,int a,int b)
   {
      byte temp = in[a];
      in[a] = in[b];
      in[b] = temp;
   }
   private void reverse(int start,int end,byte [] in){
     while(end - start>0){
        
        swap(in,start,end);
        start++;
        end --;
     }
   }
   private String solve(String prob)
   {
      byte [] bStr = prob.getBytes();
      byte blank = " ".getBytes()[0];
      reverse(0,bStr.length-1,bStr);
      int wstart=0;
      int wend =0;
      for(int i=0;i<bStr.length;i++)
      {
         if(bStr[i] == blank)
         {
            reverse(wstart,i-1,bStr);
            wstart = i+1;
         }
      }
      reverse(wstart,bStr.length-1,bStr);
      return new String(bStr);
   }
}