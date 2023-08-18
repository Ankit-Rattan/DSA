#include<iostream>
using namespace std;
class MyQueue {
        int* arr;
        int size;
        int front;
        int rear;

public:
    MyQueue() {
        size = 10001;
        arr = new int[size];
        front =0;
        rear = 0;

    }
    
    void push(int x) {
        if(rear == size) return;
        arr[rear] = x;
        rear++;
    }
    
    int pop() {
        if(front  == rear) return -1;
        int temp = arr[front];
        arr[front] = -1;
        front++;
        if(front == rear){
            front = 0; rear=0;
        }
        return temp;
        
    }
    
    int peek() {
        if(front == rear) return -1;
        return arr[front];
    }
    
    bool empty() {
        if(front  == rear) return true;
        return false;
    }
};

int main()
{
    MyQueue q;
    q.push(1);
    cout<<q.peek()<<endl    ;
    
    return 0;
}