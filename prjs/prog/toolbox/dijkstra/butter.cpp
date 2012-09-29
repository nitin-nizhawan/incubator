/*
ID: nitin.n1
PROG: butter
LANG: C++
*/
#include<queue>
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("butter.in");
ofstream fout("butter.out");
int N,P,C;
struct edge
{
    int v,w;
    edge(int _w,int _v):w(_w),v(_v){}
};
vector<vector<edge> > g;
int edcnt[1000];
int ttl[1000];
int cows[2000];
int cown=0;
enum color {white,gray,black};
vector<int> dijkstra(int s)
{
    int n=g.size();
    vector<int> d(n,-1);
    vector<color> c(n,white);
    d[s]=0;
    c[s]=gray;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; // declare priority_queue
    q.push(make_pair(d[s],s)); //push starting vertex
    while(!q.empty())
    {
        int u=q.top().second;q.pop(); //pop vertex from queue
        if(c[u]==black)continue;
        c[u]=black; 
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i].v,w=g[u][i].w;
            if(c[v]==white) //new vertex found
            {
                d[v]=d[u]+w;
                c[v]=gray;
                q.push(make_pair(d[v],v)); //add vertex to queue
            }
            else if(c[v]==gray && d[v]>d[u]+w) //shorter path to gray vertex found
            {
                d[v]=d[u]+w;
                q.push(make_pair(d[v],v)); //push this vertex to queue
            }
        }
    }
    return d;
}

int main(){
    
    fin>>N>>P>>C;
    for(int i=0;i<N;i++){
        fin>>cows[cown];
        cows[cown]--;
        cown++;
    }
    for(int i=0;i<P;i++){
       g.push_back(*(new vector<edge>));
    }
    for(int i=0;i<C;i++){
        int t1,t2,t3;
        fin>>t1>>t2>>t3;
        g[t1-1].push_back( *(new edge(t3,t2-1)));
        // add reverse edge
        g[t2-1].push_back( *(new edge(t3,t1-1)));
    }
    int mind=(1<<30);
    for(int i=0;i<cown;i++){
        vector<int> dst = dijkstra(cows[i]);
        //printf("Ran dijkdtra for cow %d\n",cows[i]);
        for(int j=0;j<dst.size();j++){
            //printf("%d,",dst[j]);
            ttl[j]+=dst[j];
        }
        //printf("\n");
    }
    for(int i=0;i<P;i++){
        //printf("%d , ",ttl[i]);
        if(ttl[i]<mind){
            mind = ttl[i];
        }
    }
    //printf("\n");
    fout<<mind<<"\n";

}
