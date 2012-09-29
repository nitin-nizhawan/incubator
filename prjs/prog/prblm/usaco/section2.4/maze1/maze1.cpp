/*
ID: nitin.n1
PROG: maze1
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
char buff[500];
const int WALL=-23;
const int TRANS=-24;
int mazeinp[500][500];
class Node{
    public:
        int edges[4]; // max four edges
        int ed_cnt;
        bool visited;
        int dist[2];// one for each target
        int parent;
        Node(){
            ed_cnt=0;
            visited=false;
            dist[0]=0;
            dist[1]=0;
            parent=-1;
        }

};
Node nodes[5000];
int queue[5000];
int sq=0,eq=0;
bool isEmpty(){
    if((sq%4500)==(eq%4500)){
        return true;
    }
    return false;
}
void addToQueue(int v){
    queue[eq]=v;
    eq=(eq+1)%4500;
}
int remove(){
    int v = queue[sq];
    sq = (sq+1)%4500;
    return v;
}
void addEdge(int from,int to){
    nodes[from].edges[nodes[from].ed_cnt++]=to;
}
void bfs(int node,int t){
    addToQueue(node);
    while(!isEmpty()){
        int n = remove();
        if(!nodes[n].visited){
            nodes[n].visited=true;
            if(nodes[n].parent>=0){
                nodes[n].dist[t]=nodes[nodes[n].parent].dist[t]+1;
            } else {
                nodes[n].dist[t]=0;
            }
            // add all children to queue
            for(int i=0;i<nodes[n].ed_cnt;i++){
                addToQueue(nodes[n].edges[i]);
                nodes[nodes[n].edges[i]].parent=n;
            }
        }

    }
}
int main() {
    ofstream fout ("maze1.out");
    ifstream fin ("maze1.in");
    int w,h;
    fin >>w>>h;
    fin.getline(buff,2*w+2+40,'\n');
    int number=0;
    int ti[4],tj[4],tc=0;
    for(int i=0;i<(2*h+1);i++){
        fin.getline(buff,2*w+2+40,'\n');
        //printf("%s\n",buff);
        for(int j=0;j<(2*w+1);j++){
            if(buff[j]!=' '){
                mazeinp[i][j]=WALL;
            } else if(i%2>0&&j%2>0){
                mazeinp[i][j]=number;
                number++;
            } else {
                if(i==0){
                    ti[tc]=i+1;tj[tc++]=j;
                } else if(j==0){
                    ti[tc]=i;tj[tc++]=j+1;
                } else if(i==2*h){
                    ti[tc]=i-1;tj[tc++]=j;
                } else if(j==(2*w)){
                    ti[tc]=i;tj[tc++]=j-1;
                }
                mazeinp[i][j]=TRANS;
            }
            //  printf("%5d",mazeinp[i][j]);
        }
        /*        buff[2*w+1]=0;*/
        //printf("\n");
    }
    //printf("Number :%d\n",number);
    // intitialize;
    for(int i=0;i<(2*h+1);i++){
        for(int j=0;j<(2*w+1);j++){
            if(mazeinp[i][j]!=WALL&&mazeinp[i][j]!=TRANS){
                if((i-2)>=0&&mazeinp[i-1][j]!=WALL){
                    addEdge(mazeinp[i][j],mazeinp[i-2][j]);

                } 
                if((j-2)>=0&&mazeinp[i][j-1]!=WALL){
                    addEdge(mazeinp[i][j],mazeinp[i][j-2]);
                } 
                if((i+2)<(2*h+1)&&mazeinp[i+1][j]!=WALL){
                    addEdge(mazeinp[i][j],mazeinp[i+2][j]);
                } 
                if((j+2)<(2*w+1)&&mazeinp[i][j+1]!=WALL){
                    addEdge(mazeinp[i][j],mazeinp[i][j+2]);
                } 

            }
        }
    }
    int target[4];

    target[0]=mazeinp[ti[0]][tj[0]];target[1]=mazeinp[ti[1]][tj[1]];
    bfs(target[0],0);
    // reset ds
    for(int i=0;i<number;i++){
        nodes[i].visited=false;
        nodes[i].parent=-1;
    }
    sq=eq=0;
    bfs(target[1],1);
    int max_path=0;
    for(int i=0;i<number;i++){
        int min_path=(1<<29);
        min_path = min(nodes[i].dist[0],nodes[i].dist[1]);
        if(min_path>max_path){
            max_path=min_path;
        }
    }
    fout <<max_path+1<< endl;
    return 0;
}

