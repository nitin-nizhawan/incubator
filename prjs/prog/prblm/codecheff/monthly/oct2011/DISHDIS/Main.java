import java.util.StringTokenizer;
public class Main
{
    static final long MOD=1000000007L;
    static long [][]dp_rec;
    static Cook [] cooks;
    static class Cook{
        public int x;
        public int y;
    }

static long recurse(int m,int n){
    if(m==1){
        if(cooks[0].x<=n&&cooks[0].y>=n){
            return 1;
        } else {
            return 0;
        }
    }
    if(n>=0&&m>=0&&dp_rec[n][m]>-1){
        return dp_rec[n][m];
    }
    Cook cook = cooks[m-1];
    long sum =0;
    for(int i=cook.x;i<=cook.y;i++){
        if((n-i)>=0&&(m-1)>=0){
            long tmp = recurse(m-1,n-i);
            dp_rec[n-i][m-1]=tmp;
            sum = (sum+tmp)%MOD;
        }
    }
    return sum;
}



 static long solve(int n, int m){
    for(int i=0;i<=n;i++){
       for(int j=0;j<=m;j++){
           dp_rec[i][j]=-1;
       }
   }
   return recurse(m,n);
       
    }
    public static void main (String[] args) throws java.lang.Exception
    {
        java.io.BufferedReader r = new java.io.BufferedReader (new java.io.InputStreamReader (System.in));
        int T =  Integer.parseInt(r.readLine());
        cooks = new Cook[101];
        dp_rec = new long[101][101];
        while(T>0){
            T--;
            StringTokenizer st = new StringTokenizer(r.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            for(int i=0;i<m;i++){
                st = new StringTokenizer(r.readLine());
                if(cooks[i]==null){
                    cooks[i] = new Cook();
                }
                cooks[i].x = Integer.parseInt(st.nextToken());
                cooks[i].y = Integer.parseInt(st.nextToken());
            }
            System.out.println(solve(n,m));
        }
    }
}
