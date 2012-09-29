/*
ID: nitin.n1
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
char prefixes[400][19];
int prefix_count=0;
int prefix_len[400]={0};
char seq[300000];
bool isprefix[300000]={false};
int main() {
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
    int count=0;
    do{
       fin>>prefixes[count++];
    }while(prefixes[count-1][0]!='.');
    prefix_count = count -1;
    int read=0;
    int i=0;
    int old_i=0;
    while(true){
        fin>>(&seq[i]);
        while(seq[i]!='\0'){ i++; }
        if(old_i==i){
            break;
        }
        old_i = i;
    }
    seq[i]='\0';

    // calc prefix len;
    for(int i=0;i<prefix_count;i++){
        int len =0;
        while(prefixes[i][len++]!='\0');
        prefix_len[i]=len-1;
    }
    int ans=0;
    for(int i=0;seq[i]!='\0';i++){
        for(int j=0;j<prefix_count;j++){
            int start_pos = i-prefix_len[j]+1;
            bool matches = true;
            if(start_pos>=0){
            for(int k=0;k<prefix_len[j];k++){
                if(prefixes[j][k]!=seq[start_pos+k]){
                    matches = false;
                    break;
                }
            }
            }
            if(matches){
                if(start_pos>0){
                    if(isprefix[start_pos-1]){
                        isprefix[i] = true;//isprefix[start_pos-1];
                    }
                } else if(start_pos==0){
                    isprefix[i]=true;
                } 
            }
        }
        if(isprefix[i]==true){
            ans = i+1;
        }
    }
    fout<<ans<<"\n";
    return 0;
}

