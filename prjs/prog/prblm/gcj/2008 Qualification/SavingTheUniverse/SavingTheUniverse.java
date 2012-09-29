import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
public class SavingTheUniverse
{
   public static void main(String [] args) throws Exception
   {
       SavingTheUniverse stu = new SavingTheUniverse();
       stu.readProblem(args[0]);
   }
   public int solve(int sq[],int noOfSearchEngines)
   {
       int switchCount =0;
        int max_engines = noOfSearchEngines;
        boolean flag_ar []  = new boolean [max_engines];
        for(int z = 0;z<sq.length;z++)
        {
            if(sq[z]>-1)
            {
                if(flag_ar[sq[z]]!=true) 
                {
                   if(max_engines <2) // we need to start a new segment and make a switch
                   {
                      switchCount++;
                      max_engines = noOfSearchEngines;
                      flag_ar = new boolean [max_engines];
                   }   
                      
                      max_engines --;
                      flag_ar[sq[z]]=true;       
                   
                   
                }
                
            }  
        }
        return switchCount;
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
        int num_search_engines = Integer.parseInt(br.readLine());
        HashMap searchIndex = new HashMap();
        for(int j=0;j<num_search_engines;j++)
        {
           searchIndex.put(br.readLine().trim(),j+"");
        }
        int num_search_queries = Integer.parseInt(br.readLine());
        int searchqueries [] = new int[num_search_queries];
        for(int k=0;k<num_search_queries;k++)
        {
           String qName = br.readLine().trim();
           Object indexObj = searchIndex.get(qName);
           if(indexObj!=null)
           {
               int indexInt = Integer.parseInt((String)indexObj);
               searchqueries[k]=indexInt;
           }
           else
           {
               searchqueries[k]=-1;
           }
        }
        
       
        pw.println("Case #"+(i+1)+": "+solve(searchqueries,num_search_engines));
     }
     pw.close();
   }
   
}