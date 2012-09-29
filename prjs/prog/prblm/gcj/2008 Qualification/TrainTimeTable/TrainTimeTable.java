import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.PriorityQueue;
import java.util.Arrays;
public class TrainTimeTable
{
  int T_A = 0;
  int T_B = 1;
  PrintWriter dpw;
  public static void main(String [] args) throws Exception
   {
       TrainTimeTable  ttt = new TrainTimeTable();
       ttt.readProblem(args[0]);
   }
 public int convertToMin(String time)
 {
     StringTokenizer st = new StringTokenizer(time,":");
     int hours = Integer.parseInt(st.nextToken());
     int min = Integer.parseInt(st.nextToken());
     return hours*60+min;
 }
 public void readProblem(String path) throws Exception{
     BufferedReader br=null;
     br =  new BufferedReader(new FileReader(path));
     dpw = new PrintWriter(new FileWriter("debug.txt"));
     PrintWriter pw = new PrintWriter(new FileWriter("Output.txt"));
     String numtestcaseStr = br.readLine();
     int num_tests = Integer.parseInt(numtestcaseStr);
     System.out.println("num_tests: "+num_tests);
     for(int i=0;i<num_tests;i++) // for each test
     {
        int tot = Integer.parseInt(br.readLine());
        String noTrips = br.readLine();
        StringTokenizer st = new StringTokenizer(noTrips);
        int NA = Integer.parseInt(st.nextToken());
        int NB = Integer.parseInt(st.nextToken());
        //TrainSchedule ts[] = new TrainSchedule[NA+NB];
        PriorityQueue tsp [] = new PriorityQueue[2];
        tsp[T_A] = new PriorityQueue(NA+NB,new TrainScheduleComparator(true));
        tsp[T_B] = new PriorityQueue(NB+NA,new TrainScheduleComparator(true));
        for(int k=0;k<NA;k++)
        {
           StringTokenizer st2 = new StringTokenizer(br.readLine());
           //ts[k] = 
         tsp[T_A].offer(new TrainSchedule(convertToMin(st2.nextToken()),convertToMin(st2.nextToken())+tot,T_A));
        }
        for(int j=NA;j<NB+NA;j++)
        {
           StringTokenizer st1 = new StringTokenizer(br.readLine());
          // ts[T_B] = 
         tsp[T_B].offer(new TrainSchedule(convertToMin(st1.nextToken()),convertToMin(st1.nextToken())+tot,T_B));
        }
   
        int sol[] = solve(tsp);
        pw.println("Case #"+(i+1)+": "+sol[0]+" "+sol[1]);
     }
     pw.close();
	dpw.close();
    }
    public void printit(PriorityQueue q,String str) throws Exception
    {
	dpw.println(" .....  "+str+" : ....... ");
	dpw.println(" Size "+((q!=null)?q.size():"null"));
	for(java.util.Iterator it = q.iterator();it.hasNext();)
        {
	     TrainSchedule ts = (TrainSchedule) it.next();
	     dpw.println(" { arr = "+ts.arr+" ,dep = "+ts.dep+" , flag = "+ts.flag+" } ");
        }
    }
    public void finalize() throws Exception {

    }    
    public int [] solve(PriorityQueue [] tsp) throws Exception
    {
       int sol [] = new int [2];
       boolean DEPARTURE = true;
       boolean ARRIVAL = false;
       sol[T_A]=0;
       sol[T_B]=0;
       PriorityQueue [] tQ = new PriorityQueue[2];
       tQ[T_A]= new PriorityQueue(tsp[T_B].size()+tsp[T_A].size(),new TrainScheduleComparator(ARRIVAL));
       tQ[T_B] = new PriorityQueue(tsp[T_A].size()+tsp[T_B].size(),new TrainScheduleComparator(ARRIVAL));
       //boolean flat_t [] = new boolean[ts.length];
      // Arrays.sort(ts,new TrainScheduleComparator(DEPARTURE)); 
           
       while(!tsp[T_A].isEmpty()||!tsp[T_B].isEmpty())
       {
	  printit(tsp[T_A],"tsp[T_A]");
	  printit(tsp[T_B],"tsp[T_B]");
          printit(tQ[T_A],"tQ[T_A]");
          printit(tQ[T_B],"tQ[T_B}");	  
          boolean processed = false;
          TrainSchedule earliestTSA = (TrainSchedule) tsp[T_A].peek();
          TrainSchedule earliestTSB = (TrainSchedule) tsp[T_B].peek();
          TrainSchedule availTSA = null;
          TrainSchedule availTSB = null;
          if(!tQ[T_A].isEmpty())
          {
              availTSA = (TrainSchedule) tQ[T_A].peek();
          }
           
          
          if(availTSA!=null&&earliestTSA!=null&&availTSA.arr<=earliestTSA.dep)
          {
             processed = true;
             tQ[T_B].offer(tsp[T_A].poll());
             tQ[T_A].poll();
          }
          if(!tQ[T_B].isEmpty())
          {
              availTSB = (TrainSchedule) tQ[T_B].peek();
          }
          if(availTSB!=null&&earliestTSB!=null&&availTSB.arr<=earliestTSB.dep)
          {
             processed = true;
             tQ[T_A].offer(tsp[T_B].poll());
             tQ[T_B].poll();
          }
          if(!processed)
          {
             if(earliestTSA!=null&&earliestTSB!=null)
             {
                 if(earliestTSA.dep<earliestTSB.dep)
                 {
                    sol[T_A]++;
                    tQ[T_B].offer(tsp[T_A].poll());
                 }
                 else
                 {
                    sol[T_B]++;
                    tQ[T_A].offer(tsp[T_B].poll());

                 }
             }
             else if(earliestTSA!=null)
             {
                 sol[T_A]++;
                    tQ[T_B].offer(tsp[T_A].poll());

             }
             else if(earliestTSB!=null)
             {
                sol[T_B]++;
                tQ[T_A].offer(tsp[T_B].poll());
             }
          }
         
       }
    
       
       return sol;
    }
    
 
}
