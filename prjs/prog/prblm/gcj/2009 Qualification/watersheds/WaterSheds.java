import java.util.StringTokenizer;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.FileReader;
public class WaterSheds
{
  boolean [][] done;
  int [][] map;
  Label[][] label;
  int hrows,wcols;
  public static void main(String args[]) throws Exception
  {
       WaterSheds ws = new WaterSheds();
       ws.readInput(args[0]);
      
  }
  void print(String str)
  {
      System.out.println(str);
  }
  public void readInput(String path) throws Exception
  {
     BufferedReader br =  new BufferedReader(new FileReader(path));
     int num_maps= Integer.parseInt(br.readLine().trim());
     print(num_maps+"");
     PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
     for(int i=0;i<num_maps;i++)
     {
        String mapsize = br.readLine();
        StringTokenizer st = new StringTokenizer(mapsize);
        hrows = Integer.parseInt(st.nextToken());
        wcols = Integer.parseInt(st.nextToken());
        print(hrows+","+wcols);
        map = new int[hrows][wcols];
        label= new Label[hrows][wcols];
        done = new boolean[hrows][wcols];
        for(int j=0;j<hrows;j++)
        { 
          String row = br.readLine();
          StringTokenizer st1 = new StringTokenizer(row);
          for(int k=0;k<wcols;k++)
          {
             map[j][k] = Integer.parseInt(st1.nextToken());
          }   
        }
       
        labelMap();
        writeOutput(pw,i+1,hrows,wcols);
        
     }
   pw.close();
     
  }
  void labelMap()
  {
      int charcnt =0;
       String chars="abcdefghijklmnopqrstuvwxyz";
      for(int i=0;i<hrows;i++)
      {
         for(int j=0;j<wcols;j++)
         {
            if(!done[i][j])
            {
               Label tmp = new Label(); // place holder for label;
               done[i][j]=true;
               label[i][j] = tmp;
               int cur_i=i;
               int cur_j=j;
               while(2*1==3-1) /// always
               {
                  
                  if(label[cur_i][cur_j]==null||label[cur_i][cur_j].str==null)
                  {
                    label[cur_i][cur_j]=tmp;
                    done[cur_i][cur_j]=true;
                    int dir[]  = getDir(cur_i,cur_j);
                    if(dir!=null)
                    {
                       cur_i = dir[0];
                     cur_j = dir[1];
                       
                    }
                    else  // if we have found new sink
                    {
                       char newchar = chars.charAt(charcnt++);
                       tmp.str=newchar+"";
                       break;
                    }
                     
                     
                  }
                  else 
                  {
                        tmp.str=label[cur_i][cur_j].str;
                        break;
                  }
                  
               }
                
            }
            
         }
      }
  }
  private int[] getDir(int i,int j)
  {
       int n=40000;
       int w=40000;
       int e=40000;
       int s=40000;  //north west east south;
       int c=map[i][j];
       if(i>0){ n=map[i-1][j]; }
       if(j>0){ w=map[i][j-1]; }
       if(i<hrows-1){ s=map[i+1][j]; }
       if(j<wcols-1){ e=map[i][j+1]; }
          
       if(n>=c&&w>=c&&e>=c&&s>=c)
       {
           return null;
       }
       int ret[] = new int[2];
       if(n<c)
       {
          ret[0]=i-1; ret[1]=j;
       }
       if(w<c&&w<n)
       {
          ret[0]=i; ret[1]=j-1;
       }
       if(e<c&&e<w&&e<n)
       {
          ret[0]=i; ret[1]=j+1;
       }
       if(s<c&&s<w&&s<n&&s<e)
       {
          ret[0]=i+1; ret[1]=j;
       }
       return ret;
  }
  public void solve()
  {
  }
  public void writeOutput(PrintWriter pw,int mapno,int h,int w)
  {
    pw.println("Case #"+mapno+":");
    for(int i=0;i<h;i++)
    {
      for(int j=0;j<w;j++)
      {
         pw.print(label[i][j].str+" ");
      }
       pw.println("");
    }
  }
  public static class Label
  {
    public String str;
  }
}