#include<stdio.h>
#define EXPMAX 65000
int N;
long long pos[500];
bool dir[500];
int Q;
int qN;
long long qT;
double sim_pos[EXPMAX][500];
int sim_cnt[EXPMAX][500];
double sim_t[EXPMAX];
bool sim_dir[EXPMAX][500];
int c_row;
void solve(){
    for(int i=0;i<N;i++){
        sim_pos[0][i] = pos[i];
        sim_cnt[0][i]=0;
        sim_dir[0][i] = dir[i];
    }
    sim_t[0]=0;
    int p1[500],p2[500];
    int pcnt=0;
    int min_p1[500],min_p2[500];
    int min_pcnt=0;
    c_row=0;
    do {
        pcnt=0;
        min_pcnt=0;
        bool first_found=false;
        for(int i=0;i<N;i++){
           if(sim_dir[c_row][i]==0){
               if(first_found){
                   first_found=false;
                   p2[pcnt++]=i;
               } 
           } else {
               p1[pcnt]=i;
               first_found=true;
           }
        }
        if(pcnt>0){
            double min_dist = sim_pos[c_row][p2[0]] - sim_pos[c_row][p1[0]];
            for(int i=1;i<pcnt;i++){
                double dist = sim_pos[c_row][p2[i]] - sim_pos[c_row][p1[i]];
                if(dist<min_dist){
                    dist=min_dist;
                }
            }
            for(int i=0;i<pcnt;i++){
                double dist = sim_pos[c_row][p2[i]] - sim_pos[c_row][p1[i]];
                if( min_dist = dist){
                    min_p1[min_pcnt]=p1[i];
                    min_p2[min_pcnt]=p2[i];
                }
            }

            double t_up = min_dist/2;
            double last;
            sim_t[c_row+1] = sim_t[c_row]+t_up;
            for(int i=0;i<N;i++){
                sim_cnt[c_row+1][i] = sim_cnt[c_row][i];
                if(sim_dir[c_row][i]==1){
                    sim_pos[c_row+1][i]= sim_pos[c_row][i] + t_up;
                } else {
                    sim_pos[c_row+1][i] = sim_pos[c_row][i] - t_up;
                }
                if(i==0){
                    last = sim_pos[c_row+1][i];
                    sim_dir[c_row+1][i] = sim_dir[c_row][i];
                } else {
                    sim_dir[c_row+1][i] = sim_dir[c_row][i];
                    if(last==sim_pos[c_row+1][i]){
                        sim_dir[c_row+1][i-1] = 1 - sim_dir[c_row][i-1];
                        sim_dir[c_row+1][i] = 1 - sim_dir[c_row][i];
                        sim_cnt[c_row+1][i-1]+1;
                        sim_cnt[c_row+1][i]+1;
                    }
                    last = sim_pos[c_row+1][i];
                }
            }
            c_row++;

        }
    } while(pcnt>0);
}
void query(){
      
}
int main(){
    int T,tmp;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%lld",&pos[i]);
        }
        for(int i=0;i<N;i++){
            scanf("%d",&tmp);
            dir[i]=(tmp>0)?1:0;
        }
        solve();
        scanf("%d",Q);
        for(int i=0;i<Q;i++){
            scanf("%d",&qN);
            scanf("%lld",&qT);
            query();
        }
    }
}
