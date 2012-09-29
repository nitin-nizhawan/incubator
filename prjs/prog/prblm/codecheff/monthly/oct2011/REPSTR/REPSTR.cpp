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
        for(int i=(len-L+1);i>=0;i--){
            curNode = root;
            if(curNode->ht[buff[i]]!=NULL){
                Node nNode = curNode->ht[buff[i]];
                nNode->count++;
                int k1=nNode->sPos,k2=i;
                while(k1<=nNode->ePos){
                    if(buff[k1]!=buff[k2]){
                        break;
                    }
                    k1++;k2++;
                }
            } else {
                Node nNode  = newNode();
                nNode->sPos = i;
                nNode->ePos = len-1;
                nNode->count = 1;
                curNode->ht[buff[i]] = nNode;
            }
        }
           
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
