import java.util.*;
import java.io.*;
public class Main {

    public static long MAX_PRIME = 10007;
    public static long MAX_PATTERN_SIZE = 1000*MAX_PRIME;
    public static long ccnt[] = new long[(int)MAX_PATTERN_SIZE];
    public static long seq [] = new long [(int)(2*MAX_PATTERN_SIZE+1)];
    public static int pstart,pend;
    public static long A,B,X,Y,Z,C,P,Q,R,L;
    public static java.util.Random rn;
    public static boolean isPrime(long n){
        if(n<2){
            return false;
        }
        if(n<4){
            return true;
        }
        long d=2;
        while(d*d<=n){
            if(n%d==0){
                return false;
            }
            if(d==2){
                d++;
            } else {
                d+=2;
            }
        }
        return true;
    }
    public static int rand(){
        return rn.nextInt();
    }
    public static void tester(){
        P = rn.nextInt()%10008;
        while(!isPrime(P)){
        P = rn.nextInt()%10008;
        }
        A = rn.nextInt()%P;
        B = rand()%P;
        X = rand()%P;
        Y = rand()%P;
        Z = rand()%P;
        C = rand()%P;
        Q = rand()%20000 + 1;
        //    A=6483;B=4419;X=2330;Y=7258;Z=4643;P=8331;C=5056;Q=15901;
        A=1541;B=1986;X=150;Y=1023;Z=1977;P=4651;C=4478;Q=7734;L=984579433;R=31917347041L;
        process();
        query();
        /*
           while(Q--){
           L = rand()%(1<<30);
           long long MAX = 1;
           MAX = MAX<<36;
           int ch = rand()%100;
           L = (ch>50) ? L : (L*L)%MAX;
           R = rand()%(1<<30);
           ch = rand()%100;
           R = (ch>50) ? R : (R*R)%MAX;
           if(L>R){
           long long tmp = L;
           L = R;
           R = tmp;
           }
           query();
           }*/
    }

    public static  boolean checkPattern(int start,long len){
        if(len>MAX_PATTERN_SIZE){
            return false;
        }
        boolean isPattern = true;
        for(int i=0;i<len;i++){
            if(seq[i]!=seq[(int)(len+i)]){
                isPattern = false;
                break;
            }
        }
        return isPattern;

    }

    public static void query(){
        //L--; R--; //make zero indexed;
        long  Plength = pend - pstart +1;
        long  leftMult = L/Plength;
        long  leftOffset = L%Plength;
        long   rightMult = R/Plength;
        long   rightOffset = R%Plength;
        long   sum = 0;
        if(R<((L/Plength)+1)*Plength){ // L,R falls in same interval
            int l = (int)( (L-1+Plength)%Plength);
            int r = (int) ((R-1+Plength)%Plength);
            sum+=ccnt[r];
            if( l-1>=0){
                sum-=ccnt[l-1];
            }
        } else {
            int r = (int) ((R-1+Plength)%Plength);
            int l =(int)( (L-1+Plength)%Plength);
            sum+=ccnt[r];
            if(l-1>=0){
                sum -=ccnt[l-1];
            }
            sum+=((R/Plength)-(L/Plength))*ccnt[(int)(Plength-1)];
        }
        if(sum<0){
            System.out.printf("A=%l,B=%l,X=%l,Y=%l,Z=%l,P=%l,C=%l,Q=%l,L=%l,R=%l\n",A,B,X,Y,Z,P,C,Q,L,R);
            System.exit(0);
        }
        System.out.println(""+sum);
    }
    public static void process(){
        long  p2_min_1 = P*P -1 ;
        long  j=1;
        long factors1[] = new long [(int)(MAX_PRIME*MAX_PRIME+1)]; 
        seq[0]=A;
        seq[1]=B;
        for(int i=2;i<seq.length;i++){
            seq[i]= ((X*seq[i-1])%P + (Y*seq[i-2])%P + Z)%P;
        }
        boolean isPattern = false;
        int numfac=0;
        
        while(j*j<=p2_min_1){
            if(p2_min_1%j==0){
                long d1= p2_min_1/j;
                long  d2 = j;
                factors1[numfac++]=d2;
                factors1[numfac++]=d1;
            }
            j++;
        }
        long factors[] = new long[numfac];
        for(int i=0;i<numfac;i++){
            factors[i]=factors1[i];
        }
        Arrays.sort(factors,0,numfac);
        if(P<=6){
            numfac = (int) (6*P);
            for(int i=0;i<6*P;i++){
                factors[i]=i+1;
            }
        }
        for(int i = numfac-1;i>0;i--){
            isPattern=true;
            if(isPattern=checkPattern(0,factors[i])){
                pstart = 0;
                pend = (int)i;
                break;
            }
        }
        if(isPattern){
            ccnt[0]=0;
            for(int i=pstart;i<=pend;i++){
                if(seq[i]==C){
                    ccnt[i]=1;
                } else {
                    ccnt[i]=0;
                }
                if(i>0){
                    ccnt[i]+=ccnt[i-1];
                }
            }


        } else {
            int a =1;
            int b = 1/(a-1);
        }

    }
    public static void doInput() throws Exception {
        java.io.BufferedReader br = new java.io.BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while(T>0){
            StringTokenizer params = new StringTokenizer(br.readLine());
            long A = Long.parseLong(params.nextToken());
            long B = Long.parseLong(params.nextToken());
            long X = Long.parseLong(params.nextToken());
            long Y = Long.parseLong(params.nextToken());
            long Z = Long.parseLong(params.nextToken());
            long P = Long.parseLong(params.nextToken());
            long C = Long.parseLong(params.nextToken());
            long Q = Long.parseLong(params.nextToken());
            process();
            while(Q>0){
                StringTokenizer query1 = new StringTokenizer(br.readLine());
                L = Long.parseLong(query1.nextToken());
                R = Long.parseLong(query1.nextToken());
                query();
                Q--;
            }
            T--;
        }
    }
    public static void main(String args[]) throws Exception {
        rn = new java.util.Random();
       // doInput();
       tester();
    }
}


