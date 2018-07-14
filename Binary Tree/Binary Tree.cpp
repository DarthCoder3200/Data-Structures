#include<iostream>
#include<queue>
using namespace std;

class node{
public:

int data;
node*right;
node*left;
node(int d){
data = d;
right = NULL;
left = NULL;
}
};
int max(int a, int b){
if(a>=b){
    return a;
}
else{
    return b;
}
}

node*buildTree(){
int d;
cin>>d;
if(d==-1){
    return NULL;
}
node*n = new node(d);
n->left  = buildTree();
n->right = buildTree();
return n;
}
void printPreOrder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
void printLevel(node*root, int k){
    if(root == NULL || k<0){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
        return;
    }
    printLevel(root->left,k-1);
    printLevel(root->right,k-1);
}
int countnodes(node*root){
    if(root == NULL){
        return 0;
    }
    return 1 + countnodes(root->left) + countnodes(root->right);
}
int height(node*root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left),height(root->right));
}
void levelOrderPrint(node*root){

    for(int i = 0 ;i<height(root);i++){
        printLevel(root,i);
        cout<<endl;
    }
    return;
}
void inOrderPrint(node*root){
    if(root == NULL){
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
    return;
}

void postOrderPrint(node*root){
    if(root == NULL){
        return;
    }
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout<<root->data<<" ";
    return;
}

int diameter (node*root){
    if(root == NULL){
        return 0;
    }
    int op1 = height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1,max(op2,op3));
}

void levelOrderInput(node*&root){
    cout<<"Enter the root node";
    int d;
    cin>>d;
    root = new node(d);

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node*parent = q.front();
        q.pop();
        cout<<"Enter the children of "<<parent->data;
        int c1;
        int c2;
        cin>>c1;
        cin>>c2;
        if(c1 != -1){
            parent->left = new node(c1);
            q.push(parent->left);
        }
        if(c2 != -1){
            parent->right = new node(c2);
            q.push(parent->right);
        }
    }
}

class myPair{
public:
        int height;
        int diameter;
};

myPair diameterFast(node*root){
    myPair p;
    if(root = NULL){
        p.height = 0;
        p.diameter = 0;
        return p;
    }
    myPair left = diameterFast(root -> left);
    myPair right = diameterFast(root -> right);
    int d1 = left.diameter;
    int d2 = right.diameter;
    int h1 = left.height;
    int h2 = right.height;

    p.diameter = max(h1 + h2,max(d1,d2));
    p.height = 1 + max(h1,h2);

}
class sumPair{
public:
    int exc;
    int inc;
};
sumPair maxSumProblem(node*root){
    sumPair p;
    if(root == NULL){
        p.exc = 0;
        p.inc = 0;
        return p;
    }
    sumPair left = maxSumProblem(root->left);
    sumPair right = maxSumProblem(root->right);

    p.inc = root->data + left.exc + right.exc;
    p.exc = max(left.inc,left.exc) + (right.inc,right.exc);

    return p;
}

int main(){
    node*root = NULL;
    /*printPreOrder(root);
    cout<<endl;
    printLevel(root,2);
    cout<<endl;
    cout<<countnodes(root);
    cout<<endl;
    cout<<height(root);
    cout<<endl;*/
    levelOrderInput(root);
    cout<<endl;
    sumPair p = maxSumProblem(root);
    cout<<"Max Sum is "<<max(p.inc,p.exc);
    return 0;
}
