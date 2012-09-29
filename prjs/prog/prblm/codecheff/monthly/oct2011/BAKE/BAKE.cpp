#include<stdio.h>
int db [11][4][11][21][6][2][91]={0};
char ind[200];
const int TP=0;
const int PID=1;
const int SZ=2;
const int PRO=3;
const int CTY=4;
const int REG=5;
const int GEN=6;
const int SAGE=7;
const int EAGE=8;
const int VAL=9;
int inp[20];
void addItem(){
    int pid = (inp[PID]>=0)?inp[PID]:10;
    int sz = (inp[SZ]>=0)?inp[SZ]:3;

    int pro = (inp[PRO]>=0)?inp[PRO]:10;
    int cty = (inp[CTY]>=0)?inp[CTY]:20;
    int reg = (inp[REG]>=0)?inp[REG]:5;

    int gen = inp[GEN];
    int age = inp[SAGE]-1;
    db[pid][sz][pro][cty][reg][gen][age]+=inp[VAL];
}
void query(){
    int s_pid=0,e_pid=10;
    int s_sz=0,e_sz=3;

    int s_pro=0,e_pro=10;
    int s_cty=0,e_cty=20;
    int s_reg=0,e_reg=5;
    int gen = inp[GEN];
    int s_age=inp[SAGE]-1,e_age=inp[EAGE]-1;
    if(inp[PID]>-1){
        s_pid = e_pid = inp[PID];
        if(inp[SZ]>-1){
            s_sz = e_sz = inp[SZ];

        }
    } 
    if(inp[PRO]>-1){
        s_pro=e_pro=inp[PRO];
        if(inp[CTY]>-1){
            s_cty = e_cty = inp[CTY];
            if(inp[REG]>-1){
                s_reg = e_reg = inp[REG];
            }
        }
    }
    if(inp[EAGE]<0){
        s_age = e_age = inp[SAGE];
    }
    long sum=0;
    for(int pid=s_pid;pid<=e_pid;pid++){
        for(int sz=s_sz;sz<=e_sz;sz++){
            for(int pro=s_pro;pro<=e_pro;pro++){
                for(int cty=s_cty;cty<=e_cty;cty++){
                    for(int reg=s_reg;reg<=e_reg;reg++){
                        for(int age=s_age;age<=e_age;age++){
                            sum+=db[pid][sz][pro][cty][reg][gen][age];
                        }
                    }
                }
            }
        }
    }
    printf("%ld\n",sum);
        //printf("Hello: %s\n",ind);
}
int main(){
    int T;
    scanf("%d",&T);
    fgets(ind,200,stdin);
    char rt;
    while(T--){

        inp[TP]=-1,inp[PID] = -1,inp[SZ]= -1,inp[PRO]=-1,inp[CTY] =-1, inp[REG]=-1 ,inp[GEN]=0, inp[SAGE]=-1,inp[EAGE]=-1, inp[VAL]=0;
        fgets(ind,200,stdin);
        int i=0,v=0;
        if(ind[i]=='I'){
            inp[v]=0;
        } else {
            inp[v]=1;
        }
        i++;i++;v=PID;
        if(ind[i]!='-'){
            inp[v]=0;
            while(ind[i]!='.'&&ind[i]!=' '){
                inp[v]=inp[v]*10+(ind[i]-'0');
                i++;
            };;
            v++;
            if(ind[i]!=' '){
                i++; inp[v]=0; 
                while(ind[i]!=' '){
                    inp[v] = inp[v]*10+(ind[i]-'0');
                    i++;
                }
            }
            v++;i++;
        } else {
            i++;i++;i++;
            v=PRO;
        }
        if(ind[i]!='-'){
            inp[v]=0;
            while(ind[i]!='.'&&ind[i]!=' '){
                inp[v]=inp[v]*10+(ind[i]-'0');
                i++;
            }
            if(ind[i]!=' '){
                v++; i++;inp[v]=0; 
                while(ind[i]!='.'&&ind[i]!=' '){
                    inp[v] = inp[v]*10+(ind[i]-'0');
                    i++;
                }
                if(ind[i]!=' '){
                    v++; i++;inp[v]=0; 
                    while(ind[i]!=' '){
                        inp[v] = inp[v]*10+(ind[i]-'0');
                        i++;
                    }
                }
            }
            v=GEN; i++;
        } else {
            i++;i++;i++;
            v=GEN;
        }
        if(ind[i]=='F'){
            inp[v]=1;
        } else {
            inp[v]=0;
        }
        i++;i++;v++;
        while(ind[i]!='-'&&ind[i]!=' '&&ind[i]!='\0'){
            inp[v]= inp[v]*10 + (ind[i]-'0');
            i++;
        }
        if(ind[i]==' '){
            v=VAL; i++;inp[v]=0;
            while(ind[i]!='\0'&&ind[i]!=' '&&ind[i]!='\n'){
                inp[v]=inp[v]*10 + (ind[i]-'0');
                i++;
            }
        } else if(ind[i]=='-'){
            v=EAGE;i++;inp[v]=0;
            while(ind[i]!='\0'&&ind[i]!=' '&&ind[i]!='\n'){
                inp[v]=inp[v]*10 + (ind[i]-'0');
                i++;
            }
        } else {
            // end
        }
        if(inp[TP]==0){
            addItem();
        } else {
            query();
        }
    }

}
