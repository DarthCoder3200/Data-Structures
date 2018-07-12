#include<iostream>
#include<deque>
using namespace std;

int main(){
    int n;
    int a[100000];
    int k;
    cin>>n;
    int i;
    for( i =0 ;i < n;i++){
        cin>>a[i];
    }
    cin>>k;
    deque<int> Q(k);
    for(i =0;i < k;i++){
        while(Q.empty() && a[i]>a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }

    for(;i<n;i++){
        cout<<a[Q.front()]<<" ";
        while(!Q.empty() && (Q.front()<=(i-k))){
            Q.pop_front();
        }
        while(!Q.empty() && a[Q.back()]<a[i]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    cout<<a[Q.front()]<<endl;

return 0;
}
