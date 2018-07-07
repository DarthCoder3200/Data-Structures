#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;

    node(int p){
    data = p;
    next = NULL;
    }

};

  void insertAtHead(node*&head,int data){
    node *n = new node(data);
    n->next = head;
    head =n;
    }

void print(node*head){

while(head != NULL){
        cout<<head->data<<"=>";
        head = head->next;
        }

    }


void insertAtTail(node*&head,int data){
node * temp = head;
while(temp->next != NULL){
    temp = temp->next;
}
node *n = new node(data);
temp->next =n;
}

void insertAtmiddle(node*&head,int data,int pos){
    if(pos == 0){
        insertAtHead(head,data);
    }
    node* n = new node(data);
    node*temp = head;
    for(int i=1;i<pos;i++){
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}


int main(){
    node*head;
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtmiddle(head,7,2);
    print(head);
return 0;
}
