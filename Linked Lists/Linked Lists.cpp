#include<iostream>
using namespace std;

/// http://ideone.com/qW7Oqf

class node{
public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void addAtFront(node*&head,int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    node* n = new node(data);
    n->next = head;
    head = n;
    return;
}
int length(node*head){
    int l=0;
    for(node*temp = head;temp!=NULL;temp=temp->next){
        l++;
    }
    return l;
}

void insertAtPosition(node*&head,int data,int p){
    if(p==0){
        addAtFront(head,data);
        return;
    }
    else{
        ///Take p-1 jumps to reach the temp node
        node*temp = head;
        int cnt=1;
        while(cnt<=p-1){
            cnt++;
            temp = temp->next;
        }

        node* n = new node(data);
        n->next = temp->next;
        temp->next = n;
        return;
    }
}
void insertAtTail(node*&head,int data){
        insertAtPosition(head,data,length(head));
}
void deleteFront(node*&head){
    node*temp = head;
    head = head->next;
    delete temp;
}
void deleteInMiddle(node*&head,int p){
    ///HomeWork


}

///Recursion - Search Element
node* searchElement(node*head,int key){
    if(head==NULL){
        return NULL;
    }
    if(head->data == key){
        return head;
    }
    return searchElement(head->next,key);
}
node* searchIterative(node*head,int key){
    while(head!=NULL){
        if(head->data==key){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

/// Find out the midpoint of the Linked List

node* mid(node*head){
    node*slow = head;
    node*fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}



void takeInput(node*&head){
    int d;
    cin>>d;
    while(d!=-1){
        addAtFront(head,d);
        cin>>d;
    }
}
void print(node*head){

    while(head!=NULL){
        cout<<head->data<<"=>";
        head=head->next;
    }
    cout<<endl;
}

ostream& operator<<(ostream &os,node*head){
    print(head);
    return os;
}
istream& operator>>(istream &is,node*&head){
    takeInput(head);
    return is;
}
node* merge(node*a,node*b){
    ///Base Case
      if(a==NULL){
        return b;
      }
      if(b==NULL){
        return a;
      }

    ///Rec Case
    node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c = b;
        c->next = merge(a,b->next);
    }
    return c;
}
///Sort a Linked List
node* mergeSort(node *head){
    ///Base Case 0 or 1 node in LL
    if(head==NULL ||head->next==NULL){
        return head;
    }
    ///Rec Case 3 steps, divide, sort and merge
    node* m  = mid(head);
    node* a = head;
    node* b = m->next;
    m->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a,b);
}

void reverseIterative(node*&head){
    node* C = head;
    node* P = NULL;

    node*N;

    while(C!=NULL){
        ///Save the next node
        N = C->next;
        ///Make current node point to prev
        C->next = P;

        ///Update Prev and Current
        P = C;
        C = N;
    }
    head = P;
}

node* recReverse(node*head){
    ///Base Case 1 node
    if(head==NULL||head->next==NULL){
        return head;
    }
    ///Rec Case
    node* chotaHead = recReverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}

node* getLast(node*head){

    while(head->next!=NULL){
        head = head->next;
    }
    return head;
}




int main(){

    ///Create a LL of nodes
    node* head = NULL;
    node* head2 = NULL;

    cin>>head;
    cout<<head;
    cout<<endl;
    cout<<length(head);

    /*head = mergeSort(head);
    cout<<head;
   // reverseIterative(head);
    head =recReverse(head);
    cout<<head;
    */

   /*
    cout<<"Length is "<<length(head)<<endl;
    int d,p;
    cout<<"Enter data and pos ";
    cin>>d>>p;
    insertAtPosition(head,d,p);
    cout<<head;
    insertAtTail(head,27);
    cout<<head;

    cout<<"Mid point is"<<mid(head)->data<<endl;
    */



return 0;
}
