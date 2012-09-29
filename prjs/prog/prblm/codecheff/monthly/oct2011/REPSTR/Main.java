
public class Main {


    static long L,H;
    static byte [] buff;
    static class Node {
        Node ht[];
        int count;
        Node(){
            ht = new Node[27];
            count =0;
        }
    };
   public static void  main(String [] args) throws Exception{
       try {
       buff = new byte[100009];
        java.io.BufferedReader br = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        String s;
        java.util.StringTokenizer st = new java.util.StringTokenizer(br.readLine());
        L = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        while(L>0&&H>0){
            s= br.readLine();
            
            //printf("%s\n",buff);
            int slen = s.length();
            int len =0;
            while(len<slen&&s.charAt(len)<='z'&&s.charAt(len)>='a'){
                buff[len] =(byte) ( s.charAt(len)-'a');
                len++;
            }
            Node root = new Node();
            Node curNode; 
            int max=0;
            int mlen=0;
            int mi=0,mj=0;
            for(int i=0;i<(len-L+1);i++){
          //  for(int i=0;i<len;i++){
                curNode = root;
                for(int j=i;j<len&&j<(i+H);j++){
            //    for(int j=i;j<len;j++){
                    if(curNode.ht[buff[j]]!=null){
                        curNode = curNode.ht[buff[j]];
                    } else {
                        curNode.ht[buff[j]] = new Node();
                        curNode = curNode.ht[buff[j]];
                    }
                    curNode.count++; 
                    if((j-i)>=(L-1)&&(j-i)<=H){
                        if(curNode.count>max){
                            max = curNode.count;
                            mlen = j-i+1;
                                mi=i;mj=j;
                        } else if(curNode.count==max){
                            if((j-i+1)>mlen){
                                mi=i;mj=j;
                                mlen = j-i+1;
                            }
                        }
                    }
                }
            }
            System.out.print(max+" "+mlen+"\n");

            st = new java.util.StringTokenizer(br.readLine());
            L = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());
        }
        }finally{
                System.exit(0);
        }
    }



}
