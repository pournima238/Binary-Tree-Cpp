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
//levelOrderTraversal
void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }

    }
}
//level order traversal using level seperators..
void levelWithSeperators(node *root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
    
}


int main(){
    node* root=NULL;
    root=buildTree(root);
    cout<<"printing level order traversal in one line"<<endl;
    levelOrderTraversal(root);
    cout<<"printing level order traversal levelwise"<<endl;
    levelWithSeperators(root);



}