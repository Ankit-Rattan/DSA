#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    // Constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }    

    // Program will run wihtout destructor also.
    // Destructor
    // ~Node(){
    //     int value = this -> data;
    //     if(this-> next != NULL){
    //         delete next;
    //         this -> next = NULL;
    //     }
    //     cout<<"memory free data: "<<value<<endl;
    // }

};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);

    temp-> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);

    tail-> next = temp;
    tail = temp;
}

void insertAtAny(Node* &head, int pos, int d){
    if(pos == 1){
        insertAtHead(head, d);
        return ;
    }

    Node* temp = head;
    int count = 1;

    while(count<pos-1){
        temp =temp-> next;
        count++;
    }

    Node* insertNode = new Node(d);
    
    insertNode-> next = temp-> next;
    temp -> next=  insertNode;

    
}

// DELETING  using positon;

void deleteNode(Node* &head, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head-> next;

        temp-> next = NULL;
        cout<<"Deleted Value is: "<<temp-> data<<endl;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    int count =1;
    while(count<pos){
        prev = curr;
        curr = curr-> next;

        count++;
    }

    prev -> next = curr -> next;

    curr-> next = NULL;

    cout<<"Deleted value is : "<<curr -> data<<endl;
    delete curr;

}


// DELETING BY Value

void delByValue(Node* &head, int val){
    int pos= 1;
    Node* temp = head;
    while(temp -> data != val){
        temp = temp-> next;
        pos++;
    }

    if(pos == 1){
        Node* temp = head;
        head = head->next;
        temp-> next = NULL;
    cout<<"Deleted Value: "<<temp->data<<endl;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    int count =1;
    while(count<pos){
        prev = curr;
        curr = curr-> next;
        count++;
    }

    prev->next = curr-> next;
    curr->next = NULL;

    cout<<"Deleted Value: "<<curr->data<<endl;

    delete curr;

}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;

    }
    cout<<"NULL"<<endl;
}

int main()
{
    int fv;
    cout<<"Enter the first value : ";
    cin>>fv;

    Node* node1 = new Node(fv);

    Node* head = node1;
    Node* tail = node1;


    insertAtHead(head, 12);
    insertAtHead(head, 13);
    
    insertAtTail(tail, 10);
    insertAtTail(tail, 11);

    cout<<endl;

    print(head);

    cout<<endl;

    insertAtAny(head, 6, 100);
    print(head);
    cout<<endl;

    deleteNode(head, 4);
    print(head);
    cout<<endl;

    delByValue(head, 12);
    print(head);

    return 0;
}