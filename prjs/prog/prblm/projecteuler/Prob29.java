import java.util.HashMap;
public class Prob29{
static long sign [][] =new long [101][101];

static void setsign(int n){
	int val = n;
	for(int i=2;n>1;i++){
		sign[val][i]=0;
		while(n%i==0){
			sign[val][i]++;
			n/=i;
		}
	}

}
static HashMap hm = new HashMap();
static void  calcsign(int i,int j){
	String str="";
        for(int k=2;k<101;k++){
		str+=""+k+"^"+sign[i][k]*j+",";
		
	}
	hm.put(str,"");

}
public static   void main(String args[]){
	for(int k =2;k<=100;k++){
	setsign(k);
	}
	// find pairs
	for(int i=2;i<=100;i++){
		for(int j=2;j<=100;j++){
			calcsign(i,j); // calc sign of i^j;

		}
	}
//	cout<<99*99-count<<endl;
  System.out.println(hm.size());
}

}
