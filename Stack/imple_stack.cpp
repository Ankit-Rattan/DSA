#include<iostream>
using namespace std;
// Implemeting stack using array:

class stack{
    public:

    // property (elements)
    int size;
    int *arr;
    int top;

    // Constructor
    stack(int size){
        this -> size = size;
        arr = new int[size];    
        top = -1;
    }

    //Operators

    void push(int ele){
        if(size-top >1){
            top++;
            arr[top] = ele;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Empty List"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;    
    }

    void print(){
        if(top>=0){
            int temp =0;
            cout<<"\nStack: "<<endl;
            while(temp<= top){
                cout<<arr[temp]<<" ";
                temp++;
            }
            cout<<endl;
        }
        else{
            cout<<"Stack is Empty"<<endl;
        }
    }

};


int main()
{
    stack s(5);

    s.push(1);
    s.push(2);
    s.push(4);

    s.print();

    s.pop();
    s.print();

    cout<<s.peek()<<endl;

    cout<<s.isEmpty()<<endl;

    s.print();

 

    
    return 0;
}