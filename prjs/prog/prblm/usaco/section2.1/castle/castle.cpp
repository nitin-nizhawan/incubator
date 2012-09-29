/*
ID: nitin.n1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int castle[60][60];
int castle1[60][60]={0};
int cols,rows;
int COLOR=0;
int WEST=1,NORTH=2,EAST=4,SOUTH=8;
int roomSize[2600]={0};
void dfs(int i, int j){
    if(i>=0&&i<rows&&j>=0&&j<cols&&castle1[i][j]<1){
        castle1[i][j]=COLOR;
        int val = castle[i][j];
        if(!(val&WEST)){
            dfs(i,j-1);
        } 
        if(!(val&NORTH)){
            dfs(i-1,j);
        } 
        if(!(val&EAST)){
            dfs(i,j+1);
        } 
        if(!(val&SOUTH)){
            dfs(i+1,j);
        }
    }
}
int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    int a, b;
    fin >>cols>>rows; // cols first
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            fin>>castle[i][j];
            castle1[i][j]=0;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(castle1[i][j]<1){
                COLOR++;
                dfs(i,j);
            }
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
//            printf("%d ",castle1[i][j]);
            if(castle1[i][j]>0){
                roomSize[castle1[i][j]-1]++;
            }
        }
//        printf("\n");
    }
    int maxSize = 0;
    for(int i=0;i<COLOR;i++){
        if(roomSize[i]>maxSize){
            maxSize = roomSize[i];
        }
    }
    int celli,cellj,wall,maxPossibleSize=0;
    for(int j=-0;j<cols;j++){
        for(int i=rows-1;i>=0;i--){
            int val = castle[i][j];
            if((val&NORTH)&&i>0){
                int thisRoom = castle1[i][j];
                int thatRoom = castle1[i-1][j];
                int newRoomSize = roomSize[thisRoom-1] + roomSize[thatRoom-1];
                if(newRoomSize>maxPossibleSize&&(thisRoom!=thatRoom)){
                    celli=i; cellj=j; wall = NORTH;
                    maxPossibleSize=newRoomSize;
                }
            }
            if((val&EAST)&&(j+1)<cols){
                int thisRoom = castle1[i][j];
                int thatRoom = castle1[i][j+1];
                int newRoomSize = roomSize[thisRoom-1] + roomSize[thatRoom-1];
                if(newRoomSize>maxPossibleSize&&(thisRoom!=thatRoom)){
                    celli=i; cellj=j; wall = EAST;
                    maxPossibleSize=newRoomSize;
                }
            }
        }
    }
    fout<<COLOR<<"\n";
    fout<<maxSize<<"\n";
    fout<<maxPossibleSize<<"\n";
    fout<<(celli+1)<<" "<<(cellj+1)<<" "<<((wall==NORTH)?"N":"E")<<"\n";
    return 0;
}

