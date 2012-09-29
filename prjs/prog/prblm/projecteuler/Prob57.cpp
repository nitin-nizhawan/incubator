#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull gcd(ull m,ull n){
	ull tmp;
	while(n>0){
		tmp = m%n;
		m=n;
		n=tmp;
	}
	return m;
}
ull d(ull n){
	ull size=0;
	while(n>0){
		n=n/10;
		size++;
	}
	return size;
}
int main(){
	ull p=3,q=2,tp,tq;
	ull count=1;
	ull result=0;
	while(count<1001){
	    tp = p+q+q;
	    tq = p+q; 
            p = tp; q = tq;
	    tp = gcd(p,q);
	    p = p/tp;
	    q= q/tp;
	    if(d(p)>d(q)){
		    result++;
	    } 
	    cout<<p<<"/"<<q<<" ----- "<<result<<endl;
            count++;
	}
        cout<<result<<endl;

}
