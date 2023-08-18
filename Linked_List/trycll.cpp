#include<iostream>
using namespace std;
 
class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

};

void insertNode(Node* &tail, int val, int d){
    if(tail == NULL){
        Node* newNode = new Node(d);

        tail = newNode;

        newNode -> next = newNode;
        return;
    }

    // assuming val input is present in the list.
    Node* curr = tail;

    while(curr -> data != val){
 
        curr = curr -> next;
    }

    Node* temp = new Node(d);

    temp -> next = curr -> next;
    curr -> next = temp;

}

void del(Node* &tail, int val){
    if(tail == NULL){
        cout<<"empty LL"<<endl;
        return;
    }

    Node* prev = tail;
    Node* curr = prev -> next;

    while(curr -> data != val){
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = curr -> next ;

    if(curr == prev){
        tail = NULL;
    }

    if(curr == tail){
        tail = curr -> next;
    }
    
    curr -> next = NULL;

    cout<<"Deleted element: "<<curr -> data<<endl;

    delete curr;

}

void print(Node* tail){
    
    if(tail == NULL){
        cout<<"empty LL"<<endl;
        return;
    }

    Node* temp = tail;

    do{
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }while(temp != tail);
    cout<<endl;

}

int main()
{
    Node* tail  = NULL;

    insertNode(tail, 5, 3);
    print(tail);
    
    // insertNode(tail, 3, 2);
    // print(tail);
    
    // insertNode(tail, 3, 4);
    // print(tail);

    del(tail,3 );
    print(tail);
    
    return 0;
}