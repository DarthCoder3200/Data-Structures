#include<iostream>
#include "Stack.h"
using namespace std;
template<typename T>
void print(Stack<T> s){

     ///Print the elements without actually making the stack empty
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

// LIFO -Last in first out

int main(){
    ///Stack for all types of data - Generic


    Stack<char> s;
    for(int i=0;i<=5;i++){
        s.push(65+i);
    }
    ///Print the elements without actually making the stack empty
    print(s);
    cout<<endl;


    Stack<string> s2;
    s2.push("Hello");
    s2.push("Coding");
    s2.push("world!");

    print(s2);

return 0;
}

