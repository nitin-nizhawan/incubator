import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class BinaryCode
{
	public String [] decode(String message){
      String [] retVal = new String[]{decode(message,0),decode(message,1)};
      return retVal;
   }
   private int v(String message,int i){
     return (message.charAt(i)-'0');
   }
   private String decode(String m,int f){
       if(m.length()==1){
           return (v(m,0)==f)?m:"NONE";
       }
       int dmi [] = new int[m.length()];
       dmi[0] = f; dmi[1] = v(m,0)-f;
       for(int i=2;i<m.length();i++){
           dmi[i] = v(m,i-1) - dmi[i-1] - dmi[i-2];
           
       }
       if(v(m,m.length()-1) == (dmi[m.length()-1]+dmi[m.length()-2])){
            String retStr="";
            for(int i=0;i<m.length();i++){
                if(dmi[i]<0){
                   return "NONE";
                }
                retStr+=dmi[i]+"";
            }
            return retStr;
       } else {
            return "NONE";
       }
   }
	
}
