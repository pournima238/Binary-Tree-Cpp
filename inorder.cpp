//LNR
//INorder==>>LNR=>GO LEFT->PRINT->GO RIGHT
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
//constructor initializing all values when node is created
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

//function to create tree
node * buildTree(node* root){
int data;
cout<<"enter the data"<<endl;
cin>>data;
if(data==-1){
    return NULL;
}
root=new node(data);
cout<<"enter left node data of "<<data<<endl;
root->left=buildTree(root->left);
cout<<"enter right node data of "<<data<<endl;
root->right=buildTree(root->right);

return root;

}
void inorder(node* root){
    if(root==NULL){
        return ;
    }
   // cout<<root->data<<" ";
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    //cout<<root->data<<" ";
    

}

int main(){
    node* root=NULL;
    root=buildTree(root);
    cout<<"inorder Series"<<endl;
    inorder(root);


}

//input
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1