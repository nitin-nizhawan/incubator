/*
ID: nitin.n1
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
int adj[200][200];
double dist[200][200];
char buff[200];
int N;
double x[200],y[200];
int main() {
    ofstream fout ("cowtour.out");
    ifstream fin ("cowtour.in");
    int a, b;
    fin >>N;
    for(int i=0;i<N;i++){
        fin>>x[i]>>y[i];
    }
    for(int i=0;i<N;i++){
        fin>>buff;
        for(int j=0;j<N;j++){
            dist[i][j] = 2000000000.0;
            if(buff[j]=='0'){
                adj[i][j]=0;
            } else {
                adj[i][j]=1;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(adj[i][j]==1||adj[j][i]==1){
                double dx = x[i]-x[j];
                double dy = y[i]-y[j];
                dist[i][j] = pow(dx*dx+dy*dy,0.5);
                dist[j][i] = pow(dx*dx+dy*dy,0.5);
                adj[i][j] = adj[j][i] =1;
            } 
        }
    }
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
                if(adj[i][k]>0&&adj[k][j]>0){
                    adj[i][j] = 1;
                }
            }
        }
    }
    double maxdis[200];
    for(int i=0;i<N;i++){
        maxdis[i]=0;
        for(int j=0;j<N;j++){
            if(i!=j&&adj[i][j]>0){
                if(dist[i][j]>maxdis[i]){
                    maxdis[i]=dist[i][j];
                }
            }
        }
    }
    int comp_id[200]={0};
    int COLOR=1;
    for(int i=0;i<N;i++){
        comp_id[i]=0;
    }
    comp_id[0]=COLOR;
    for(int i=1;i<N;i++){
        for(int j=0;j<N;j++){
            if(adj[j][i]>0||adj[i][j]>0){
                if(comp_id[j]>0&&i!=j){
                    comp_id[i]=comp_id[j];
                    break;
                }
            }
        }
        if(comp_id[i]<1){
            comp_id[i]=++COLOR;
        }
    }
    double comp_dia[200]={0.0};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(comp_id[i]==comp_id[j]&&i!=j){
                if(dist[i][j]>comp_dia[comp_id[i]-1]){
                    comp_dia[comp_id[i]-1]=dist[i][j];
                }
            }
        }
    }
    double mindia = (1<<30);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            double dia = maxdis[i]+maxdis[j] + pow((x[i]-x[j])*(x[i]-x[j])+ (y[i]-y[j])*(y[i]-y[j]),0.5);
            if(dia<comp_dia[comp_id[i]-1]){
                dia = comp_dia[comp_id[i]-1];
            }
            if(dia<comp_dia[comp_id[j]-1]){
                dia = comp_dia[comp_id[j]-1];
            }
            if(adj[i][j]<1&&i!=j){
                if(dia<mindia){
                    mindia = dia;
                }
            }
        }
    }
    buff [40];
    sprintf(buff,"%f",mindia);
    fout<<buff<<"\n";
/*    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%12.5f ",dist[i][j]);
        }
        printf("\n");
    }*/
    
    return 0;
}

