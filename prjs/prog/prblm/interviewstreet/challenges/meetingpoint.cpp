/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<stdio.h>
#include<algorithm>
using namespace std;
class Point{
    public:
    long long x,y;
}p[100005];
bool mycomp1(Point p1,Point p2){
    return p1.x<p2.x;
}
bool mycomp2(Point p1,Point p2){
    return p1.y<p2.y;
}

long long abs1(long long p1){
    if(p1<0) return 0-p1;
    return p1;
}
long long max1(long long a,long long b){
    return a>b?a:b;
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lld %lld",&(p[i].x),&(p[i].y));
    }
    sort(p,p+N,mycomp1);
    long long min1x=p[0].x,min1y=p[0].y;   
    long long mind1=0;
    for(int i=1;i<N;i++){
        mind1+=p[i].x>min1x?p[i].x-min1x:min1x-p[i].x;
    }
    long long lastd=mind1;
    for(int i=1;i<N;i++){
        long long dst = p[i-1].x>p[i].x?p[i-1].x-p[i].x:p[i].x-p[i-1].x;
        lastd = lastd + i*dst - (N-i)*dst;
            if(lastd<mind1){
                min1x=p[i].x;
                min1y=p[i].y;
                mind1=lastd;
            }
    }
    long long can1=0;
    for(int i=0;i<N;i++){
        can1+= max1(abs1(p[i].x-min1x),abs1(p[i].y-min1y));
    }
    sort(p,p+N,mycomp2);   
    mind1=0;   min1x=p[0].x;
    min1y = p[0].y;
    for(int i=1;i<N;i++){
        mind1+=p[i].y>min1y?p[i].y-min1y:min1y-p[i].y;
    }
    lastd=mind1;
     for(int i=1;i<N;i++){
        long long dst = p[i-1].y>p[i].y?p[i-1].y-p[i].y:p[i].y-p[i-1].y;
        lastd = lastd + i*dst - (N-i)*dst;
            if(lastd<mind1){
                min1x=p[i].x;
                min1y=p[i].y;
                mind1=lastd;
            }
    }
    long long can2=0;
     for(int i=0;i<N;i++){
        can2+= max1(abs1(p[i].x-min1x),abs1(p[i].y-min1y));
    }
    printf("%lld\n",can1<can2?can1:can2);
}
