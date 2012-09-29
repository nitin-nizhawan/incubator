import java.util.StringTokenizer;
import java.io.PrintWriter;
public class AlwaysTurnLeft extends BaseSolution
{
	static PrintWriter mpw = new PrintWriter(System.out);
	int [] chars = new int [] {
        //	can e, can w, can s, n
		        0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0xb,0xc,
			0xd,0xe,0xf
	};
	int setCanN(int n){
		return n|0x1;
	}
	int setCanS(int n){
		return n|0x2;
	}
	int setCanW(int n){
		return n|0x4;
	}
	int setCanE(int n){
		return n|0x8;
	}
	int maze [][];
	final int TO_SOUTH = 0;
	final int TO_WEST = 1;
	final int TO_NORTH = 2;
	final int TO_EAST = 3;
	int MAX_D;
	int getNewDir(String moveCode,int curDir){
		moveCode = moveCode.toLowerCase();
            if("w".equals(moveCode)){
		    return curDir;
	    } else if("r".equals(moveCode)){
		    return (curDir+1)%4;
	    } else {
		    return (curDir-1+4)%4;
	    }
	}

	public static void main(String args[]) throws Exception{
		new AlwaysTurnLeft().start(args[0]);
        }
	private int countMoves(String str){
		int count = 0;
		for(int i=0;i<str.length();i++){
			if((str.charAt(i)+"").toLowerCase().equals("w")){
				count++;
			}
		}
		return count;
	}
	public void initMaze(){
		for(int i=0;i<MAX_D;i++){
			for(int j=0;j<MAX_D;j++){
				maze[i][j]=0;
			}
		}
	}
	public void solveTestCase(int tcn) throws Exception{
	//	logTo(mpw);
                StringTokenizer st = new StringTokenizer(readLine());

		String straight = st.nextToken();
		log("Straight "+straight);

		String reverse = st.nextToken();
		log("reverse "+reverse);
		MAX_D = straight.length();//countMoves(straight);
		if(reverse.length()>straight.length())
		{
			MAX_D = reverse.length();
		}
		log("MAX_D " +MAX_D);
	        maze  = new int [MAX_D][MAX_D];
		initMaze();
		int curX = 0;
		int curY = 0;
		int curDir = TO_SOUTH;
		int [] result = traverseMaze(straight,curX,curY,curDir);
		curX = result[0];
		curY = result[1];
		curDir = result[2];
                // now we are out of maze, lets go back
		// lets move 180 degree, back;
		curDir = getNewDir("r",curDir); // 90 degree
		curDir = getNewDir("r",curDir); // 90 more degrees;
		// move one step back now;
		int [] coords2 = moveOneStep(curDir,curX,curY);
		curX = (coords2[0]+MAX_D)%MAX_D;
		curY = (coords2[1]+MAX_D)%MAX_D;
			log("afteri " +curX+" , "+curY);
		traverseMaze(reverse,curX,curY,curDir);
		printSol("Case #"+(tcn+1)+":");
	       printMaze();
	}
	int [] traverseMaze(String directions,int x,int y,int dir)
	{
		int curDir = dir;
		int curX = x;
		int curY = y;
                for(int j=1;j<directions.length();j++){
			String curr = directions.charAt(j)+"";
			int newDir = getNewDir(curr,curDir);
			if(newDir == curDir){
			int [] coords = moveOneStep(newDir,curX,curY);
			log("going withi " +curX+" , "+curY);
			setCanMove(newDir,curX,curY);
			curX = (coords[0]+MAX_D)%MAX_D;
			curY = (coords[1]+MAX_D)%MAX_D;
			}
		        curDir = newDir;	

		}
		return new int[]{curX,curY,curDir};

	}
	private int [] findHorizontalLimit(){
		
		int left = 0;
		for(int i=MAX_D-1;maze[i][0]>0;i--)
		{
			left++;
		}
		int right=0;
		for(int j=0;maze[j][0]>0;j++)
		{
			right++;
		}
		return new int[]{left,right};
	}
	private void printMaze(){
//		for(int t=0;t<MAX_D;t++){
//		log(java.util.Arrays.toString(maze[t]));
//		}
		int [] limit = findHorizontalLimit();
		int left = limit[0];
		int right = limit[1];
		log("Left "+left+" , right "+right);
		for(int k=0;maze[0][k]>0;k++)
		{
			String row="";
			for(int l=-1*left;l<right;l++)
			{
				int x = (l+MAX_D)%MAX_D;
				log("inner Loop l= "+l+" , x= "+x);
				String hexVal = Integer.toHexString(maze[x][k]);
				row=row+hexVal;
				
			}
			printSol(row);
		}
	
	}
	private int [] moveOneStep(int dir,int x, int y){
           int retVal[] = new int[] {x,y};
           switch(dir){
		   case TO_SOUTH:
			  retVal[1]++;
			  break;
		   case TO_NORTH:
			  retVal[1]--;
			  break;
		   case TO_WEST:
			  retVal[0]--;
	                  break;
	           case TO_EAST:
			  retVal[0]++;
			  break;

	   }
	   return retVal;
	}
	private void setCanMove(int dir,int x, int y){

           switch(dir){
		   case TO_SOUTH:
			  maze[x][y] = setCanS(maze[x][y]);
			  break;
		   case TO_NORTH:
			  maze[x][y] = setCanN(maze[x][y]);
			  break;
		   case TO_WEST:
			  maze[x][y] = setCanW(maze[x][y]);
	                  break;
	           case TO_EAST:
			  maze[x][y] = setCanE(maze[x][y]);
			  break;

	   }
	}
}
