import java.util.HashMap;
/**
 * Created with IntelliJ IDEA.
 * User: nnizhawa
 * Date: 26/5/14
 * Time: 7:56 PM
 * To change this template use File | Settings | File Templates.
 */
public class Prob32 {
    static void swap(int n[], int a, int b){
        int tmp =n[a];
        n[a] = n[b];
        n[b] = tmp;
    }
    static boolean  perm_next(int n[]) {
         int tail, i, j;

       /* if (n.length <= 1)
            return 0;*/

    /* Find all terms at the end that are in reverse order.
       Example: 0 3 (5 4 2 1) (i becomes 2) */
        for (i=n.length-1; i>0 && n[i-1] >= n[i]; i--);
        tail = i;

        if (tail > 0) {
        /* Find the last item from the tail set greater than
            the last item from the head set, and swap them.
            Example: 0 3* (5 4* 2 1)
            Becomes: 0 4* (5 3* 2 1) */
            for (j=n.length-1; j>tail && n[j] <= n[tail-1]; j--);

            swap(n,tail-1, j);
        }

    /* Reverse the tail set's order */
        for (i=tail, j=n.length-1; i<j; i++, j--)
            swap(n,i, j);

    /* If the entire list was in reverse order, tail will be zero. */
        return (tail != 0);
    }
    static HashMap hm = new HashMap();
    public static void printpermuteation(int [] n){
        System.out.print("{");
        for(int i=0;i<n.length;i++){
            System.out.print(n[i]);
        }
        System.out.println("}");
    }
    public static int getnum(int num[], int start, int len){
        int r =0;
        for(int i=0;i<len;i++){
            r =  r*10 + num[start+i];
        }
        return r;
    }
    public static int check(int num[]){
          for(int a=1;a<9;a++){
              int av = getnum(num,0,a);
              for(int b=1;b<(9-a);b++){
                int bv = getnum(num,a,b);
                int cv = getnum(num,a+b,9-a-b);
                if(av*bv == cv&&hm.get(cv)==null){
                     hm.put(cv,"hell");
                     System.out.println("{"+av +"*"+bv+"="+cv+"}");
                    return cv;
                }else {
		//System.out.println(av +"*"+bv+"="+cv);
                }
              }
          }
          return 0;
    }
    public static void main(String args[]){
        int [] nums = new int[]{1,2,3,4,5,6,7,8,9};
        int totalperms = 1*2*3*4*5*6*7*8*9;
        int sum=0;
        for(int i=1;i<=totalperms;i++){
            int t = check(nums);
            if(t>0){
                sum+=t;
            }
//            printpermuteation(nums);
            perm_next(nums);
        }
        System.out.println("Sum="+sum);

    }
}
