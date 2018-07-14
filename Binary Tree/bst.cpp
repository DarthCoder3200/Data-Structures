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
node*insertAtBST(node*&root,int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(root->data < data){
        root->right = insertAtBST(root->right,data);
    }
    if(data < root->data){
        root->left = insertAtBST(root->left,data);
    }
    return root;
}

void takeInput(node*&root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertAtBST(root, data);
        cin>>data;
    }
}

int main(){
    node*root = NULL;
    takeInput(root);
    levelOrderPrint(root);
return 0;
}
