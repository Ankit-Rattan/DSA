#include<iostream>
using namespace std;
class MyCircularQueue {
    int* arr;
    int front;
    int rear;
    int size;
public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size))) {
            return false;
        }

        else if(front == -1){
            front = rear = 0;
        }
        else if(rear == size-1 && front!=0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(front  == -1) return false;

        arr[front] = -1;
        if(front == rear){
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front ++;
        }
        return true;
    }
    
    int Front() {
        if(front == -1) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(rear == -1) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1) return true;
        return false;
    }
    
    bool isFull() {
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size))){
            return true;
        }
        return false;
    }
};
int main()
{
    MyCircularQueue q(5);
    q.enQueue(5);
    // cout<<q.Front()<<endl;
    // cout<<q.Rear()<<endl;
    q.enQueue(4);
    cout<<q.Front()<<endl;
    cout<<q.Rear()<<endl;
    
    return 0;
}