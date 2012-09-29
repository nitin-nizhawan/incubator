import java.io.*;
import java.util.*;


public class Main {
    public static String[] pows = new String[1005];
    public static StringBuffer zeros = new StringBuffer("0");;
    public static int sofar=0;  
    public static String fivePow(int n){
        if(n>sofar){
            for(int i=sofar+1;i<=n;i++){
               String multiplicand = pows[i-1];
               StringBuffer result = new StringBuffer(multiplicand.length());
               int c = 0;
               for(int j=multiplicand.length()-1;j>=0;j--){
                   int d = multiplicand.charAt(j)-'0';
                   int v = d*5 + c;
                   result.append((char)((v%10)+'0'));
                   c = v/10; 
               }
               if(c>0){
                   result.append((char)(c+'0'));
               }
               result.reverse();
               pows[i] = result.toString();
               zeros.append('0');
            }
            sofar = n;
        }
        return pows[n];
    }
    public static String solve(int n){
        if(n==0){
            return "1";
        }
        int num_digits = n;
        String five_pow_n = fivePow(n);
        return "0."+zeros.substring(0,n-five_pow_n.length())+five_pow_n; 
    }
    public static void main(String args[]) throws Exception{
        pows[0]="1";
      BufferedReader r = new BufferedReader
            (new InputStreamReader (System.in));
        int T=Integer.parseInt(r.readLine()),N;
        while(T-->0){
            N=Integer.parseInt(r.readLine());
            System.out.println(solve(N-1));
        }
    }
}
