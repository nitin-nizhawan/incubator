/*
ID: nitin.n1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    char ufo[6],comet[6];
    fin >> ufo >> comet;
    int i=0;
    long ufoi=1,cometi=1;
    while(ufo[i]!='\0'){
       long tmp = ufo[i]-'A'+1;
       ufoi = ufoi*tmp;
       i++;
    }
    i=0;
    while(comet[i]!='\0'){
        long tmp = comet[i]-'A'+1;
        cometi = cometi*tmp;
        i++;
    }
    if((cometi%47)==(ufoi%47)){
    fout <<"GO"<< endl;
    } else {
      fout<<"STAY"<<endl;
    }
    return 0;
}

