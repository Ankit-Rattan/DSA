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

void postorder(node* root){
    if(root == NULL) return;

    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data<<" ";
}
int main()
{
    node* root = NULL;
    root = buildTree(root);
    postorder(root);

    return 0;
}