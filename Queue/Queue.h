
class Queue{
    int *arr;
    int f;
    int r;
    int cs; ///Current Size
    int ms; ///Max Size of queue
public:
    Queue(int ds=5){
        ms = ds;
        cs = 0;
        arr = new int[ms];
        f = 0;
        r = ms - 1;
    }
    void push(int data){
        if(!isFull()){
            r = (r+1)%ms;
            arr[r] = data;
            cs++;
        }

    }
    void pop(){
        if(!isEmpty()){
            f = (f+1)%ms;
            cs--;
        }

    }

    int front(){
        if(!isEmpty()){
            return arr[f];
        }
    }
    bool isEmpty(){
        return cs==0;
    }
    bool isFull(){
        return cs==ms;
    }


};
