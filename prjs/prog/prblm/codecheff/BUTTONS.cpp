#include<cstdio>
#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull grid[1004][20];
ull gridsize;
int pattern;
int anti_pattern;
void setBit(int j,ull &num){
    ull val = 1<<j;
    num = num | val;
}
void clearBit(int j,ull &num){
    ull val = 1<<j;
    num = num & (~val);
}
int getBit(int j,ull num){
	ull mask= 1<<j;
	return ((num&mask)>0)?1:0;
}
void setGrid(int i,int j,int val){
    if(val>0){
        setBit(j%50,grid[i][j/50]);
    } else {
        clearBit(j%50,grid[i][j/50]);
    }
}
int getGrid(int i,int j){
	return getBit(j%50,grid[i][j/50]);
}
int isPatternOrAntiPattern(int i){
    int flag=1;
    for(int j=0;j<20;j++){
        if(grid[0][j]!=grid[i][j]){
            flag=0; break;
        }
    }
    if(flag>0){
        return 1;
    }
    flag =1;
    for(int j=0;j<20;j++){
        if(((grid[0][j])&(grid[i][j]))>0){
            flag=0; break;
        }
    }
    if(flag>0){
        return -1;
    }
    return 0; // none;
}
void countPatterns(){
    pattern=1;
    anti_pattern=0;
    for(int i=1;i<gridsize;i++){ // for each row
        int val=isPatternOrAntiPattern(i);
        if(val>0){
            pattern++;
        } else if(val<0){
            anti_pattern++;
        } else {
            pattern=-1; // no solution possible
            return;
        }
    }
}
int countBits(){
    ull bit_mask=1;
    int count=0;
  /*  for(int i=0;i<50;i++){
        if(grid[0][i]&bit_mask){
            count++;
        }
        bit_mask = bit_mask<<1;
    }*/
    for(int i=0;i<gridsize;i++){
	    if(getGrid(0,i)>0){
		    count++;
	    }
    }
    return count;
}
void printAntiPatternSol(){
    
}
void printPatternSol(){
}
void clearGrid(){
	for(int i=0;i<1004;i++){
		for(int j=0;j<20;j++){
			grid[i][j]=0;
		}
	}
}
void solveProb(){
    countPatterns();
    if(pattern<0){
        printf("%d\n",-1);
   clearGrid();
        return;
    }
    int bitsInPattern = countBits();
//    cout<<"bits in Pattern "<<bitsInPattern<<endl;
    int bitsInAntiPattern = gridsize-bitsInPattern;
  //  cout<<"bits in AntiPattern "<<bitsInAntiPattern<<endl;
  //  cout<<"patterns"<<pattern<<endl;
  //  cout<<"anti_pattern "<<anti_pattern<<endl;
    int patternRowButtons = anti_pattern;  // all antipaterns need to be toggled by row wize buttons
  //  cout<<"patternRowButtons "<<patternRowButtons<<endl;
    int antiPatternRowButtons = pattern;  // all patterns need to toggled
  //  cout<<"anti-patternRowButtons "<<antiPatternRowButtons<<endl;

    int patternButtonPress = bitsInPattern+patternRowButtons;
    int antiPatternButtonPress = bitsInAntiPattern + antiPatternRowButtons;
    if(patternButtonPress>antiPatternButtonPress){
        printf("%d\n",antiPatternRowButtons);
	for(int i=0;i<gridsize;i++){
		if(isPatternOrAntiPattern(i)==1){  // all the patterns need to be toggled
			printf("%d\n",i);
		}
	}
        printf("%d\n",bitsInAntiPattern);
        for(int i=0;i<gridsize;i++){ 
            if(getGrid(0,i)<1){
		    printf("%d\n",i);
	    }
        }
    } else {
        printf("%d\n",patternRowButtons);
	for(int i=0;i<gridsize;i++){
		if(isPatternOrAntiPattern(i)==-1){  // all the antipatterns need to be toggled
			printf("%d\n",i);
		}
	}
        printf("%d\n",bitsInPattern);
        for(int i=0;i<gridsize;i++){
            if(getGrid(0,i)>0){
		    printf("%d\n",i);
	    }
        }
    }
   clearGrid();
 
}

void inputProb(){
    scanf("%llu",&gridsize);
    ull n = gridsize;
     int inp;
//source grid
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&inp);
            setGrid(i,j,inp);
        }
    }
  /*  for(int i=0;i<n;i++){
	    for(int j=0;j<20;j++){
		    printf("%llu",grid[i][j]);
	    }
	    printf("\n");
    }*/
// traget grid
    ull row[20];
    
    for(int i=0;i<n;i++){
        for(int k=0;k<20;k++) row[k]=0; // clear row
        for(int j=0;j<n;j++){
            scanf("%d",&inp);
            if(inp>0){
                setBit(j%50,row[j/50]);
            } else {
                clearBit(j%50,row[j/50]);
            }
        }
        for(int k=0;k<20;k++) { grid[i][k]=grid[i][k]^row[k]; } // xor 
    }
  /*  for(int i=0;i<n;i++){
	    for(int j=0;j<20;j++){
		    printf("%llu",grid[i][j]);
	    }
	    printf("\n");
    }*/
}
int main(){
    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    long T;
    scanf("%ld",&T);
    while(T--){
        inputProb();
        solveProb();
    }    
}

