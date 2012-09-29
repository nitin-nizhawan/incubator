import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Arrays;
public class StoreCredit
{
   public static void main(String [] args) throws Exception
   {
      StoreCredit sc = new StoreCredit(); 
      sc.readProblem(args[0]);
   }
   public CostObj[] solve(int credit,CostObj [] costs){
        if(costs.length<3)
        {
           return costs;
        }
        for(int i=costs.length - 2;i>=0;i--)
        {
           int value = costs[i+1].val;
           if(value>credit) 
           {
log("continue "+i+" , "+value+" , "+credit);
              continue;
              
           }
           log("cnt,val,credit  "+i+" , "+value+" , "+credit);
           log("searching 0 "+i+" "+(credit-value));
           int index =  binarySearch(0,i,costs,credit-value);
           log("index "+index);
           if(index>-1)
           {
             return new CostObj[]{costs[i+1],costs[index]};
           }
        }
      log("Failed to find");
      return new CostObj[2];
   }
   public void log(String str){
        System.out.println(str);
   }
    
   public int binarySearch(int s,int e,CostObj [] ar, int val)
   {
      int max = e;
      int min = s;
      int mid = (max + min)/2;
      while(1*1==1)
      { 
          log("min,mid,max "+min+" , "+mid+" , "+max);
          int midval = ar[mid].val;
          if(val < midval)
          {
             max = mid-1;
             if(max<min) break;
             mid = (min + max)/2;
          }
          else if(val > midval)
          {
             min = mid+1;
             if(min > max) break;
             mid = (min + max)/2;

          }
          else if(val == midval)
          {
               return mid;
          }
          else if(min == max)
          {
               break;
          }
      } 
      return -1;
   }
   public void readProblem(String path) throws Exception{
     BufferedReader br=null;
     br =  new BufferedReader(new FileReader(path));
     CostObjComparator  coc = new CostObjComparator();
      PrintWriter pw = new PrintWriter(new FileWriter("Output.txt"));
     String numtestcaseStr = br.readLine();
     int num_tests = Integer.parseInt(numtestcaseStr);
     log("num_tests: "+num_tests);
     for(int i=0;i<num_tests;i++)
     {
         log("testcase "+i);
         int credit = Integer.parseInt(br.readLine().trim());
         int num_items = Integer.parseInt(br.readLine().trim());
         log("credit "+credit+" ,num_items" + num_items);
         String costsStr = br.readLine().trim();
         log("costsStr "+costsStr);
         CostObj [] costs = new CostObj[num_items];//new int[num_items];
         StringTokenizer st =  new StringTokenizer(costsStr);
         int counter = 0;
         while(st.hasMoreTokens())
         {
            
            costs[counter] = new CostObj(Integer.parseInt(st.nextToken()),counter);
            counter++;
         }
         Arrays.sort(costs,coc);
         log("ArraystoStr costs "+Arrays.toString(costs));
         
         CostObj [] sol = solve(credit,costs);
         Arrays.sort(sol,new CostObjComparator(true));
         //log("ArraystoStr sol "+Arrays.toString(sol));

         pw.println("Case #"+(i+1)+": "+(sol[0].idx+1)+" "+(sol[1].idx+1));
     }
     pw.close();
     br.close();
   }
 
}

