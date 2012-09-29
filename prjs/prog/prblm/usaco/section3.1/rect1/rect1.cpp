
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
    //printf("append st   ");
    Rect *ar = new Rect;
    ar->llx=llx;
    ar->lly=lly;
    ar->urx=urx;
    ar->ury=ury;
    ar->color = color;
    ar->next = head->next;
    if(head->next) head->next->prev=ar;
    ar->prev = head;
    head->next = ar;
    //printf("append end\n");
}
bool intersect(int i,int llx,int lly,int urx,int ury,int color){
}
bool zeroArea(Rect* r){
    int w = (r->urx)-(r->llx);
    int l = (r->ury)-(r->lly);
    return w==0||l==0;
}
void addRect(int llx,int lly,int urx,int ury,int color){
    if(urx-llx==0||ury-lly==0){
        return;
    }
    int numPresent = cN;
    Rect *rect = head->next;
    while(rect!=NULL){
        // test intersection cases
        //p2=i;
        if(zeroArea(rect)){
            continue;
        }
        bool intersects=false;
        if(ury<rect->ury&&ury>rect->lly&&llx<rect->urx&&urx>rect->llx){
            append(max(llx,rect->llx),ury,min(urx,rect->urx),rect->ury,rect->color);
            intersects=true;
        }
        if(llx>rect->llx&&llx<rect->urx&&lly<rect->ury&&ury>rect->lly){
            append(rect->llx,rect->lly,llx,rect->ury,rect->color);
            intersects=true;
        }
        if(lly>rect->lly&&lly<rect->ury&&llx<rect->urx&&urx>rect->llx){
            append(max(llx,rect->llx),rect->lly,min(rect->urx,urx),lly,rect->color);
            intersects=true;
        }
        if(urx<rect->urx&&urx>rect->llx&&ury>rect->lly&&lly<rect->ury){
            append(urx,rect->lly,rect->urx,rect->ury,rect->color);
            intersects=true;
        }
        Rect *tmp = rect->next;
        if(intersects||(llx<=rect->llx&&lly<=rect->lly&&urx>=rect->urx&&ury>=rect->ury)){
            //if(rect->prev!=NULL){
                rect->prev->next=rect->next;
            //}
            if(rect->next!=NULL){
                rect->next->prev = rect->prev;
            }
            delete rect;
        } 
      // printf("rect=tmp begin");
        rect = tmp;
        //printf("end \n");
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
    head = new Rect;
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
    Rect *rect = head->next;
    while(rect!=NULL){
        cAns[rect->color]+=(rect->urx-rect->llx)*(rect->ury-rect->lly);
        rect=rect->next;
//        if(rect&&rect->prev) delete rect->prev;
    }
    rect=head->next;
    while(rect!=NULL){
        rect=rect->next;
        if(rect&&rect->prev) delete rect->prev;
     }
    for(int i=0;i<cols_n;i++){
        cols[i].val=cAns[cols[i].col];
    }
    sort(cols,cols+cols_n,mycomp);
    for(int i=0;i<cols_n;i++){
        if(cols[i].val>0){
            fout<<cols[i].col<<" "<<cols[i].val<<"\n";
        }
    }
}
