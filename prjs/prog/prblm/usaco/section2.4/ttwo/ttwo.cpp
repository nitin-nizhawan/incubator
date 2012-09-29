/*
ID: nitin.n1
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int BLOCK=(1<<0);
const int EMPTY=(1<<1);
const int FJOHN=(1<<2);
const int COW=(1<<3);
const int UP=0;
const int RIGHT=1;
const int DOWN=2;
const int LEFT=3;
int maze[30][30];
int fi,fj,ci,cj,fd=UP,cd=UP;

void moveObj(int &i,int &j,int &dir){
    switch(dir){
        case UP:
        if(i-1<0){
            dir=(dir+1)%4;
        } else if(maze[i-1][j]==BLOCK){
            dir=(dir+1)%4;
        } else {
            i--;
        }
        break;
        case RIGHT:
        if(j+1>=10){
            dir=(dir+1)%4;
        } else if(maze[i][j+1]==BLOCK) {
            dir=(dir+1)%4;
        } else {
            j++;
        }
        break;
        case DOWN:
        if(i+1>=10){
            dir=(dir+1)%4;
        } else if(maze[i+1][j]==BLOCK){
            dir=(dir+1)%4;
        } else {
            i++;
        }
        break;
        case LEFT:
        if(j-1<0){
            dir=(dir+1)%4;
        } else if(maze[i][j-1]==BLOCK){
            dir=(dir+1)%4;
        } else {
            j--;
        }
        break;
    }
}
int main() {
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");
    char buff[30], b;
    for(int i=0;i<10;i++){
        fin>>buff;
        for(int j=0;j<10;j++){
            if(buff[j]=='*'){
                maze[i][j]=BLOCK;
            } else if(buff[j]=='.'){
                maze[i][j]=EMPTY;
            } else if(buff[j]=='C'){
                maze[i][j]=COW;
                ci=i;cj=j;
            } else if(buff[j]=='F'){
                maze[i][j]=FJOHN;
                fi=i;
                fj=j;
            }
        }
    }
    int maxSteps=100000;
    bool met=false;
    int i=0;
    while(i<=maxSteps){
        moveObj(fi,fj,fd);
        moveObj(ci,cj,cd);
        i++;
        if(ci==fi&&cj==fj){
            fout<<i<<"\n";
            return 0;
        }
    }
   
    fout <<0<<endl;
    return 0;
}

