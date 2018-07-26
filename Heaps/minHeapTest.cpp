#include<iostream>
#include "minHeap.h"

int main(){
    int a[] = {1,4,3,2,6,8,9,7,10};
    int n = sizeof(a)/sizeof(int);
    minHeap h;

    for(int i = 0;i<n;i++){
        h.push(a[i]);
    }
    while(!h.isempty()){
        cout<<h.getmin()<<" ";
        h.pop();
    }
    return 0;
}
