#include<iostream>
#include<stdlib.h>

using namespace std;


int main(int argc,char* argv[]){
    int size = atoi(argv[1]);
    int num = atoi(argv[2]);
    int N = rand()%size + 1;
    int M = rand()%num + 1;
    cout<<N<<" "<<M<<"\n";
    while(M--){
        int A = (N+1>0)?rand()%(N+1):0;
        int B = (N-A>0)?rand()%(N - A) + 1:0;
        int C = (N-B+1>0)?rand()%(N-B+1):0;
        cout<<A<<" "<<B<<" "<<C<<"\n";
    }
}
