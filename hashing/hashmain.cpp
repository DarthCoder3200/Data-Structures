#include<iostream>
#include "hashtable.h"
using namespace std;

int main(){
Hashtable<int> H;
H.insert("Mango",100);
H.insert("Guava",130);
H.insert("gobi",200);
H.insert("aalu",250);
H.insert("bangan",260);
H.print();
cout<<endl;
int*price = H.search("gobi");
if(price == NULL){
    cout<<"fuck, not found";
}
else{
    cout<<"the price is"<<*price;
}

}
