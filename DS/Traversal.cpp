#include <bits/stdc++.h>

using namespace std;

typedef class NODE{
  public:
  int val;
  NODE * left, * right;
  NODE(int data);

}NODE;

NODE::NODE(int data){
  cout<<"Node created with value : " <<data<<"\n\n";
  val=data;
  left=NULL;
  right=NULL;
}

void inorder(NODE * root){
  if (root==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->val<<"->";
  inorder(root->right);
}

void preorder(NODE * root){
  if (root==NULL){
    return;
  }
  cout<<root->val<<"->";
  inorder(root->left);
  inorder(root->right);
}

void postorder(NODE * root){
  if (root==NULL){
    return;
  }
  inorder(root->left);
  inorder(root->right);
  cout<<root->val<<"->";
}

int main(void){
  ios::sync_with_stdio(0); 
  cin.tie(0);

  NODE * root= new NODE(5);
  root->left= new NODE(3);
  root->right=new NODE(4);

  postorder(root);
  cout<<"FINISHED\n\n";


  return 0;
}