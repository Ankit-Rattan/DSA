#include<iostream>
using namespace std;

class Node{
    public :
        int data;
        Node* next;

    Node(int data){
        this-> data = data;
        this -> next = NULL;
    }    
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);

    temp-> next = head;

    head = temp;

}

void insertAtAny(Node* &head, int d, int pos){
    if(pos ==1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count =1;
    while(count<pos-1){
        temp = temp-> next;
        count++;
    }
    Node* insertNode = new Node(d);
    insertNode -> next = temp -> next;
    temp -> next = insertNode;
}

void print(Node* &head){
    Node* temp = head;
    cout<<endl;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    cout<<endl;
}

void delPos(Node* &head, int pos){
    if(pos==1){
        Node* temp = head;
        head  = head -> next;
        temp-> next = NULL;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int count=1;
    while(count<pos){
        prev = curr;
        curr = curr-> next;
        count++;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;

}

void delVal(Node* &head, int v ){
    Node* temp = head;
    int p =1;
    while(temp -> data != v){
        temp  =temp-> next;
        p++;
    }
    if(p == 1){
        Node* t = head;
        head = head-> next;
        t -> next = NULL;
        delete t;
        return;
    }

    Node* curr= head;
    Node* prev = NULL;
    int count =1;
    while(count<p){
        prev = curr;
        curr = curr->next;
        count++;
    }

    prev-> next = curr -> next;

    curr-> next = NULL;
    delete  curr;

}
int main()
{
    int val;

    int first;
    cout<<"Enter the first value: ";
    cin>>first;

    Node* node1 = new Node(first);

    Node* head = node1;
    while(val!= 4){

    cout<<"1. Inserting Value "<<endl;
    cout<<"2. Deleting By Value "<<endl;
    cout<<"3. Deleting By Position "<<endl;
    cout<<"4. Show List"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter the value: ";
    cin>>val;

    if(val ==1){
        int n;
        cout<<"Enter Value: ";
        cin>>n;
        int pos; 
        cout<<"Enter Position: ";
        cin>>pos;
        insertAtAny(head, n, pos);
        print(head);
    }

    else if(val == 2){
        int v;
        cout<<"Enter value  to delete: ";
        cin>>v;
        delVal(head, v);
        print(head);
    }
    else if(val == 3){
        int pos;
        cout<<"Enter the postion: ";
        cin>>pos;
        delPos(head , pos);
        print(head);
    }
    else if(val == 4){
        print(head);
    }

    else{
        break;
    }

    }

    cout<<"Thank You"<<endl;
    return 0;


}