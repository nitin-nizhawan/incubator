#include<stdio.h>


class Node {
    public:
    long long priority;
    int recipe;
    Node *hash[27];
    Node(){
        priority = -1*1000*1000*1000 - 1000;
        recipe=-1;
        for(int i=0;i<27;i++){
            hash[i]=NULL;
        }
    }
}root;
char recipes[1005][1005];
int prio[1005];
int iVal(char ch){
    if(ch=='-'){
        return 26;
    } else {
        return ch-'a';
    }
}
void addToTrie(char *buff,int r){
    int p=0;
    Node *curNode = &root;
    while(buff[p]!='\0'){
        int ch  = iVal(buff[p]);
        if(curNode->hash[ch]!=NULL){
            if(prio[curNode->hash[ch]->recipe]<prio[r]){
                curNode->hash[ch]->recipe=r;
            }
        } else {
            curNode->hash[ch] = new Node();
            curNode->hash[ch]->priority=prio[r];
            curNode->hash[ch]->recipe=r;
            
        }
        curNode = curNode->hash[ch];
        p++;
    }
}
int query(char *buff){
    int p=0;
    int ret=-1;
    Node * curNode = &root;
    while(buff[p]!='\0'){
        int ch=iVal(buff[p]);
        if(curNode->hash[ch]!=NULL){
            ret=curNode->hash[ch]->recipe;
        } else {
            ret = -1;
            break;
        }
        curNode = curNode->hash[ch];
        p++;
    }
    return ret;
}
int main(){
    int N,Q;
    char tmp[1005];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",recipes[i]);
        scanf("%d",&prio[i]);
        addToTrie(recipes[i],i);
    }
    scanf("%d",&Q);
    for(int i=0;i<Q;i++){
        scanf("%s",tmp);
        int r = query(tmp);
        printf("%s\n",(r>=0)?recipes[r]:"NO");
    }
}
