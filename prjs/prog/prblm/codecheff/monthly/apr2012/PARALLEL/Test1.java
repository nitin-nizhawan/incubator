import java.util.*;
public class Test1 {
    public static void main(String args[]){
        int m = 20;
        ArrayList<ArrayList<Integer>> moves = new ArrayList<ArrayList<Integer>>();
        ArrayList<ArrayList<Integer>> tmoves = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> tmpi = new ArrayList<Integer>();
        tmpi.add(0);
        moves.add(tmpi);

        for(int i=1;i<m;i++){
            tmpi = new ArrayList<Integer>();
            tmpi.add(i);
            tmoves.add(tmpi);
            for(int j=0;j<moves.size();j++){
                ArrayList<Integer> cmove = moves.get(j);
                if(cmove.get(cmove.size()-1)+1<i){
                    ArrayList<Integer> cmove_cpy = new ArrayList<Integer>();
                    for(int k=0;k<cmove.size();k++){
                        cmove_cpy.add(cmove.get(k));
                    }
                    cmove_cpy.add(i);
                    tmoves.add(cmove_cpy);
                }
            }
            for(int j=0;j<tmoves.size();j++){
                moves.add(tmoves.get(j));
            }
            tmoves.clear();
        }
        for(int i=0;i<moves.size();i++){
            ArrayList<Integer> imove = moves.get(i);
            for(int j=0;j<imove.size();j++){
                System.out.print(imove.get(j));
                if(j+1<imove.size()){
                    System.out.print("-");
                }
            }
            System.out.println("");
        }
    }
}
