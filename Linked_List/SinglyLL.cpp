#include<iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node* next;

    // Constructor: 
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }    

};

// Insert at Head

void insertAtHead(Node* &head, int d){

    // Creating temperary node (pointer);
    Node* temp = new Node(d);

    temp -> next = head;   // Connecting Nodes

    head = temp;     // Changing head pointer address.
}

// Printing  (Traversing)
void print(Node* &head){

    Node* temp = head;

    while(temp!=NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}


// INSERT AT TAIL

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);

    tail -> next = temp;

    tail = temp;
}


/*
    NOTE: 

    -> Initially both 'head' and 'tail' are at one position, (In General)
*/
int main()
{

    Node* node1 = new Node(10);

    // cout<< node1 -> data<<endl;
    // cout<<node1 -> next<<endl;
    

    Node* head = node1;
    Node* tail = node1;

    // insertAtHead(head, 12);

    cout<<"Enter the numbers to added in Linked-List AT HEAD"<<endl;
    int ns;
    cin>>ns;
    for(int i=0; i<ns; i++){
        int ele ;
        cin>>ele;
        insertAtHead(head, ele);
    }

    cout<<"Enter the number to added AT TAIL"<<endl;
    int ne;
    cin>>ne;
    for(int i=0; i<ne; i++){
        int ele;
        cin>>ele;
        insertAtTail(tail, ele);
    }

    print(head);

    return 0;
}