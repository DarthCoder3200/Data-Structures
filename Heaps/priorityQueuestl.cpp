#include<iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

class Fruit{
public:
    string name;
    int price;
    Fruit(string n, int p){
        name = n;
        price =p;
    }
};

class myCompare{
public:
    bool operator()(Fruit a , Fruit b){
        if(a.price == b.price){
            return a.name < b.name;
        }

    return a.price > b.price;
    }

};

int main(){

Fruit f1("Mango" , 100);
Fruit f2("Banana" , 200);
Fruit f3("APPLE", 50);
Fruit f4("aalu", 100);

priority_queue<Fruit,vector<Fruit>,myCompare > pq;


    pq.push(f1);
    pq.push(f2);
    pq.push(f3);
    pq.push(f4);

while(!pq.empty()){

    cout<<pq.top().name<<" "<<pq.top().price<<endl;
    pq.pop();

}

return 0;
}
