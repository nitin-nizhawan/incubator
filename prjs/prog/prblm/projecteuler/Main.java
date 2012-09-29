import java.io.*;
public class Main{
	public static void main(String args[]) {
		try{
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
		String line = br.readLine();
		int	input =0;
		if(line!=null&&line.length()>0){
	        input=	Integer.parseInt(line);
		while(input!=42){
			System.out.println(input);
			line = br.readLine();
			if(line==null||line.length()<1){
				break;
			}
			input = Integer.parseInt(line);
		}
	}
		br.close();
		}catch(Exception e){
		}
		
	}
}
