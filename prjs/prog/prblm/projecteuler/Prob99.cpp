#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main(){
double b,e;
double sb,se;
double val=0;
int line=0;
int sl;
while(scanf("%lf,%lf",&b,&e)>0){
	sb=b; se=e;
	double newval=e*log10(b);
	if(newval>val){
		val=newval;
		sb=b;
		se=e;
		sl=line;
	}
	line++;
}
cout<<sb<<","<<se<<" "<<sl<<endl;

}
