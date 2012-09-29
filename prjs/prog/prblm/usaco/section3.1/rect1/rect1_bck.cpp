
/*
ID:nitin.n1
PROG: rect1
LANG: C++
*/
#include<fstream>
#include<iostream>
#include<algorithm>
#define MAX_MEM 5000
using namespace std;

//datastructures
class Rect {
    public:
    int llx,lly,urx,ury;
    int color;
    Rect *next;
    Rect *prev;
    Rect(){
        next = NULL;
        prev=NULL;
    }
};
Rect *head;
ifstream fin("rect1.in");
ofstream fout("rect1.out");
int A,B,N,cN=0;
int llx[1005],lly[1005],urx[1005],ury[1005];
bool cHash[1005];
int cAns[1005];
int p1=0,p2=0;
void append(int llx,int lly,int urx,int ury,int color){
    rects[cN].llx=llx;
    rects[cN].lly=lly;
    rects[cN].urx=urx;
    rects[cN].ury=ury;
    rects[cN].color = color;
}
bool intersect(int i,int llx,int lly,int urx,int ury,int color){
}
bool zeroArea(int i){
    int w = rects[i].urx-rects[i].llx;
    int l = rects[i].ury-rects[i].lly;
    return w==0||l==0;
}
void addRect(int llx,int lly,int urx,int ury,int color){
    if(urx-llx==0||ury-lly==0){
        return;
    }
    int numPresent = cN;
    
    for(int i=0;i<numPresent;i++){
        // test intersection cases
        p2=i;
        if(zeroArea(i)){
            continue;
        }
        bool intersects=false;
        if(ury<rects[i].ury&&ury>rects[i].lly&&llx<rects[i].urx&&urx>rects[i].llx){
            append(max(llx,rects[i].llx),ury,min(urx,rects[i].urx),rects[i].ury,rects[i].color);
            intersects=true;
        }
        if(llx>rects[i].llx&&llx<rects[i].urx&&lly<rects[i].ury&&ury>rects[i].lly){
            append(rects[i].llx,rects[i].lly,llx,rects[i].ury,rects[i].color);
            intersects=true;
        }
        if(lly>rects[i].lly&&lly<rects[i].ury&&llx<rects[i].urx&&urx>rects[i].llx){
            append(max(llx,rects[i].llx),rects[i].lly,min(rects[i].urx,urx),lly,rects[i].color);
            intersects=true;
        }
        if(urx<rects[i].urx&&urx>rects[i].llx&&ury>rects[i].lly&&lly<rects[i].ury){
            append(urx,rects[i].lly,rects[i].urx,rects[i].ury,rects[i].color);
            intersects=true;
        }
        if(intersects||(llx<=rects[i].llx&&lly<=rects[i].lly&&urx>=rects[i].urx&&ury>=rects[i].ury)){
            rects[i].llx=rects[i].lly=rects[i].urx=rects[i].ury=rects[i].color=0;
        }

    }
    append(llx,lly,urx,ury,color);
}
class Color{
    public:
    int col;
    int val;
    Color(){
        col=0;
        val=0;
    }
};
Color cols[1005];
int cols_n=0;
bool mycomp(Color a , Color b){
    return a.col<b.col;
}
int main(){
    fin>>A>>B>>N;
    append(0,0,A,B,1);//base rect
    cHash[1]=true;
    cols[cols_n++].col=1;
    int llx,lly,urx,ury,color;

    for(int i=0;i<N;i++){
        p1=i;
        fin>>llx>>lly>>urx>>ury>>color;
        addRect(llx,lly,urx,ury,color);
        if(cHash[color]==false){
            cHash[color]=true;
            cols[cols_n++].col=color;
        }
    }
    for(int i=0;i<cN;i++){
        cAns[rects[i].color]+=(rects[i].urx-rects[i].llx)*(rects[i].ury-rects[i].lly);
    }
    for(int i=0;i<cols_n;i++){
        cols[i].val=cAns[cols[i].col];
    }
    sort(cols,cols+cols_n,mycomp);
    for(int i=0;i<=cols_n;i++){
        if(cols[i].val>0){
            fout<<cols[i].col<<" "<<cols[i].val<<"\n";
        }
    }
}
