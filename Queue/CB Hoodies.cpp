#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void work_on_char(char ch,stack<int> &Q){
    stack<int> q2;
    if(ch == 'E'){
    int a;
    cin>>a;
    while(!Q.empty()||Q.top() == a){
        q2.push(Q.top());
        Q.pop();
    }
    if(!Q.empty()){
        Q.push(a);
        while(!q2.empty()){
        Q.push(q2.top());
        q2.pop();
    }
    }
    else{
        while(!q2.empty()){
        Q.push(q2.top());
        q2.pop();
    }
    Q.push(a);
    }
}
    if(ch =='D'){
            while(!Q.empty()){
                q2.push(Q.top());
            }
        cout<<q2.top()<<" ";
        q2.pop();
        while(!q2.empty()){
                Q.push(q2.top());
            }

    }
}

int main(){
    int p[100] = {0};
    int k = 0;
    stack<int> Q;
    char ch;
    for (int i =0 ;i<5;i++){
    cin>>ch;
    work_on_char(ch,Q);
    }
	return 0;
}
