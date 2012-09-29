/*
ID: nitin.n1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int days[7]={0};
bool isLeapYear(int y){
    if((y%100)==0){
        return ((y%400)==0);
    } else {
        return ((y%4)==0);
    }
}
int dayon13th(int m,int y,int ld){
    if(m==1&&y==1900){
        return 6;
    }
    int lm = (m==1)?12:(m-1);
    switch(lm){
       case 1: 
       case 3:
       case 5:
       case 7:
       case 8:
       case 10:
       case 12:
       return (ld+31)%7;
       break;
       case 4: 
       case 6: 
       case 9: 
       case 11:
       return (ld+30)%7;
       break;
       case 2:
        return isLeapYear(y)?(ld+29)%7:(ld+28)%7;
       break;
    }
}
int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    fin >> n ;
int ld=6;   
    int lastyear = 1900+n;
  for(int y=1900;y<lastyear;y++){
      for(int m=1;m<=12;m++){
         ld = dayon13th(m,y,ld);
          days[ld]++;
      }
  }
  fout<<days[6]<<" "<<days[0]<<" "<<days[1]<<" "<<days[2]<<" "<<days[3]<<" "<<days[4]<<" "<<days[5]<<endl;
    return 0;
}

