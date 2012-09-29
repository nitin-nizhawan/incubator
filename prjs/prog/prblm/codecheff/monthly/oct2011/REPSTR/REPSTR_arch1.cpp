#include<stdio.h>
#define MAXMEM  9999999
long L,H;
char buff[100009];
class Node {
    public:
        Node *ht[26];
        int count;
        Node(){
        }
        void reset(){
            count =0;
            for(int i=0;i<26;i++){
                ht[i]=NULL;
            }

        }
};
const int maxNode=MAXMEM;
Node nodes[MAXMEM];
int memc=0;
Node* newNode(){
    if(memc<maxNode){
        Node *a;
        a = &nodes[memc++];
        a->reset();
        return a;
    } else {
        int a =1;
        int b ;
        b = 1/(a-1);  // create divide by zero error
        return 0;
    }

}
int main(){
    fgets(buff,10000,stdin);
    L=H=0;
    int i=0;
    while(buff[i]<='9'&&buff[i]>='0'){
        L = L*10+(buff[i]-'0');
        i++;
    }
    i++;
    while(buff[i]<='9'&&buff[i]>='0'){
        H = H*10+(buff[i]-'0');
        i++;
    }
    while(L>0&&H>0){
        fgets(buff,100005,stdin);        
        //printf("%s\n",buff);
        int len=0;
        while(buff[len]>='a'&&buff[len]<='z'){
            //printf("Debug:: %c,%di\n",buff[len],buff[len]);
            buff[len] = buff[len]-'a';
            len++;
        }
        memc=0;// reuse memory   
        Node *root = newNode();
        Node *curNode; 
        int max=0;
        int mlen=0;
        for(int i=0;i<(len-L+1);i++){
            curNode = root;
            for(int j=i;j<len&&j<(i+H);j++){
                if(curNode->ht[buff[j]]!=NULL){
                } else {
                    curNode->ht[buff[j]] = newNode();
                }
                curNode = curNode->ht[buff[j]];
                curNode->count++; 
                if((j-i)>=(L-1)&&(j-i)<=H){
                    if(curNode->count>max){
                        max = curNode->count;
                        mlen = j-i+1;
                    } else if(curNode->count==max){
                        if((j-i+1)>mlen){
                            mlen = j-i+1;
                        }
                    }
                }
            }
        }
        printf("%d %d\n",max,mlen);

        fgets(buff,10000,stdin);
        L=H=0;
        int i=0;
        while(buff[i]<='9'&&buff[i]>='0'){
            L = L*10+(buff[i]-'0');
            i++;
        }
        i++;
        while(buff[i]<='9'&&buff[i]>='0'){
            H = H*10+(buff[i]-'0');
            i++;
        }
    }
}
