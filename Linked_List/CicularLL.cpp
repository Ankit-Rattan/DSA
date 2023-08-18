#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next; 

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};

void insertNode(Node* &tail, int ele, int d){

    if(tail == NULL){
        Node* newNode = new Node(d);

        tail = newNode;

        newNode -> next = newNode;
        return;
    }

    Node* temp = tail;

    while(temp -> data != ele){
        temp = temp -> next;
    }

    Node* newNode = new Node(d);

    newNode -> next = temp -> next;
    temp -> next  = newNode;

}

void del(Node* &tail, int ele){

    if(tail == NULL){
        cout<<"This is Emply LL"<<endl;
        return;
    }

    Node* prev = tail;
    Node* curr = prev -> next;

    while(curr-> data != ele){
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = curr -> next;

    // for single data CLL

    if(curr == prev){
        tail = NULL;
    }

    // for >2 and for deleting tail data
    if(tail == curr){
        tail = prev;
    }

    curr -> next = NULL;
    cout<<"Deleted element: "<<curr -> data<<endl;
    delete curr;
}

void print(Node* &tail){

    Node* temp = tail;

    if(tail == NULL){
        cout<<"Empty List"<<endl;
        return;
    }

    do{
        cout<<temp -> data<<" ";
        temp = temp -> next;

    }while(temp != tail);

    cout<<endl;
}

int main()
{
    Node* tail = NULL;

    insertNode(tail, 5, 1);
    print(tail);

    insertNode(tail, 1, 2);
    print(tail);
    
    insertNode(tail, 1, 3);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    del(tail, 1);
    print(tail);


    return 0;
}