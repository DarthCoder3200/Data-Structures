
#include<bits/stdc++.h>
using namespace std;

class minHeap{
vector<int> v;
void heapify(int index){
    int leftChild = 2*index;
    int rightChild = 2*index + 1;

    int minIndex = index;
    if(leftChild < v.size() && v[leftChild] <v[index]){
        minIndex = leftChild;
    }
    if(rightChild<v.size() && v[rightChild]<v[minIndex]){
        minIndex = rightChild;
    }
    if(minIndex != index){
        swap(v[index] , v[ minIndex]);
        heapify(minIndex);
    }
}
public:
    minHeap(){
        v.push_back(-1);//blocking zeroth position
    }
    void push(int data){
        v.push_back(data);
        int index = v.size() - 1;
        int parent = index/2;
        while(index>1 && v[index]<v[parent]){
            swap(v[index],v[parent]);
            index = parent;
            parent = parent/2;
        }
    }
    int getmin(){
    return v[1];
    }
    void pop(){
    int last = v.size() - 1;
    swap(v[1],v[last]);
    v.pop_back();
    heapify(1);
    }
    bool isempty(){
    return v.size() == 1;
    }
};
