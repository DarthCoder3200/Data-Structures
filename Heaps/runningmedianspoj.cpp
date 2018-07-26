#include<iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

int main(){

priority_queue<int , vector<int>, greater<int> > right_min_heap;
priority_queue<int> left_max_heap;
int k,d,m;
int rightSize =0 , leftSize = 0;
cin>>k;
while(k!=-1){
    pmin.push(k);
    leftSize++;
    if(leftSize - rightSize == 0 || leftSize - rightSize ==1){
        cout<<pmin.top()<<endl;
        pmin.pop();
        leftSize = pmin.size();
    }
    else if(rightSize - leftSize == 1){
        cout<<pmax.top()<<endl;
        pmax.pop();
        rightSize = pmax.size();
    }
    else if(leftSize - rightSize > 1){
        while(leftSize - rightSize > 1){
        d = pmin.top();
        pmin.pop();
        pmax.push(d);
        rightSize++;
        leftSize--;
        }
        cout<<pmin.top()<<endl;
        pmin.pop();
        leftSize--;
    }
    else{
        while(rightSize - leftSize > 1){
        d = pmax.top();
        pmax.pop();
        pmin.push(d);
        rightSize--;
        leftSize++;
        }
        cout<<pmax.top()<<endl;
        pmax.pop();
        rightSize--;
    }
    cin>>k;
}
return 0;
}
