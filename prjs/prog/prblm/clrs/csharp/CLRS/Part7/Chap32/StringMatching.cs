namespace CLRS.Part7.Chap32;
public class StringMatching
{
private static bool IsAt(string haystack, string needle, int pos){
        if(pos + needle.Length > haystack.Length){
            return false;
        }
        for(int i=0;i<needle.Length;i++){
            if(needle[i]!=haystack[i+pos]){
                return false;
            }
        }
        return true;
    }
 private class RollingHash {
        int hash;
        int M = 9973;
        int B = 26;
        int H = 1;
        public RollingHash(string s, int len){
            hash = 0;
            for (int i = 0; i < len-1; i++){
               H = (H*B)%M;
            }
            for(int i=0;i<len;i++){
                hash = ((hash*B)%M + (s[i]-'a'))%M;
            }
        }
        public int val(){
            return hash;
        }
        public int slide(string s,int i,int len){
            var cprev = s[i-1] - 'a';
            var cnow = s[i+len -1] -'a';
            var additive_inverse = M - (cprev*H)%M;
            hash = (((hash + additive_inverse)*B)%M + cnow)%M;
            return hash;
        }
    }
    private static int RabinKarpStrStr(string haystack, string needle){
        if(needle==""){
            return 0;
        }
        if(haystack.Length < needle.Length){
            return -1;
        }
        // calc needle hash
        int hash = 0;
        int rollinghash =0;
        var phash = new RollingHash(needle,needle.Length);
        var thash = new RollingHash(haystack,needle.Length);
        
        if(phash.val()==thash.val() && IsAt(haystack,needle,0)){
            return 0;
        }
       //  Console.WriteLine("hash="+hash+" , rhash="+rollinghash);
        for(int i=1;i<haystack.Length-needle.Length + 1;i++){
            thash.slide(haystack,i,needle.Length);
          //   Console.WriteLine("hash="+hash+" , rhash="+rollinghash+ ", i="+i);
            if(phash.val()==thash.val() && IsAt(haystack,needle,i)){
                return i;
            }
                
        }
        return -1;
        
    }

   public static int RabinKarp(string needle, string haystack){
	   return RabinKarpStrStr(haystack,needle);
   }

   class KMPSearch {
        int[] lps;
        string pattern;
        public KMPSearch(string pattern){
        //    0 0 1 2 
        //    a b a b b b a b a b a b
            this.pattern = pattern;
            lps = new int[pattern.Length];
            lps[0]=0;
            for(int i=1;i<pattern.Length;i++){
                lps[i] = 0;
                var lastPrefixLen = lps[i-1];
                while(lastPrefixLen > 0 && pattern[i] != pattern[lastPrefixLen]){
                   lastPrefixLen = lps[lastPrefixLen-1];                   
                }  
                if(pattern[i] == pattern[lastPrefixLen]){
                   lps[i] = lastPrefixLen+1;
                }
            
            }
           // Console.WriteLine(string.Join(",",lps));
        }
        public int Search(string haystack){
            if(lps.Length < 1) return 0;
            int i=0;
            int j=0;
            while(i<haystack.Length){
                if(haystack[i]==pattern[j]){
                    i++;
                    j++;
                } else if(j==0){
                    i++;
                } else {
                    j = this.lps[j-1];
                }               
                if(j == pattern.Length){
                    return i - pattern.Length;
                }
            }
            return -1;
        }
        
    }
   public static int KnuthMorrisPratt(string needle, string haystack){
	    var searcher = new KMPSearch(needle);
        return searcher.Search(haystack);
   }
}
