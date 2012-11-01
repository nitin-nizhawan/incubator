/*
ID: nitin.n1
PROG: camelot
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream fout ("camelot.out");
ifstream fin ("camelot.in");
int rows,cols;
int col[5000];
int row[5000];
int cnt=0;
int distmat[31*27][31*27];
int board[31][27];
int abs1(int a){
    if(a<0) return 0-a;
    return a;
}
int mn(int r,int c){
   return c+r*cols;
}
int bk(int n,int* r,int* c){
    *r = n/cols;
    *c = n%cols;
}
void clearBoard(){
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            board[r][c]=1<<28;
        }
    }
}
int rq[31*27];
int cq[31*27];
int qh=0,qt=0;
void addq(int r,int c){
    rq[qt]=r;
    cq[qt]=c;
    qt = (qt+1)%(31*27);
}
void remq(int *r,int *c){
    *r = rq[qh];
    *c = cq[qh];
    qh = (qh+1)%(31*27);
}
bool eq(){
    return qh==qt;
}
void setD(int r, int c,int d){
   if(r>=0&&c>=0&&r<rows&&c<cols){
       if(board[r][c]==(1<<28)){
           board[r][c] = d;
           addq(r,c);
       }
   }
}
void bfs(int r,int c,int dist=0){
  board[r][c]=0;
   addq(r,c);
   while(!eq()){
       remq(&r,&c);
       int cd = board[r][c]+1;
       setD(r+1,c+2,cd);
       setD(r-1,c+2,cd);
       setD(r+1,c-2,cd);
       setD(r-1,c-2,cd);
       setD(r+2,c+1,cd);
       setD(r-2,c+1,cd);
       setD(r+2,c-1,cd);
       setD(r-2,c-1,cd);
   }
}
void setDists(int r,int c){
    for(int r1=0;r1<rows;r1++){
        for(int c1=0;c1<cols;c1++){
            int sp = mn(r,c);
            int ep = mn(r1,c1);
            distmat[sp][ep]=distmat[ep][sp]=board[r1][c1];
        }
    }
}
void initDistMat(){
    for(int r1=0;r1<rows;r1++){
        for(int c1=0;c1<cols;c1++){
            int sp = mn(r1,c1);
            clearBoard();
            bfs(r1,c1);
            setDists(r1,c1);            
        }
    }
}
int kingSteps(int r, int c, int r1,int c1){
    int dr = abs1(r-r1);
    int dc = abs1(c-c1);
    return max(dr,dc);
}
int rideSteps(int kbh,int k,int r, int c){
    kbh-=distmat[mn(r,c)][mn(row[k],col[k])];
    kbh-=kingSteps(r,c,row[0],col[0]);
    // now lets make king and kinght meet at arbitray point
    int MinDist=1<<28;
    for(int r1=0;r1<rows;r1++){
        for(int c1=0;c1<cols;c1++){
             int tmp = kbh+kingSteps(row[0],col[0],r1,c1);
              tmp+=distmat[mn(row[k],col[k])][mn(r1,c1)];
              tmp+=distmat[mn(r1,c1)][mn(r,c)];
              MinDist = min(tmp,MinDist);
        }
    }
    return MinDist;
}
int findMinDist(int r,int c){
   int minSofar=0,kingbyhimself;
   // king goes all by himself
  int sp = mn(r,c);
  kingbyhimself= kingSteps(r,c,row[0],col[0]);
  for(int i=1;i<cnt;i++){
      kingbyhimself+=distmat[sp][mn(row[i],col[i])];
  }
  minSofar=kingbyhimself;
  // now let give king a ride
  for(int i=1;i<cnt;i++){
      minSofar = min(minSofar,rideSteps(kingbyhimself,i,r,c));
  }
  return minSofar;
}
int main() {
    fin>>rows>>cols;
    char C;
    int R;
    fin>>C;
    while(!fin.eof()){
        fin.putback(C);
        fin>>C;
        fin>>R;
        row[cnt]=R-1;
        col[cnt]=C-'A';
        cnt++;
        fin>>C;
    }
   /* for(int i=0;i<cnt;i++){
        printf("row=%d,col=%d\n",row[i],col[i]);
    }*/
    initDistMat();
/*    for(int i=0;i<rows*cols;i++){
        for(int j=0;j<rows*cols;j++){
            printf("%d ",distmat[i][j]);
        }
        printf("\n");
    } */
    int minD = 1<<28;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            minD = min(findMinDist(r,c),minD);
        }
    }
    fout<<minD<<"\n";
    return 0;
}

