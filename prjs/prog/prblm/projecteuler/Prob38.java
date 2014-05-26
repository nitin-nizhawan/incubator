public class Prob38{
   public static int size(long n){
      int s=0;
      while(n>0){
          n/=10;s++;
      }
      return s;
   }
   static boolean check(long n[],int k){
       boolean flag[] = new boolean[9];
       for(int f=0;f<9;f++) flag[f]=false;
       for(int i=0;i<k;i++){
           long num= n[i];
           while(num>0){
              int d =(int)( num%10L);
              if(d==0) return false;
               if(flag[d-1]) return false;
               flag[d-1]=true;
               num/=10L;
           }
       }
       for(int c=0;c<9;c++) if(flag[c]==false) return false;
       System.out.println("");
       for(int p=0;p<k;p++) System.out.print(n[p]);
       return true;
   }
   public static void main(String args[]){
        for(long a=1;a<999999999;a++){
           long prods[] = new long[9];
           int totalsize = 0;
           for(int j=1;j<=9;j++){ 
              prods[j-1] = a*(long)j;
              totalsize+=size(prods[j-1]);
              if(j>1&&totalsize==9&&check(prods,j)){
                  break; 
              } else if(totalsize >=9 ){
                    break;
              } 
           }
        }       
   }
}
