
import java.util.StringTokenizer;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.PrintWriter;
public class AlienLanguage
{
  String [] wordlist;
  String [] tests;
  int num_chars;
  int num_words;
  int num_tests;
  public static void main(String args[]) throws Exception
  {
      AlienLanguage al = new AlienLanguage();
      System.out.println(args[0]);
      al.readInput(args[0]);
      int answers[] = al.solve();
      al.createOutput(answers);
  }
  public void createOutput(int [] answers) throws Exception
  {
     PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
     for(int i=0;i<num_tests;i++)
     {
       pw.println("Case #"+(i*1+1)*1+": "+answers[i]);
     }
     pw.close();
  }
  public int [] solve()
  {
     int answers[] = new int[num_tests];
     
     for(int i=0;i<num_tests;i++)
     {  
         answers[i]=0;
         String [] prsd = parseTestCase(tests[i]);
         for(int j=0;j<num_words;j++)
         {
              int flag=1;
              for(int k=0;k<num_chars;k++)
              {
                 if(prsd[k].indexOf(wordlist[j].charAt(k))<0)
                 {
                    flag=0;
                    break;
                 }
              }
              if(flag==1)
              {
                 answers[i]++;
              }
         }
         
         print("Testcase: "+tests[i]+" answers: "+answers[i]);
                  
     }
     return answers;
     
  }
  public String [] parseTestCase(String testcase)
  {
     print("parsing "+testcase);
     String [] prsd = new String[num_chars];
     int x=0;
     for(int i=0;i<testcase.length();i++)
     {
        if(testcase.charAt(i)=='(')
        {
           i++;
           String wgrp = "";
           while(testcase.charAt(i)!=')')
           {
                wgrp+=testcase.charAt(i)+"";
                i++;
           }
           prsd[x++]=wgrp;
        }
        else	
        {
           prsd[x++]=testcase.charAt(i)+"";
        }
     }
     print(x+"");
     return prsd;
  }
  public void readInput(String path) throws Exception
  {
     BufferedReader br=null;
     try{
     br =  new BufferedReader(new FileReader(path));
     String inputsizestr  = br.readLine();
     
     StringTokenizer st = new StringTokenizer(inputsizestr.trim());
     num_chars = Integer.parseInt(st.nextToken());
     num_words = Integer.parseInt(st.nextToken());
     num_tests = Integer.parseInt(st.nextToken());
      print(num_chars+" "+num_words+" "+num_tests);
     wordlist = new String[num_words];
     for(int i=0;i<num_words;i++)
     {
          
         wordlist[i] = br.readLine();
         print("Words: "+wordlist[i]);
     }
     tests = new String[num_tests];
     for(int j=0;j<num_tests;j++)
     {
       tests[j]=br.readLine();
       print("tests: "+tests[j]);
     }
     }catch(Exception e)
      {
         print(e+"");
      }
     finally
     {
        if(br!=null)
        {
          br.close();
        }
     }
     
  }
  void print(String str)
  {
     System.out.println(str);
  }
}
