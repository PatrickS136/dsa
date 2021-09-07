#include <bits/stdc++.h>

using namespace std;

typedef class nodes{
  public:
  int val;
  nodes * left;
  nodes * right;
} node;

void inorder(node * root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->val << " -> ";

    // Traverse right
    inorder(root->right);
  }
}

node * NewNode(int data){
  node * temp=new node;
  temp->val=data;
  temp->left=NULL;
  temp->right=NULL;

  return temp;
}

node * Insert(node * root, int data){
  if (root==NULL){
    root=NewNode(data);
  }
  else{
    if (data<=root->val){
      root->left=Insert(root->left, data);
    }
    else{
      root->right=Insert(root->right,data);
    }
  }
  return root;
}

bool Search(node * root, int data){
  if (root==NULL){
    return 0;
  }
  else if (root->val==data){
    return 1;
  }
  else if (data<root->val){
    return Search(root->left,data);
  }
  else{
    return Search(root->right,data);
  }
}

node * findMin(node * root){
  node * current = root;

  // Find the leftmost leaf
  while (current && current->left != NULL){
    current = current->left;
  }

  return current;
}

node * deleteNode(node * root, int data){
  if (root==NULL){
    return root;
  }
  else if (data<root->val){
    root->left=deleteNode(root->left, data);
  }
  else if (data>root->val){
    root->right=deleteNode(root->right, data);
  }
  else{ // DATA FOUND
    if (root->left==NULL){
      node * temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL){
      node * temp = root->left;
      free(root);
      return temp;
    }
    else if (root->right != NULL && root->left == NULL){
      node * temp=root;
      root=root->left;
      delete root;
      return root;
    }
    else{ 
      node * del=findMin(root->right);
      root->val=del->val;
      root->right=deleteNode(root->right, del->val);
    }
  }
  return root;
}

int main(void){
  ios::sync_with_stdio(0); 
  cin.tie(0);

  node * root= NULL;
  root = Insert(root, 8);
  root = Insert(root, 3);
  root = Insert(root, 1);
  root = Insert(root, 6);
  root = Insert(root, 7);
  root = Insert(root, 10);
  root = Insert(root, 14);
  root = Insert(root, 4);

  cout << "Inorder traversal: ";
  inorder(root);

  cout << "\nAfter deleting 10\n";
  root = deleteNode(root, 10);
  cout << "Inorder traversal: ";
  inorder(root);

  return 0;
}