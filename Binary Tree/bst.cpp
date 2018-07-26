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
ostream& operator<<(ostream&os,node*root){
levelOrderPrint(root);
return os;
}
istream& operator>>(istream&is,node*&root){
takeInput(root);
return is;
}
bool search(node*root,int key){
if(root == NULL){
        return false;
}
if(key == root->data){
    return true;
}
if(key<root->data){
    return search(root->left,key);
}
if(key>root->data){
   return search(root->right,key);
}
}
int catalan_no(int n){
    int c;
    c = 1;

    int d = 2*n;
    for(int i=1; i<=n;i++){
        c = c*d;
        c = c/i;
        d--;
    }
    c = c/(n+1);

    return c;
}

node* minnode(node*root){
    while(root->left !=NULL){
        root = root->left;
    }
    return root;
}
node* maxnode(node*root){
    while(root ->right != NULL){
        root = root->right;
    }
    return root;
}

node* deleteinBST(node*&root,int key){
    if(root ==NULL){
        return NULL;
    }
    if(root->data == key ){
        if(root->left ==NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left == NULL && root->right != NULL){
            node*temp = root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right == NULL){
            node*temp = root->left;
            delete root;
            return temp;
        }
    if(root->right!=NULL){
    node*replacement = minnode(root->right);
    root->data = replacement->data;
    root->right = deleteinBST(root->right,root->data);
    return root;
    }
    else{
    node*replacement = maxnode(root->left);
    root->data = replacement->data;
    root->left = deleteinBST(root->left,root->data);
    return root;
    }
    }
    if(root->data < key){
       root ->right =deleteinBST(root->right,key);
       return root;
    }

    else if(root->data > key){
        root->left = deleteinBST(root->left,key);
        return root;
    }
}
node*arrtoBST(int*a,int s,int e){
if(s>e){
    return NULL;
}
int m =(s+e)/2;
node*root  = new node(a[m]);
root->left = arrtoBST(a,s,m-1);
root->right = arrtoBST(a,m+1,e);

return root;
}

bool isBST(node*root,int minV = INT_MIN,int maxV = INT_MAX){
    if(root == NULL){
    return true;
    }
    if(root->data>=minV &&root->data <=maxV&& isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
        return true;
    }
    return false;
}
class LinkedList{
public:
    node*head;
    node*tail;
};

LinkedList TreetoLL(node*&root){
    LinkedList l;
    if(root == NULL){
        l.head = l.tail = NULL;
        return l;
    }
    else if(root->left == NULL && root->right == NULL){
        l.head = root;
        l.tail = root;
    }
    else if(root->left == NULL && root->right != NULL){
        LinkedList rightLL = TreetoLL(root->right);
        root ->right =rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
    }
    else if(root->left !=NULL && root->right == NULL){
        LinkedList leftLL = TreetoLL(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
    }
    else{
        LinkedList LeftLL = TreetoLL(root->left);
        LeftLL.tail->right = root;
        LinkedList rightLL = TreetoLL(root->right);
        root->right =rightLL.head;
        l.head = LeftLL.head;
        l.tail = rightLL.tail;
    }
    return l;
}

int main(){
    /*node*root = NULL;
    cin>>root;
    cout<<root;
    if(search(root,68)){
        cout<<"fuck key is here";
    }
    else{
        cout<<"shit we don't get it";
    }
    deleteinBST(root,6);
    cout<<endl;
    cout<<root;*/
    int a[100] = {1,2,4,5,6,8,9};
    node*root = arrtoBST(a,0,6);
    cout<< root << endl;
    LinkedList L = TreetoLL(root);
    node*temp = L.head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->right;
    }
return 0;
}
