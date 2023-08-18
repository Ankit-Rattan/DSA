#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this-> data = data;
        this -> next = NULL;
    }    

    // ~Node(){
    //     int value = this -> data;

    //     // Memory free
    //     if(this-> next != NULL){
    //         delete next;
    //         this -> next = NULL;
    //     }

    // }

};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);

    temp -> next = head;

    head = temp;
}

void insertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);

    tail -> next = temp;

    tail = temp;

}

void insertAtAny(Node* &head, int position, int d){

    if(position ==1){
        insertAtHead(head, d);
        return ;   // to skip all below part.
    }
    Node* temp =head;
    int cnt = 1;
    while(cnt<position-1){
        temp = temp->next; 
        cnt++;
    }

    Node* insertNode = new Node(d);

    insertNode -> next = temp -> next;
    temp -> next = insertNode;
}

void del(int position, Node* &head){
    if(position ==1){
        Node* temp = head;
        head = head->next;

        temp -> next = NULL;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    int cnt = 1;
    while(cnt<position){
        prev = curr;
        curr = curr -> next;
        cnt++;
    }

    prev -> next = curr -> next;
    curr-> next = NULL;
    delete curr;


}

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

    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL "<<endl;
}




int main()
{
    int n; cout<<"Enter first value: "; cin>>n;

    Node* node1 = new Node(n);

    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head,1);
    insertAtHead(head,10);



    insertAtAny(head, 1, 20);
    print(head);
    cout<<endl;





    
    return 0;
}