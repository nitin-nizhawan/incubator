/*
ID: nitin.n1
PROG: fracdec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int decimal[200000];
int toPrint=0;
int period_start=-1,period_len=-1;
int find_period_start(long long D){
    // if number of 2's in D is a, and number of 5's is b,
    // then length of non repeating digits is max(a,b),the reason being 
    //that you can eleminate 2,and 5' by multiplying by 
    //that many powers of ten;
    int twos=0, fives=0;
    long long D_cpy;
    while(D%2==0){
        twos++;
        D/=2;
        if(D==0){
            break;
        }
    }
   while(D%5==0){
       fives++;
       D/=5;
       if(D==0){
           break;
       }
   }
   return twos>fives?twos:fives;
}
long long gcd(long long a, long long b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
long long calc_phi(long long D){
   // euler's totient function phi(N) is the number of numbers less than N
   // that are coprim to N;
   long long ans=0;
   for(long long i=1;i<D;i++){
       if(gcd(D,i)==1){
           ans++;
       }
   }
   return ans;
}
bool ispattern(int len,int start){
    //printf("is pattern %d,%d",len,start);
    for(int i=0;i<len;i++){
        if(decimal[start+i]!=decimal[start+i+len]){
            return false;
        }
    }
    return true;
}
bool rigrous_test(int len,int start,long long phi){
    for(int i=1;(i+1)*len+start<(2*phi);i++){
        if(!ispattern(len,len*i+start)){
            return false;
        }
    }
    return true;
}
void solve(long long N,long long D){
    int pos=0;
    if(N==0){
        decimal[0]=0;
        toPrint=1;
        return;
    }
    N = N*10;
    period_start = find_period_start(D);
    while(pos<(2*(D+period_start))){
        if(N<D){
            N=N*10;
            decimal[pos++]=0;
        } else {
            long long q = N/D;
            while((q/10)>0){
                q/=10;
            }
            decimal[pos++]=q;
            N = N-q*D;
            if(N==0){
                toPrint=pos;
                return;
            }
            if(N<D){
                N=N*10;
            }
        }
    }
    long long phi =calc_phi(D); // period of fraction is a divisor of phi
    //printf("phi = %lld\n",phi);
//    for(int i=0;i<pos;i++) printf("%lld",decimal[i]); printf("\n");
    for(int i=1;i<=phi;i++){ // for each divisor of phi check if it is period
        if(phi%i==0){
            if(ispattern(i,period_start)&&rigrous_test(i,period_start,phi)){
                period_len = i;
                toPrint=period_start+period_len;
                return;
            }
        }
    }

    toPrint=pos;
}
int main() {
    ofstream fout ("fracdec.out");
    ifstream fin ("fracdec.in");
    long long N, D;
    fin >> N  >> D;
    long long integer = (N/D);
    solve(N-integer*D,D);
    int numchars=0;
    long long int_cpy = integer;
    while(int_cpy>0){
        numchars++;
        int_cpy/=10;
    }
    if(integer==0){
        numchars=1;
    }
    fout<<integer<<".";
    numchars++;

    for(int i=0;i<toPrint;i++){
        if(i==period_start){
            fout<<"("; numchars++;
        }
        if(numchars>=76){
            fout<<"\n";
            numchars=0;
        }
        fout<<decimal[i];
        numchars++;
        if(numchars>=76){
            fout<<"\n";
            numchars=0;
        }
    }
    if(period_len>-1){
        fout<<")";numchars++;
    }
        fout<<"\n";
    return 0;
}

