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

void preorder(node* root){
    if(root == NULL) return;
    
    cout<< root -> data<<" ";   // Node (N)
    preorder(root -> left);     // Left(L)
    preorder(root -> right);    // Right(R)
}
int main()
{
    node* root = NULL;
    root = buildTree(root);

    preorder(root);

    return 0;
}