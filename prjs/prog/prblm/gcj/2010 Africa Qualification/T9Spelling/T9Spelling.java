import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class T9Spelling
{
   int [][] keycode = new int[][]{
                                                     {2,2},{2,22},{2,222},           {3,3},{3,33},{3,333},
                         {4,4},{4,44},{4,444},          {5,5},{5,55},{5,555},           {6,6},{6,66},{6,666},
                         {7,7},{7,77},{7,777},{7,7777},    {8,8},{8,88},{8,888},           {9,9},{9,99},{9,999},{9,9999},
                                                          {0,0}
                 };
   
   public static void main(String [] args) throws Exception	
   {
       T9Spelling ts = new T9Spelling();
       ts.readProblem(args[0]);
   }
   public void readProblem(String path) throws Exception{
     BufferedReader br=null;
     br =  new BufferedReader(new FileReader(path));
     PrintWriter pw = new PrintWriter(new FileWriter("Output.txt"));
     String numtestcaseStr = br.readLine();
     int num_tests = Integer.parseInt(numtestcaseStr);
     System.out.println("num_tests: "+num_tests);
     for(int i=0;i<num_tests;i++)
     {
         String message = br.readLine();
         pw.println("Case #"+(i+1)+": "+getKeySequence(message));
     }
     pw.close();
   }
   private String getKeySequence(String msg)
   { 
        String out ="";
        int key = -1;
        for(int i=0;i<msg.length();i++)
        {
            int index = 0;
            
            if(msg.charAt(i)==' ')
            {
              index = 26;
            }
            else
            {
                index = msg.charAt(i)-'a'; 
            }

            int tkey = keycode[index][0];
            if(tkey==key)
            {
                 out+=" ";
            }
            key = tkey;
            out+=""+keycode[index][1];
              
        }
        return out;
   }

}