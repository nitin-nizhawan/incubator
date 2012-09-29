import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;


public class Main {

    public static int N;
    public static int A[] = new int[42];
    public static HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
    /**
     * @param args
     */
    public static int NumberOfSetBits(int i)
    {
        i = i - ((i >> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    }
    public static int solve(HashMap<Integer,Integer> hm,int cfg, int len){
        if(hm.get(cfg)==null){
            int bitset = NumberOfSetBits(cfg)-1;
            if(bitset==len){
                hm.put(cfg, 0);
            } else if(2*bitset>=len){
                hm.put(cfg,1);
            } else {
                int min=Integer.MAX_VALUE;
                for(int i=0;i<len;i++){
                    int max_pos=-1;
                    for(int j=(len-1);j>i;j--){
                        int wz = j-i+1;
                        int t_cfg = getCfg(cfg,i,j);
                        int t_bits = NumberOfSetBits(t_cfg)-1;
                         
                        if(t_bits<(j-i+1) && t_bits>0 && 2*t_bits >= (j-i+1)){
                            hm.put(t_cfg, 1);
                            if(max_pos<j){
                                max_pos=j;
                                break;
                            }
                            
                        }
                    }
                    if(max_pos>=0){
                        int wz = max_pos - i +1;
                        int n_cfg = cfg | (((1 << wz) - 1) << i);
                       
                        int tm = solve(hm,n_cfg,len);
                        if((tm+1)<min){
                            min = tm+1;
                        }
                    }
                }
                
                hm.put(cfg, min);
            }
        }
        return hm.get(cfg);
    }
    private static int getCfg(int cfg, int i, int j) {
        // TODO Auto-generated method stub
        int ans = cfg>>i;
        int mask = 1<<(j+1-i);                 
        return (ans&(mask-1))|mask;
    }
    public static void main(String[] args) throws Exception {
        // TODO Auto-generated method stub
        
     hm.put(3, 0); // 1
     hm.put(2, Integer.MAX_VALUE); // 0
     hm.put(4,Integer.MAX_VALUE); //00
     hm.put(5, 1) ; // 01
     hm.put(6, 1) ;// 10
     hm.put(7, 0) ; //11
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         int T = Integer.parseInt(br.readLine());
         while(T-->0){
             N = Integer.parseInt(br.readLine());
             StringTokenizer st = new StringTokenizer(br.readLine());
             int max = Integer.MIN_VALUE;
             for(int i=0;i<N;i++){
                 A[i] = Integer.parseInt(st.nextToken());
                 if(A[i]>max){
                     max = A[i];
                 }
            }
             int cfg=1;
             for(int i=0;i<N;i++){
                 cfg = cfg<<1;
                 if(A[i]==max){
                     cfg=cfg|0x01;
                 }
             }
             
             System.out.println(""+solve(hm,cfg,N));
         }
    }

}
