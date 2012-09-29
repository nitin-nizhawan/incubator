/*
ID: nitin.n1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
char pat[10][10];
char patf[10][10];
char pat2[10][10];
int size;
void reflect(){
    for(int i=0;i<size;i++){
        for(int j=0;j<(size/2);j++){
           char tmp = pat2[i][j];
           pat2[i][j] = pat2[i][size-j-1];
           pat2[i][size-j-1]=tmp;
        }
    }
}
void rotate90(){
    char tmp[10][10];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            tmp[i][j] = pat2[size-j-1][i];
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            pat2[i][j]  = tmp[i][j];
        }
    }
    
}
void rotate180(){
   rotate90();
   rotate90();
}
void rotate270(){
   rotate90();
   rotate90();
   rotate90();
}
bool match(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(patf[i][j]!=pat2[i][j]){
                return false;
            }
        }
    }   
    return true;
}
void init(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            pat2[i][j]=pat[i][j];
        }
    }
}
int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int a, b;
    fin >> size;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            fin>>pat[i][j];
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            fin>>patf[i][j];
        }
    }
   
    init();
    rotate90();
    if(match()){
        fout<<1<<endl;
        return 0;
    } 
    rotate90(); 
    if(match()){
        fout<<2<<endl;
        return 0;
    } 
    rotate90(); 
    if(match()){
        fout<<3<<endl;
        return 0;
    } 
  /////
    init();
    reflect();
    if(match()){
        fout<<4<<endl;
        return 0;
    } 
    rotate90();
    if(match()){
        fout<<5<<endl;
        return 0;
    }
    rotate90();
    if(match()){
        fout<<5<<endl;
        return 0;
    }
    rotate90();
    if(match()){
        fout<<5<<endl;
        return 0;
    }
    init();
    if(match()){
        fout<<6<<endl;
        return 0;
    } 
    fout<<7<<endl;
    return 0;
}

