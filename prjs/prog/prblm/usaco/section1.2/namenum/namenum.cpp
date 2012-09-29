/*
ID: nitin.n1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
char *map[] = {"","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};

                
int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream din("dict.txt");
    char inp[20]={'4'};
    char wrd[20];
    fin >>inp;
    int i=0;
    bool printed=false;
    while((din>>wrd)){
        int j=0;
        while(wrd[j]!='\0'&&inp[j]!='\0'){
             int n = inp[j]-'0';
             if(wrd[j]!=map[n][0]&&wrd[j]!=map[n][1]&&wrd[j]!=map[n][2]){
                 break;
             }
             j++;
        }
        if(inp[j]=='\0'&&wrd[j]=='\0'){
            printed=true;
            fout<<wrd<<endl;
        }
    }
    if(!printed){
         fout<<"NONE"<<endl;
    }
    return 0;
}

