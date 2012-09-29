#include<iostream>
#include<cstdlib>
#include<sstream>
#include<string>
#include<ctime>
using namespace std;
void  genTestCase(){
   int max_text_size=90; // 90 chars
   int text_size = 2+rand()%(max_text_size-2);
   stringstream text_stream;
   for(int i=0;i<text_size;i++){
       text_stream<<(char )(65+rand()%26);
   }
   string text = text_stream.str();
   cout<<text<<endl;
   int st = rand()%(text.length()-1);
   int len = 1+rand()%(text.length()-st-1);
//   cout<<st<<" "<<len<<endl;
   cout<<text.substr(st,len)<<endl;
   
}
int main(){
   int num_test_case=10;
   srand(time(NULL));
   for(int i=0;i<num_test_case;i++){
       genTestCase();
   }   
}
