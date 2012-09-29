public class TrainSchedule 
{
   int dep;
   int arr;
   int flag;
   TrainSchedule(int d,int a,int f)
   {
       dep = d;
       arr = a;
       flag = f;
       System.out.println("dep,arr,flag "+dep+" , "+arr+" , "+flag );
   }
}