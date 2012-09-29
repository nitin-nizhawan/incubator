/*
ID: nitin.n1
PROG: shopping
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream fout ("shopping.out");
ifstream fin ("shopping.in");
int s;
int offers[100][5];
int offercost[100];
int revMap[1000];
int fwdMap[5];
int itemCnt=0;
int b;
int itemCost[5];
int numItem[5];
int mat[6][6][6][6][6];
int iVal(int a){
    if(revMap[a]==0){
        revMap[a]=itemCnt+1;
        fwdMap[itemCnt++]=a;
    }
    return revMap[a]-1;
}
int depth=0;
void indent(){
   for(int i=0;i<depth;i++){
      //printf(" ");
   }
}
int min_price(int a, int b,int c, int d,int e){
    depth++;
    if(a==0&&b==0&&c==0&&d==0&&e==0){
           mat[a][b][c][d][e]=0;
           depth--;return 0;
    }
    if(mat[a][b][c][d][e]==0){
	int min_p = a*itemCost[0]+b*itemCost[1]+c*itemCost[2]+d*itemCost[3]+e*itemCost[4];
        indent();
        //printf("max_possible at %d,%d = %d \n",a,b,min_p);
	for(int i=0;i<s;i++){ // for each offer
	    int last_step_cost=0;
	    int* offer = offers[i];
	    if(a>=offer[0]&&b>=offer[1]&&c>=offer[2]&&d>=offer[3]&&e>=offer[4]){
		last_step_cost=min_price(a-offer[0],b-offer[1],c-offer[2],d-offer[3],e-offer[4]);
		indent();
		//printf("last step cost at %d,%d for offer %d,%d = %d, offercost=%d\n",a,b,offer[0],offer[1],last_step_cost,offercost[i]);
		indent();
		//printf("comparision min_p %d vs calc_cost %d\n",min_p,last_step_cost+offercost[i]);
		if(min_p>(last_step_cost+offercost[i])){
			min_p = last_step_cost+offercost[i];
		}

	    }
	}
	mat[a][b][c][d][e]=min_p;
    }
    depth--;
    return mat[a][b][c][d][e];
}
void solve(){
    // init 
    int init[5];
    for(int i=0;i<5;i++){
        if(i<itemCnt){
          init[i]=numItem[i];
        } else {
          init[i]=0;
        }
    }
    int p= min_price(init[0],init[1],init[2],init[3],init[4]);
    for(int i=0;i<5;i++){
       for(int j=0;j<5;j++){
            //printf("%d ",mat[i][j][0][0][0]);
       }
       //printf("\n");
    }
    fout<<p<<"\n";
}
int main() {
        fin>>s;
        for(int i=0;i<s;i++){
            int tn;
            fin>>tn;
            for(int j=0;j<tn;j++){
                int ic;
                fin>>ic;
                ic=iVal(ic);
                int icst;
                fin>>icst;
                offers[i][ic]=icst;
            }
            fin>>offercost[i];
        }  
        fin>>b;
        for(int i=0;i<b;i++){
           int ic;
           fin>>ic;
           ic = iVal(ic);
           fin>>numItem[ic];
           fin>>itemCost[ic]; 
        }  
        solve();
	return 0;
}

