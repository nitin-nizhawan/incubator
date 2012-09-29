/*
ID: nitin.n1
PROG: jungle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("jungle.out");
    ifstream fin ("jungle.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}

