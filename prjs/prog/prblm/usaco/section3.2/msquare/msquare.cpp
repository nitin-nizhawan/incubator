/*
ID: nitin.n1
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#define QLEN (2000000)
using namespace std;
ifstream fin ("msquare.in");
ofstream fout ("msquare.out");
    unsigned iconf=0;
map<unsigned,int> move;
map<unsigned,unsigned> parent;
unsigned Q[QLEN];
int head=0,tail=0;
long long sols[40000];
int soln=0;
bool emptyQ(){
    return head==tail;
}
bool fullQ(){
    return (tail+1)%QLEN == head;
}
unsigned getQ(){
    //printf("head=%d,tail=%d\n",head,tail);
    unsigned v = Q[head];
    head   = (head+1)%QLEN;
    return v;
}
void putQ(unsigned v){
    if(fullQ()){
        printf("Out of Memory");
        head/(head-(tail+1)%QLEN);
    }
    Q[tail]=v;
    tail = (tail+1)%QLEN;
}
unsigned set(unsigned a,unsigned v, int pos){
    v = v&0x0f;
    a&=~(0x0f<<(pos*4));
    a|=(v<<(pos*4));
    return a;
}
unsigned get(unsigned a,int pos){
    return (a>>(pos*4))&0x0f;
}
void printconf(unsigned t){
    for(int i=0;i<8;i++){
        printf("%u",get(t,i));
    }
    printf("\n");
}
unsigned A(unsigned a){
    unsigned ret =0;
    for(int i=0;i<8;i++){
        ret=ret<<4;
        ret|=((a>>(i*4))&0x0f);
    }
    return ret;
}
unsigned B(unsigned b){
    unsigned l = b&0xffff;
    unsigned h = (b>>16)&0xffff;
    h = (((h&0x0f)<<12)|((h>>4)&0x0fff))&0xffff;
    l = (((l>>12)&0x0f)|(l<<4))&0xffff;
    return (h<<16)|l;

}
unsigned C(unsigned c){
    unsigned p2 = get(c,1);
    unsigned p3 = get(c,2);
    unsigned p6 = get(c,5);
    unsigned p7 = get(c,6);
    c = set(c,p2,2);
    c = set(c,p3,5);
    c = set(c,p6,6);
    c = set(c,p7,1);
    return c;
}
unsigned plp1(int sol){
    if(sol==0) return iconf;
    unsigned v = plp1(sol/4);
    if(sol%4==1) {fout<<"A";  return A(v); } 
    if(sol%4==2) {fout<<"B";    return B(v); }
    if(sol%4==3) {fout<<"C";    return C(v); }
}

void printsol1(int sol){
    int len =0;
    int tmp=sol;
    while(tmp>0){
        tmp= tmp/4;
        len++;
    }
    fout<<len<<"\n";
    unsigned v = plp1(sol/4);
    if(sol%4==1) { fout<<"A"; printconf(A(v)); }   
    if(sol%4==2) { fout<<"B";  printconf(B(v)); }  
    if(sol%4==3) { fout<<"C";  printconf(C(v)); }
    fout<<"\n";
}
void ppl(unsigned p){
   if(parent[p]!=0){
       ppl(parent[p]);
       int t = move[p];
       if(t==1) fout<<"A";
       if(t==2) fout<<"B";
       if(t==3) fout<<"C";
   }
}
void printsol(unsigned  sol){
  int len=0;
  unsigned tmp=sol;
  while(parent[tmp]!=0){
      len++;
      tmp = parent[tmp];
  }    
   fout<<len<<"\n";
  ppl(sol);
/*       int t = move[sol];
       if(t==1) fout<<"A";
       if(t==2) fout<<"B";
       if(t==3) fout<<"C";*/
  fout<<"\n";
}
int main(){
    unsigned fconf=0;
    for(int i=0;i<8;i++){
        unsigned tmp;
        fin>>tmp;
        fconf = set(fconf,tmp,i);
        iconf|=((i+1)<<(i*4));
    }
    //printf("fconf = ");
    //printconf(fconf);
    /*
    printfconf(iconf);
    printfconf(A(iconf));
    printfconf(B(iconf));
    printfconf(C(iconf));
    */
    putQ(iconf);
    move[iconf]=0;
    
    while(!emptyQ()){
        unsigned cur = getQ();
        //printconf(cur);
        int path = move[cur];
        unsigned t = A(cur);
        if(move[t]<1&&t!=iconf){
             putQ(t);
             //move[t]=path*4+1;
             move[t]=1;
             parent[t]=cur;
        }
        t = B(cur);
        if(move[t]<1&&t!=iconf){
             putQ(t);
             //move[t]=path*4+2;
             move[t]=2;
             parent[t]=cur;
        }
        t = C(cur);
        if(move[t]<1&&t!=iconf){
             putQ(t);
             //move[t]=path*4+3;
             move[t]=3;
             parent[t]=cur;
        }
        if(cur==fconf){
            printsol(cur);
            break;
        }
    }
    return 0;
}

