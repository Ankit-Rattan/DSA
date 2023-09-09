#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL; 
    }    
};

node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;

    root = new node(data);
    
    if(data == -1) return NULL;

    cout<<"Enter the data for the left of "<<data<<endl;
    root -> left = buildTree(root -> left);
    cout<<"Enter the data for the right of "<<data<<endl;
    root -> right = buildTree(root -> right);
    return root;
}

void buildFromLevelOrder(node* &root){
    queue<node*>q;

    cout<<"Enter the data for root"<<endl;
    int data; cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"Enter left Node for"<<temp -> data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        cout<<"Enter the right node for "<< temp -> data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }

    }
}

int main()
{
    node* root = NULL;
    root = buildTree(root);


    return 0;
}