/*
ID: nitin.n1
PROG: clocks
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
char *moves[] =
{ "ABDE\0", "ABC\0", "BCEF\0", "ADG\0", "BDEFH\0", "CFI\0", "DEGH\0",
    "GHI\0", "EFHI\0" };

int mlen=1<<29;
int cs[9];
void dfs(int c[], int m, int s[]){
    // check if we have reched
    bool isfinal=true;
    for(int i=0;i<9;i++){
      if(c[i]>0){
          isfinal =false;
          break;
      }
    }
    bool isbetter=false;
    if(isfinal){
        int len=0;
        for(int i=0;i<9;i++) { len+=s[i]; }
        if(len<mlen){
            isbetter = true;
        } else if(len==mlen){
            int i=0;
            while(i<9&&cs[i]==s[i]) i++ ;
            if(i<9&&s[i]>cs[i]){
                isbetter=true;
            }
        }
        if(isbetter){
            // copy;
            for(int  i=0;i<9;i++){
                cs[i]=s[i];
            }
            mlen = len;
        }
    }
    if(m>=9){
        return;
    }
    int t[9];
    for(int i=0;i<9;i++) t[i] = c[i];
    for(int i=0;i<4;i++){
        int j=0;
        while(moves[m][j]!='\0'){
            t[moves[m][j]-'A'] = (c[moves[m][j]-'A']+i)%4;
            j++;
        }
        s[m]=i;
        dfs(t,m+1,s);
/*        j=0;
        while(moves[m][j]!='\0'){
            t[moves[m][j]-'A'] = (c[moves[m][j]-'A'])%4;
            j++;
        } */
 
    }
}
int main () {
    ofstream fout ("clocks.out");
    ifstream fin ("clocks.in");
    int c[9];
    for (int i = 0; i < 9; i++)
    {
        int tmp;
        fin >> tmp;
        c[i] = ((tmp) % 12) / 3;	// maps 12,3,6,9 to 0,1,2,3
    }
//    printf("DEBUG: input:");
    for(int i=0;i<9;i++){
       // printf("%d, ",c[i]);
    }
    //printf("\n");
    int s[9];
    for(int i=0;i<9;i++) s[i]=0;
    dfs(c,0,s);
    char space[2]={'\0'};
    for(int i=0;i<9;i++){
        while(cs[i]--){
            fout<<space<<(i+1);
            space[0] = ' ';
        }
    }
    fout<<endl;

    return 0;
}
