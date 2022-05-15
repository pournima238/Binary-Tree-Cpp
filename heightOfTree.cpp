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
int heightOfTree(node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    int left=heightOfTree(root->left);
    int right=heightOfTree(root->right);
    int ans=max(left, right)+1;
    return ans;
}


int main(){
    node* root=NULL;
    root=buildTree(root);
    cout<<"Height of tree"<<endl;
    cout<<heightOfTree(root);


}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1