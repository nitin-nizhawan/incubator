/*
ID: nitin.n1
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int nodes[567890]={-1};
int pnodes[567890]={-1};
int stack[20],top=-1;
class Ans{
    public:
    char res[50];
};
vector<Ans> ans;
int anscnt=0;
int a, b;
void printsol(){
//    printf("%d",1);
    ans[anscnt].res[0]='1';
    char pchar[]={'+','-',' '};
    int i=1;
    for(i=1;i<=top;i++){
        ans[anscnt].res[2*i-1]=pchar[stack[i]];
        ans[anscnt].res[2*i] = '0'+i+1;
    }
    ans[anscnt].res[2*i - 1]='\0';
    anscnt++;
//    printf("\n");
}
void dodfs(int node){
    if((top+1)==a){
        if(nodes[node]==0){
            printsol();
        }
    }
    if((top+1)>=a){
        return;
    }
    for(int i=0;i<3;i++){
        stack[++top]=i;
        if(i==0){
            pnodes[node+1+i*3] = top+1;
            nodes[node+1+i*3] = nodes[node] + pnodes[node+1+i*3];
        } else if(i==1){
            pnodes[node+1+i*3] = -top-1;
            nodes[node+1+i*3] = nodes[node] + pnodes[node+1+i*3];
        } else {
            int newval =0;
            if(pnodes[node]>0){
                newval = pnodes[node]*10 + top +1;
            } else {
                newval = pnodes[node]*10 - top -1;
            }
            pnodes[node+1+i*3] = newval;
            nodes[node+1+i*3] = nodes[node] - pnodes[node] + pnodes[node+1+i*3];
        }
        dodfs(node+1+i*3);
        stack[top--];
    }
}
int mystrcmp(char* a, char *b){
    while(*a!='\0'&&*b!='\0'){
        if(*a!=*b){
            return *a-*b;
        }
        a++;b++;
    }
    return 0;
}
bool mycomp(Ans a, Ans b){
    return mystrcmp(a.res,b.res)<0;
}
int main() {
    ans.resize(6000);
    ofstream fout ("zerosum.out");
    ifstream fin ("zerosum.in");
    fin >> a;
    nodes[0]=1;
    pnodes[0]=1;
    stack[++top]=0;
    dodfs(0);
    stack[top--];
    sort(ans.begin(),ans.begin()+anscnt,mycomp);

    // printfoutput
    for(int i=0;i<anscnt;i++){
        fout<<ans[i].res<<"\n";
    }
    return 0;
}

