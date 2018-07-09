#include<iostream>
#include "Queue.h"

using namespace std;

int main(){
Queue q;
for(int i = 1;i<8;i++){
    q.push(i);
}
q.pop();
q.push(9);
while(!q.isEmpty()){
    cout<<q.front()<<endl;
    q.pop();

}
return 0;
}
