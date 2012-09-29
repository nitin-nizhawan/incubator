#include<iostream>
#include<algorithm>
#include<cassert>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int find(int key, int* ar, int sz){
    int a=0, b=sz-1;
    while(a<=b){
        int m = (a+b)/2;
        if(key == ar[m])
            return m;
        if(key>ar[m])
            a=m+1;
        else
            b=m;
    }
    assert(false);
    return -1;
}

void solve_case(){
    int N;
    cin>>N;
    int pos[N], dir[N];
    for(int i=0; i<N; i++)
        cin>>pos[i];
    for(int i=0; i<N; i++)
        cin>>dir[i];

    int Q;
    cin>>Q;
    for(int q=0; q<Q; q++){
        int I, T;
        cin>>I>>T;
        int final_pos[N], sorted_final[N], rev_count = 0;
        for(int i=0; i<N; i++){
            if(dir[i]==0)
                final_pos[i] = pos[i] - T;
            else
                final_pos[i] = pos[i] + T;
            sorted_final[i] = final_pos[i];
        }
        sort(sorted_final, sorted_final + N);
        for(int i=0; i<N; i++){
            if(final_pos[i]==sorted_final[I]){
                rev_count++;
                continue;
            }
            int rank = find(final_pos[i], sorted_final, N);
            if((I-i)*(I-rank)<=0)
                rev_count++;
        }
        
        cout<<sorted_final[I]<<" "<<--rev_count<<endl;
    }
    return;
}

int main(){
    int T;
    cin>>T;
    for(int i=0; i<T; i++)
        solve_case();

    return 0;
}



