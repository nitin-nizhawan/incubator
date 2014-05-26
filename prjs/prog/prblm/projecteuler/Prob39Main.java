import javax.swing.plaf.basic.BasicInternalFrameTitlePane;

/**
 * Created with IntelliJ IDEA.
 * User: nnizhawa
 * Date: 26/5/14
 * Time: 6:19 PM
 * To change this template use File | Settings | File Templates.
 */
public class Prob39Main {

    private static int numFactors(int k){
            int n=0;
            for(int d=1;d<=k;d++){
                if(k%d==0){
                    n++;
                }
            }
            return n;
    }

    private static int solutions2(int p) {
       // a^2 = b^2 + c^2
       // a + b + c = p
        // Euclid's formula
       //  a =  k.(m^2 - n^2)
        // b = k.(2m)
        // c = k(m^2+n^2)
        int sols=0;
       for(int m = 1;m<=p;m++){
           for(int n=0;n<m;n++){
               int a = m*m - n*n;
               int b = 2*m;
               int c = m*m + n*n;
               if(p%(a + b +c)==0) {
                    int ks = p/(a + b +c);
                   sols+=numFactors(ks);
               }
           }
       }
       return sols;
    }
    private static int solutions(int p) {

        int sols=0;
        for(int a=1;a<p;a++){
           // a^2 + b^2 = (p- a -b)^2
            // 0 = p^2 + (a+b)^2 - 2p(a+b) = p^2 + 2ab -2pa -2pb
            // 2pa + 2pb = p^2 + 2ab;
            // b = (2pa - p^2)/(2a - 2p)   p*(p-2a)/(2p - 2a)
            int n = p*(p-2*a)              ;
            int d = 2*p - 2*a   ;
            // n is not -ve so that b = n/d is -ve
            // and n and d are both positive
            // and d divides n
            if(n!=0&&((n+d)>n&&(n+d)>d)&&(n%d) ==0){
                //System.out.println("("+a+","+(n/d)+","+(p-a-(n/d))+")");
                sols++;
            }
        }
        return sols;
    }
    public static void main(String args[]){
         int max =1;
         int max_p = 1;
         for(int p=1;p<1000;p++){
             int solns = solutions(p);
             if(solutions(p)>max){
             max = solns;
                 max_p = p;
             }
         }
        System.out.println(max+","+max_p);
    }


}
