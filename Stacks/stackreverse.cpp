#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s,int p){
stack<int> s2;
    int k;
    while(!s.empty()){
        k = s.top();
        s2.push(k);
        s.pop();
    }
    s.push(p);
    while(!s2.empty()){
        k = s2.top();
        s.push(k);
        s2.pop();
    }
}

void rev(stack<int> &s){
    if(s.size()==0){
        return;
    }
    int topElement = s.top();
    s.pop();
    rev(s);
    insertAtBottom(s,topElement);


}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    rev(s);
    for(int i = 0;i<3;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
return 0;
}
