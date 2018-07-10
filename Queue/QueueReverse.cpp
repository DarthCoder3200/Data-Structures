#include<iostream>
#include "Queue.h"
using namespace std;

void queuerev(Queue &q){
    if(q.size()==0){
        return;
    }
    int firstElement = q.front();
    q.pop();
    queuerev(q);
    q.push(firstElement);

}
int main(){
    Queue q;
for(int i = 1;i<6;i++){
    q.push(i);
}
queuerev(q);
while(!q.isEmpty()){
    cout<<q.front()<<endl;
    q.pop();

}
return 0;
}
