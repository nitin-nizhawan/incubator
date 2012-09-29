/*
ID: nitin.n1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    int n;
    fin >>n;
    int a =0,b=1,c=1,d=n,p=0,q=0;
        fout<<a<<"/"<<b<<"\n";
        fout<<c<<"/"<<d<<"\n";
    while(c!=1||d!=1){
        int k = (b+n)/d;
        p = k*c - a;
        q = k*d - b;
        fout<<p<<"/"<<q<<"\n";
        // move ahead;
        a=c;b=d;c=p;d=q;
    }
    return 0;
}

