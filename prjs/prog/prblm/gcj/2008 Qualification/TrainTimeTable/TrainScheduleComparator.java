import java.util.Comparator;
public class TrainScheduleComparator implements Comparator<TrainSchedule>
{
    private boolean flag;
    public TrainScheduleComparator (){
       flag = true;
    }
    public TrainScheduleComparator (boolean f)
    {
      flag = f;
    }
    public int compare(TrainSchedule co1,TrainSchedule co2)
    {
          int val1;
          int val2;
          if(flag==false){
           val1 = co1.arr;
           val2 = co2.arr;
          }
          else
          {
             val1 = co1.dep;
           val2 = co2.dep;
          }
          if(val1<val2)
           {
              return -1;
           }
          else if(val1 > val2)
         {
           return 1;
         }
         else
          {
               return 0;
          }
         
    }
}