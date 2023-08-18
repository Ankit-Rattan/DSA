#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor

    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void print(Node*  head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" <=> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;

}

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);

    temp -> next = head;
    head-> prev = temp;
    
    head = temp ;
}


void insertAtTail(Node* &tail, int d){
    Node* temp =  new Node(d);

    temp->prev = tail; 
    tail -> next = temp;

    tail = temp;
}

void insert(Node* &head, int pos ,int d){
    if(pos == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;

    int count = 1;
    while(count < pos-1){
        temp = temp-> next;
        count ++;
    }

    Node* insertVal = new Node(d);

    insertVal ->next = temp -> next;
    temp->next->prev = insertVal;
    insertVal -> prev  = temp;
    temp -> next = insertVal;
}

void dele(Node* head, int pos){

    if(pos == 1){
        

    }
    Node* temp = head;

    int count = 1;
    while(count < pos-1){
        temp = temp-> next;
        count ++;
    }

    Node* toDelete = temp -> next;

    temp -> next = temp -> next -> next;
    temp -> next -> prev = temp -> next -> prev -> prev;
    cout<<"Deleted element : "<<toDelete -> data<<endl;
    delete toDelete;
}

void reverseNode(Node* &head){
    if(head == NULL || head -> next == NULL){
        return;
    }

    Node* backward = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;

        curr -> prev = curr -> next;
        curr -> next = backward;
        backward = curr;

        curr = forward;
    }

    head = backward;
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head, 15);
    insertAtTail(tail, 20);
    insert(head, 2,50);
    print(head);

    cout<<endl;

    reverseNode(head);
    print(head);

    return 0;
}
