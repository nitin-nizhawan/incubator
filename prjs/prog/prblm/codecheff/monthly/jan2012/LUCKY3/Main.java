import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    /**
     * @param args
     * @throws IOException
     * @throws NumberFormatException
     */
    static int n;
    static long nums[];

    static long canonicalize(long a) {
        long r = 0;
        int size = 0;
        while (a > 0) {
            long d = a % 10;
            if (d == 4 || d == 7) {
                r = r * 10 + d;
            } else if (d < 4) {
                r = r * 10 + 1;
            } else if (d > 4 && d < 7) {
                r = r * 10 + 5;
            } else if (d > 7) {
                return -1;
            }
            size++;
            a /= 10;
        }
        long ret = 0;
        for (int i = 0; i < size; i++) {
            ret = ret * 10 + r % 10;
            r /= 10;
        }
        return ret;
    }

    static long magicAdd(long a, long b) {
        long r = 0;
        while (a > 0 || b > 0) {
            long d1 = a % 10;
            long d2 = b % 10;
            r = r * 10 + Math.max(d1, d2);
            a /= 10;
            b /= 10;
        }
        long ret = 0;
        while (r > 0) {
            ret = ret * 10 + r % 10;
            r /= 10;
        }
        return ret;
    }

    static boolean isMagic(long n) {
        if(n==0){
            return false;
        }
        while (n > 0) {
            long d = n % 10;
            if (d != 4 && d != 7) {
                return false;
            }
            n /= 10;
        }
        return true;
    }

    static void solve() {
        HashMap<Long, Long> map = new HashMap<Long, Long>();
        HashMap<Long, Long> tmap = new HashMap<Long, Long>();
        for (int i = 0; i < n; i++) {
            long num = canonicalize(nums[i]);
            if (num >= 0) {
                for (Iterator<Map.Entry<Long, Long>> it = map.entrySet()
                        .iterator(); it.hasNext();) {
                    Map.Entry<Long, Long> me = it.next();
                    long key = me.getKey();
                    long val = me.getValue();
                    long res = magicAdd(key,num);
                    if(tmap.get(res)!=null){
                        tmap.put(res, val+tmap.get(res));
                    } else {
                        tmap.put(res, val);
                    }
                }
                if (tmap.get(num) != null) {
                    tmap.put(num, tmap.get(num) + 1);
                } else {
                    tmap.put(num, (long) 1);
                }
                for (Iterator<Map.Entry<Long, Long>> it = tmap.entrySet()
                        .iterator(); it.hasNext();) {
                    Map.Entry<Long, Long> me = it.next();
                    long key = me.getKey();
                    long val = me.getValue();
                    if (map.get(key) != null) {
                        map.put(key, val + map.get(key));
                    } else {
                        map.put(key, val);
                    }
                }
                tmap.clear();
            }
        }
        long ans = 0;
        for (Iterator<Map.Entry<Long, Long>> it = map.entrySet().iterator(); it
                .hasNext();) {
            Map.Entry<Long, Long> me = it.next();
            long key = me.getKey();
            long val = me.getValue();
            if (isMagic(key)) {
                ans += val;
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws NumberFormatException,
            IOException {
        try{
        // TODO Auto-generated method stub
        nums = new long[60];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                nums[i] = Integer.parseInt(st.nextToken());
            }
            solve();
        }
        }finally{
            System.exit(0);
        }

    }

}

