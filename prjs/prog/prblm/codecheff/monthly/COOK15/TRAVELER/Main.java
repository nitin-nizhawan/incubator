import java.util.*;
import java.io.*;
public class Main {

    static long min(long a, long b){
        return (a<b)?a:b;
    }
    public static void main(String args[])throws Exception {
        try{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        HashMap<String,Integer> nameIdx = new HashMap<String,Integer>();
        int idx=0;
        while(st.hasMoreTokens()){
            nameIdx.put(st.nextToken(),idx++);
        }
        long graph[][] = new long [50][50];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                graph[i][j] = Integer.MAX_VALUE;
            }
        }
        String tmp;
        tmp = br.readLine();
        //System.out.println("Reading M"+tmp);
        int M = Integer.parseInt(tmp);

        for(int i=0;i<M;i++){
            tmp = br.readLine();
            //System.out.println("Reading "+i+"th pair");
            st = new StringTokenizer(tmp);
            String name1 = st.nextToken();
            String name2 = st.nextToken();
            int dist = Integer.parseInt(st.nextToken());
            graph[nameIdx.get(name1)][nameIdx.get(name2)] = dist;
        }
/*        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    long sum;
                    sum = graph[i][k] + graph[k][j];
                    if(graph[i][k]>=Integer.MAX_VALUE||graph[k][j]>=Integer.MAX_VALUE){
                        sum = Integer.MAX_VALUE;
                    }
                    graph[i][j] = min (graph[i][j],sum);
                }
            }
        } */
        tmp = br.readLine();
        //System.out.println("Reading T "+tmp);
        int T = Integer.parseInt(tmp);
        for(int i=0;i<T;i++){
            tmp = br.readLine();
            //System.out.println("Reading "+i+ "th tour "+tmp);
            st = new StringTokenizer(tmp);
            int K = Integer.parseInt(st.nextToken());
            long tDist = 0;
            String name1 = st.nextToken();
            boolean visited[] = new boolean[50];
            if(nameIdx.get(name1)==null){
                System.out.println("ERROR");
                continue;
            }
            visited[nameIdx.get(name1)] = true;
            boolean flagOk = true;
            for(int j=1;j<K;j++){
                  String name2 = st.nextToken();
                  if(nameIdx.get(name1)==null||nameIdx.get(name2)==null){
                      System.out.println("ERROR");
                      flagOk=false;
                      break;
                  }
                  int idx1 = nameIdx.get(name1);
                  int idx2 = nameIdx.get(name2);
                  if(visited[idx2]){
                      System.out.println("ERROR");
                      flagOk=false;
                      break;
                  }
                  visited[idx2] = true;
                  if(graph[idx1][idx2]>=Integer.MAX_VALUE){
                      System.out.println("ERROR");
                      flagOk = false;
                      break;
                  }
                  tDist+=graph[idx1][idx2];
                  name1 = name2;
            }
            if(flagOk){
                System.out.println(""+tDist+"");
            }
        }
        br.close();
        }finally{
        System.exit(0);
        }
    }

}
