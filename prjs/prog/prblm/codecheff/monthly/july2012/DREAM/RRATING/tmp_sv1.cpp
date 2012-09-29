#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
class Node {
    public:
        int key;
        Node* p;
        Node* l;
        Node* r;
        Node(){
            p=r=l=NULL;
        }
};
Node *rightrotation(Node *p,Node *rt);
Node * leftrotation(Node *p,Node *rt);
Node nodes[250009];
int pos=0;
Node* root;
Node* current=NULL;
int total=0;
Node* newNode(){
    return &nodes[pos++];
}
void printLevelOrder(Node *rt) {
  if (!rt) return;
  queue<Node*> currentLevel, nextLevel;
  currentLevel.push(rt);
  while (!currentLevel.empty()) {
    Node *currNode = currentLevel.front();
    currentLevel.pop();
    if (currNode) {
      cout << currNode->key << " ";
      nextLevel.push(currNode->l);
      nextLevel.push(currNode->r);
    }
    if (currentLevel.empty()) {
      cout << endl;
      swap(currentLevel, nextLevel);
    }
  }
}
void splay (Node *x, Node *rt)
{
        Node *p,*g;
        /*check if node x is the root node*/
        //if(x==rt)
        if(x==NULL||x->p==NULL)
                return;
        /*Performs Zig step*/
        else if(x->p->p==NULL)
        {
                if(x==x->p->l)
                        rt=rightrotation(rt,rt);
                else
                        rt=leftrotation(rt,rt);
        }
        else
        {
                p=x->p; /*now points to parent of x*/
                g=p->p; /*now points to parent of x's parent*/
                /*Performs the Zig-zig step when x is left and x's parent is left*/
                if(x==p->l&&p==g->l)
                {
                        rt=rightrotation(g,rt);
                        rt=rightrotation(p,rt);
                }
                /*Performs the Zig-zig step when x is right and x's parent is right*/
                else if(x==p->r&&p==g->r)
                {
                        rt=leftrotation(g,rt);
                        rt=leftrotation(p,rt);
                }
                /*Performs the Zig-zag step when x's is right and x's parent is left*/
                else if(x==p->r&&p==g->l)
                {
                        rt=leftrotation(p,rt);
                        rt=rightrotation(g,rt);
                }
                /*Performs the Zig-zag step when x's is left and x's parent is right*/
                else if(x==p->l&&p==g->r)
                {
                        rt=rightrotation(p,rt);
                        rt=leftrotation(g,rt);
                }
                splay(x, rt);
        }
}
Node *rightrotation(Node *p,Node *rt)
{
        Node *x;
        x = p->l;
        p->l = x->r;
        if (x->r!=NULL) x->r->p = p;
        x->r = p;
        if (p->p!=NULL)
                if(p==p->p->r) p->p->r=x;
                else
                         p->p->l=x;
        x->p = p->p;
        p->p = x;
        if (p==rt)
                return x;
        else 
                return rt;
}
Node *leftrotation(Node *p,Node *rt)
{
        Node *x;
        x = p->r;
        p->r = x->l;
        if (x->l!=NULL) x->l->p = p;
        x->l = p;
        if (p->p!=NULL)
                if (p==p->p->l) p->p->l=x;
                else
                         p->p->r=x;
        x->p = p->p;
        p->p = x;
        if(p==rt) 
                return x;
        else
                return rt;
}
void addNode(Node* node, int k){
    if(k>(node->key)){
        if(node->l==NULL){
            node->l=newNode();
            node->l->key=k;
            node->l->p = node;
            splay(node->l,root);
            root = node->l;
            //printLevelOrder(root);
        } else {
            addNode(node->l,k);
        }
    } else {
        if(node->r==NULL){
            node->r=newNode();
            node->r->key = k;
            node->r->p=node;
            splay(node->r,root);
            root = node->r;
            //printLevelOrder(root);
        }else {
            addNode(node->r,k);
        }
    }
}
Node* pred(Node* node){
    if(node->l != NULL){
        node = node->l;
        while(node->r!=NULL){
            node = node->r;
        }
        return node;
    } 
    // ancestor of node without right subtree
    Node* ancestor = node->p;
    while(ancestor != NULL && ancestor->l == node)
    {
        node = ancestor;
        ancestor = ancestor->p;
    }
    return ancestor;
}
Node* succ(Node* node){
    if(node->r != NULL) {
        node = node->r;
        while(node->l!=NULL){
            node = node->l;
        } 
        return node;
    }

    // ancestor of node without right subtree
    Node* ancestor = node->p;
    while(ancestor != NULL && ancestor->r == node)
    {
        node = ancestor;
        ancestor = ancestor->p;
    }
    return ancestor;
}
void updateCurrent(int k){
    if(total<3){
        return;
    } else  if(total==3){
        Node* tmp  = root;
        while(tmp!=NULL){
            current = tmp;
            tmp = tmp->l;
        }
    } else {
        if(k>(current->key)){
            if(total%3){
                current = pred(current);
                splay(current,root);
                root = current;
            }
        } else {
            if(total%3==0){
                current = succ(current);
                splay(current,root);
                root=current;
            }
        }
    }
}
void add(int k){
    if(root==NULL){
        root = newNode();
        root->key = k;
    } else {
        addNode(root,k);
        printf("added new node\n");
        printLevelOrder(root);
    }
    total++;
    updateCurrent(k);
    printf("updated current \n");
    printLevelOrder(root);
}
int query(){
    if(current==NULL){
        return -1;
    }
    return current->key;
}
int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int a,b;
        scanf("%d",&a);
        if(a==1){
            scanf("%d",&b);
            add(b);
        } else {
            b = query();
            if(b<0){
                printf("No reviews yet\n");
            } else {
                printf("%d\n",b);
            }
        }
    }
}
