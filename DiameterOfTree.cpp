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
//height of tree
int height(node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left, right)+1;
    return ans;
}
//function to find diameter using height function
 int diameter(node* root) {
        //base case
        if(root==NULL){
            return 0;
        }
        int op1=diameter(root->left);
        int op2=diameter(root->right);
        int op3=height(root->left)+height(root->right)+1;
        int ans=max(op3,max(op1,op2));
        return ans;
        //return diameterFast(root).first;
    }

//time of o(n) functon to find diameter of tree
 pair<int,int>diameterFast(node* root){
        //base case
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        pair<int,int>left=diameterFast(root->left);
        pair<int,int>right=diameterFast(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second+1;
        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }


int main(){
    node* root=NULL;
    root=buildTree(root);
    cout<<"diameter of tree using o(n2)"<<endl;
    cout<<diameter(root);
    cout<<"diameter of tree using o(n)"<<endl;
    cout<<diameterFast(root).first;
}