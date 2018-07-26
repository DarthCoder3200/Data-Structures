#include<cstring>
using namespace std;
template<typename T>
class node{
public:
    string key;
    T value;
    node<T>* next;
     node(T v,string key){
    this->key = key;
    value = v;
    }
    ~node(){
    if(next!=NULL){
        delete next;
    }
    }

};
template<typename T>
class Hashtable{
int cs;
int ts;
node<T> ** buckets;

void rehash(){

    node<T>** oldBuckets = Buckets;
    int oldTs = ts;
    ts = ts*2;
    cs =0;
    buckets = new node<T>[ts];
    for(int i = 0;i<ts;i++){
        buckets[i] = NULL;
    }
    for(int k = 0;k<oldts;k++){
        node<T>*temp;
        while(temp!=NULL){
            insert(temp->key,temp->value);
            temp = temp->next;
        }
        delete oldBuckets[i];
    }
}

int hashFn(string key){
int L = key.length();
int ans =0;
int p = 1;
for(int i=0;i<L;i++){
    ans+= key[L-i-1] * p;
    p = p*37;
    p = p%ts;
    ans = ans%ts;
    }
    return ans;
}
public:
    Hashtable(int ds = 7){
        cs = 0;
        ts = ds;
        buckets = new node<T>*[ts];
        for(int i = 0;i<ts;i++){
            buckets[i] = NULL;
        }
    }
    void insert(string key,T value){
    int i = hashFn(key);
    node<T>* n = new node<T>(value,key);
    n->next = buckets[i];
    buckets[i] = n;
    cs++;
    float loadFactor = (float)cs/ts;
    if(loadFactor > .7){
        cout<<"The load factor is"<<loadFactor<<endl;

        rehash();
    }
    }
    void print(){
        for(int i =0;i<ts;i++){
        node<T>* temp = buckets[i];
        while(temp!=NULL){
        cout<<temp->key<<" ";
        temp = temp->next;
        }
        cout<<endl;
    }
    }
    T* search(string key){
    int k = hashFn(key);
    node<T>*temp = buckets[k];
    while(temp != NULL){
            if(temp->key == key){
                return &(temp->value);
            }
        temp = temp->next;
    }
    return NULL;
    }

};
