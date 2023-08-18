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

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);

    temp  -> next = head;
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
        temp = temp -> next;
        count ++;
    }

    Node* insertVal = new Node(d);

    insertVal -> next = temp ->next;

    temp -> next = insertVal;

}


void del(Node* &head, int pos){
    
    if(pos == 1){
        Node* temp = head;

        head  = head -> next;

        temp -> next = NULL;
        cout<<"Deleted element : "<<temp -> data<<endl;

        delete temp;
        return;
    }


    Node* curr = head;
    Node* prev = NULL;

    int count = 1;
    while(count < pos){
        prev = curr;
        curr = curr -> next;
        count ++;
    }

    prev -> next  = curr -> next;
    curr -> next  = NULL;

    cout<<"Deleted element : "<<curr -> data<<endl;
    delete curr;
}
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data <<" ";
        temp  = temp -> next;
    }
    cout<<endl;
}

int main()
{   
    Node* node1 = new Node(10);
    
    Node* head = node1;
    Node* tail = node1;


    insertAtAny(head, 1, 11);
 

    insertAtAny(head, 3, 12);

    insertAtAny(head, 2, 13);

    print(head);

    del(head, 1);
    print(head);
    
    return 0;
}