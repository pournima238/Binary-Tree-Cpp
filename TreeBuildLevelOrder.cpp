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

//function to create tree through level order logic.
void buildTree(node* &root){
    int data;
    cout<<"Enter root node data"<<endl;
    cin>>data;
    root= new node(data);
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        int leftDta;
         cout<<"Enter left node for"<<temp->data<<endl;
         cin>>leftDta;
        if(leftDta!=-1){
            temp->left=new node(leftDta);
            q.push(temp->left);

        }
        int RDta;
         cout<<"Enter right node for"<<temp->data<<endl;
         cin>>RDta;
        if(RDta!=-1){
            temp->right=new node(RDta);
            q.push(temp->right);

        }

    }

}


int main(){
    node* root=NULL;
    buildTree(root);


}