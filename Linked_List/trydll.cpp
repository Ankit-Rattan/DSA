#include<iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;
        Node* prev;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }    
};

void insertAtHead(Node* &head, int d){

    Node* temp = new Node(d);

    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtAny(Node* &head, int pos, int d){
    if(pos == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;

    int count = 1;
    while(count < pos-1){
        temp = temp->next;
        count++;
    }

    Node* insertVal = new Node(d);

    insertVal -> next = temp -> next;
    temp -> next -> prev = insertVal;
    insertVal -> prev = temp;    
    temp -> next = insertVal;

}

void del(Node* &head, int pos){

    if(pos == 1){

        Node* temp = head;

        
        head = temp -> next;
        temp -> next = NULL;
        head -> prev = NULL;

        cout<<"Deleted element : "<<temp -> data<<endl;
        cout<<"New Head : "<<head -> data<<endl;

        delete temp;

    }

    Node* curr = head;
    Node* prev = NULL;

    int count = 1;
    while(count < pos){
        prev = curr;
        curr = curr -> next;
        count++;
    }

    prev -> next = curr -> next;
    curr -> next -> prev = prev;
    curr -> prev = NULL;
    curr -> next = NULL;

    cout<<"Deleted element : "<<curr -> data<<endl;

    delete curr;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main()
{
    Node* node1 = new Node(10);

    Node* head = node1;

    insertAtAny(head, 1, 12);
    insertAtAny(head, 2, 11);
    // insertAtAny(head,3 , 13);
    print(head);

    del(head, 1);
    print(head);


    return 0;
}