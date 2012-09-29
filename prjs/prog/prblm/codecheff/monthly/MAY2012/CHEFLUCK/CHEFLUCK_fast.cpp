#include<stdio.h>
//Fast IO Section
#define MAX_BUFFER (512*1024)

class FastIO{
private:
    static char inBuffer[MAX_BUFFER];
    static char outBuffer[MAX_BUFFER];
    static int inBuffFilled,inBuffCurrent;
    static int outBuffFilled;
    static inline void fillInBuffer()
    {
        inBuffFilled = fread(inBuffer,1,MAX_BUFFER,stdin);
        inBuffCurrent = 0;
    }
    static inline char getNextChar()
    {
        if(inBuffCurrent>=inBuffFilled){fillInBuffer();}
        return inBuffer[inBuffCurrent++];
    }
    static inline void skipSpaces(){while(inBuffer[inBuffCurrent] == ' ' || inBuffer[inBuffCurrent] == '\n')inBuffCurrent++;}
public: 
        

    static unsigned long inReadNum()
    {
        long num = 0;
        skipSpaces();
        char ch;
        while(1){
            ch = getNextChar();
            if(ch >= '0' && ch <= '9')
            {
                num = (num*10)+(ch-'0');
            }else{
                return num;
            }
        }
    }

    static inline void flushOutBuffer()
    {
        fwrite(outBuffer,1,outBuffFilled,stdout);
        outBuffFilled = 0;
    }
private:    
    static inline void outBufferCheck(){if(outBuffFilled >= (MAX_BUFFER-11))flushOutBuffer();}
    static unsigned long recursiveOutNum(unsigned long num)
    {
        if(num && num < 10){outBuffer[outBuffFilled++] = '0' + num;}
        else
        {
            recursiveOutNum(num/10);
            outBuffer[outBuffFilled++] = '0' + (num%10);
        }
    }
public: 
    static inline void outWriteSpace(){outBufferCheck();outBuffer[outBuffFilled++] = ' ';}
    static inline void outWriteNewLine(){outBufferCheck();outBuffer[outBuffFilled++] = '\n';}
    static inline void outWriteNum(unsigned long num)
    {
        outBufferCheck();
        if(num) recursiveOutNum(num);
        else outBuffer[outBuffFilled++] = '0';
    }
};

int FastIO::inBuffFilled=0,FastIO::inBuffCurrent=0,FastIO::outBuffFilled=0;
char FastIO::inBuffer[MAX_BUFFER],FastIO::outBuffer[MAX_BUFFER];


/**
 * algorithm
 * Let N be of form 7*k + R, and let R%4 = S
 * then f(N) = f(7*k + R), since we know that f(N) = f(N-4) and
 *  that f(7*a) = 7*a
 * f(7*k + 4 ) = f(7*k + 4 - 4) = f(7*k) = 7k
 * f(7*k + 1 ) = f(7*k + 1 - 4) = f(7*k - 3) = f(7*(k-1) + 4) = 7*(k-1) =7k-7
 * f(7*k + 5) = f(7*k + 1) = 7*(k-1) = 7*k - 7
 * f(7*k +2 ) = f(7*k - 2 ) = f(7*(k-1) + 5) = 7*(k-2) = 7*k - 7*2
 * f(7*k + 6) = f(7*k + 2) = 7*(k-2) = 7*k - 7*2
 * f(7*k + 3) = f(7*k - 1 ) = f(7*(k-1) + 6) = 7*(k-3) = 7*k - 3*7
 * general formula is 7k - 7*(R%4) = 7k - 7*((N%7)%4) = (N-(N%7))-7*((N%7)%4)
 */
 char buff[200];
int readInt(){
    int ans=0;
    scanf("%s",buff);
    int i=0;
    while(buff[i]!='\0'&&buff[i]!='\n'&&buff[i]!='\r'){
        ans = ans*10 + (buff[i]-'0');
        i++;
    }
    return ans;
}
int main(){
    FastIO::fillInBuffer();
    int T=FastIO::inReadNum();
    
    long long N;
    while(T--){
        N=FastIO::inReadNum();
        long long ans = (N - (N%7)) - ((N%7)%4)*7;
        printf("%lld\n",(ans>=0)?ans:-1);
    }
}
