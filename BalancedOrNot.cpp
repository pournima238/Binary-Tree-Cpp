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
//height function
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
//balance fast approach o(n) time required
pair<bool,int> BalancedFast(node* root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true, 0);
            return p;
        }
        pair<bool, int> left=BalancedFast(root->left);
        pair<bool,int>right=BalancedFast(root->right);
        bool diff=abs(left.second-right.second)<=1;
        pair<bool, int>ans;
        ans.second=max(left.second,right.second)+1;
        ans.first=(left.first && right.first && diff);
        return ans;
    }

//balance tree slow approach o(n^2)  and uses height function
 bool isBalanced(node *root)
    {
        //bse case
        if(root==NULL){
            return true;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;
        
        if(left && right && diff){
            return true;
        }else{
            return false;
        }
        //return BalancedFast(root).first;
    }


int main(){
    node* root=NULL;
    root=buildTree(root);
   cout<<"balanced or not using slow approach"<<endl;
   cout<<isBalanced(root);
   cout<<endl;
   cout<<"balanced or not using fast approach"<<endl;
   cout<<BalancedFast(root).first;


}