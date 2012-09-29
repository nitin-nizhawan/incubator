
/*
ID:nitin.n1
PROG: contact
LANG: C++
*/
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
int A,B,N;
ifstream fin("contact.in");
ofstream fout("contact.out");
char inpstr[300000];
int pcount[60000]; // initialized to zero
unsigned plist[60000];
int plist_len=0;
void countPattern(unsigned hash,int len){
    pcount[hash]++;
}
unsigned int roll(unsigned hash,int pos,int len){
    hash = hash<<1;
    if(inpstr[pos]=='1'){
        hash = hash|1;
    }
    unsigned mask = 1<<len;
    hash = hash&(mask-1);
    return hash|mask;
}
/*
 * patterns are represented as bits, we also 
 * append 1 bit to differentiate patterns fo different lengths 
 * that begin with zeros. e.g. 
 * 00 => 100, 01 => 101, 10=>110, 11=>111
 * 000=>1000,001=>1001,010=>1010,100=>1100 etc.
*/
unsigned int rollingHash(int len){
    unsigned int hash=0;
    if(inpstr[0]=='1'){
        hash=1;
    }
    for(int i=1;i<len;i++){
        hash = hash<<1;
        if(inpstr[i]=='1'){
            hash = hash|1;
        }
    }
    return (1<<len)|hash;
}
void printPattern(unsigned int pattern){
    char cpatt[40];
    unsigned int mask = 1;
    int cpatt_len=0;
    while(pattern>0){
        cpatt[cpatt_len]='0';
        if((pattern&mask)>0){
            cpatt[cpatt_len]='1';
        }
        cpatt_len++;
        pattern = pattern>>1;
    }
    cpatt_len--; //removing last bit
    cpatt[cpatt_len]='\0';
    for(int i=0;i<cpatt_len/2;i++){
        char tmp = cpatt[i];
        cpatt[i] = cpatt[cpatt_len-i-1];
        cpatt[cpatt_len-i-1]=tmp;
    }
    fout<<cpatt;
}
bool mycomp(unsigned int a, unsigned b){
    if(pcount[a]==pcount[b]){
        return a<b;
    }
    return pcount[a]>pcount[b];
}
int printFreq(int i, int val){
    fout<<pcount[plist[i]]<<"\n";;
    int pp=0;
    while(pcount[plist[i]]==val&&i<plist_len){
        if(pp>0){
            if(pp%6==0){
                fout<<"\n";
            } else {
                fout<<" ";
            }
        }
        printPattern(plist[i]);
        i++;
        pp++;
    }
    return i;
}
int readStr(){
    int len=0;
    char buff[100];
    buff[0]='0';
    do{
        buff[0]='\0';
        fin>>buff;
        //copy buff
        for(int i=0;buff[i]!='\0';i++){
            inpstr[len]=buff[i];
            len++;
        }
        inpstr[len]='\0';
    }while(buff[0]!='\0');
    return len;
}
int main(){
   /* ofstream fout((const char*)"contact.out");
    ifstream fin((const char*)"contact.in");*/
	fin>>A>>B>>N;
    int maxlen=readStr();
    
	for(int len=A;len<=B;len++){
        if(len<=maxlen){
            unsigned mhash = rollingHash(len);
            countPattern(mhash,len);
            for(int pos=len;pos<maxlen;pos++){
                mhash = roll(mhash,pos,len);
                countPattern(mhash,len);
                if(mhash==4){
                //    printf("char= %c ,pos= %d,count= %d\n",inpstr[pos],pos,pcount[mhash]);
                }
            }
        }
	}
    for(unsigned int i=0;i<60000;i++){
        if(pcount[i]>0){
            plist[plist_len++]=i;
        }
    }
    sort(plist,plist+plist_len,mycomp);
    int printed=0;
    for(int i=0;i<plist_len&&printed<N;){
        //printPattern(plist[i]);
        //printf("    %d\n",pcount[plist[i]]);
        i = printFreq(i,pcount[plist[i]]);
        fout<<"\n";
        printed++;
    }
}
