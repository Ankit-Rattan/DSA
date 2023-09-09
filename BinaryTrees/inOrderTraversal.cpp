#include<iostream>
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

void inorder(node* root){
    if(root == NULL) return;

    inorder(root -> left);     // -> Left (L)
    cout<< root -> data << " ";
    inorder(root -> right);  // -> Right (R)
    
}

int main()
{
    node* root = NULL;
    root = buildTree(root);

    inorder(root);


    return 0;
}