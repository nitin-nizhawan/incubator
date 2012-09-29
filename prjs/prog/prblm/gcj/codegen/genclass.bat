@echo off
echo import java.util.StringTokenizer;
echo public class %1 extends BaseSolution {  
echo    public static void main(String args[]) throws Exception { 
echo       %1 obj = new %1();
echo          obj.start(args[0]);  
echo          obj.setDebugMode(true);
echo          obj.setLogToConsole(false);
echo    } 
echo // solution logic 
echo public String solveTestCase() throws Exception {
echo   //TODO: write your logic here 
echo   return "Logic not implemented";
echo  } 
echo } 
