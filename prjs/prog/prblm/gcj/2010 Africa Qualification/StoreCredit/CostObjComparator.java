import java.util.Comparator;
public class CostObjComparator implements Comparator<CostObj>
{
    private boolean flag;
    public CostObjComparator (){
       flag = false;
    }
    public CostObjComparator (boolean f)
    {
      flag = f;
    }
    public int compare(CostObj co1,CostObj co2)
    {
          int val1;
          int val2;
          if(flag==false){
           val1 = co1.val;
           val2 = co2.val;
          }
          else
          {
             val1 = co1.idx;
           val2 = co2.idx;
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