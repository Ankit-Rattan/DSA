#include<iostream>
using namespace std;

// Implementation of stack using LL

class  Node{
    public:

        int data;
        int size = 5; 
        int track;
        Node* next;
        Node* head;
        Node* tail;
        Node(int  data){
            this -> track = 0;
            this -> data = data;
            head = new Node(-1);
            tail = head;          
            this -> next = NULL;  
        }

        // Operations

        void push(int d){
            if(track <size){
                Node* newNode = new Node(d);
                tail -> next = newNode;
            
                
            }

        }
};

int main()
{
    


    
    return 0;
}