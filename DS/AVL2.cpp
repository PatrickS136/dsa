#include <bits/stdc++.h>

using namespace std;

typedef class avlnodes{
  public:
  int height;
  int val;
  avlnodes * left;
  avlnodes * right;
} Node;

int getHeight(Node * root){
  if (root==NULL){
    return 0;
  }
  return root->height;
}

int getBF(Node * root){
  if (root==NULL){
    return 0;
  }
  return getHeight(root->left)-getHeight(root->right);
}

Node * newnode(int data){
  Node * temp=new Node();
  temp->val=data;
  temp->left=temp->right=NULL;
  temp->height=1;

  return temp;
}

Node * leftrotate(Node * root){
  Node * RightNode=root->right;
  Node * Child=RightNode->left;

  RightNode->left=root;
  root->right=Child;

  root->height=max(getHeight(root->left),getHeight(root->right));
  RightNode->height=max(getHeight(RightNode->left),getHeight(RightNode->right));

  return RightNode;
}

Node * rightrotate(Node * root){
  Node *leftNode=root->left;
  Node * Child=leftNode->right;

  leftNode->right=root;
  root->left=Child;

  root->height=max(getHeight(root->left),getHeight(root->right));
  leftNode->height=max(getHeight(leftNode->left),getHeight(leftNode->right));

  return leftNode;
}

Node * Insert(Node * root, int data){
  if (root==NULL){
    return newnode(data);
  }
  if (data<root->val){
    root->left=Insert(root->left,data);
  }
  else if (data>root->val){
    root->right=Insert(root->right,data);
  }
  else{
    return root;  
  }

  int BF=getBF(root);

  root->height=max(getHeight(root->left),getHeight(root->right));

  if (BF>1){
    if (data<root->left->val){
      return rightrotate(root);
    }
    else{
      root->left=leftrotate(root->left);
      return rightrotate(root);
    }
  }
  if (BF<-1){
    if (data>root->right->val){
      return leftrotate(root);
    }
    else {
      root->right=rightrotate(root->right);
      return leftrotate(root);
    }
  }
  return root;
}

Node * findmin(Node * root){
  Node * current=root->right;
  while (current->left!=NULL){
    current=current->left;
  }

  return current;
}

Node *deleteNode(Node *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;
  if (key < root->val)
    root->left = deleteNode(root->left, key);
  else if (key > root->val)
    root->right = deleteNode(root->right, key);
  else {
    if (root==NULL){
      return root;
    }
    else if (root->left==NULL && root->right==NULL){
      delete root;
      root=NULL;
    }
    else if (root->left==NULL && root->right!=NULL){
      Node * x=root->right;
      delete root;
      root=x;
    }
    else if (root->left!=NULL && root->right==NULL){
      Node * x=root->left;
      delete root;
      root=x;
    }
    else{
      Node * inorderS=findmin(root);
      root->val=inorderS->val;
      root->right=deleteNode(root->right,inorderS->val);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(getHeight(root->left),
               getHeight(root->right));
  int balanceFactor = getBF(root);
  if (balanceFactor > 1) {
    if (getBF(root->left) >= 0) {
      return rightrotate(root);
    } else {
      root->left = leftrotate(root->left);
      return rightrotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBF(root->right) <= 0) {
      return leftrotate(root);
    } else {
      root->right = rightrotate(root->right);
      return leftrotate(root);
    }
  }

  return root;
}

// Print the tree
void printTree(Node *root, string indent, bool last) {
  if (root != nullptr) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->val << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}

int main(void){
  ios::sync_with_stdio(0); 
  cin.tie(0);

  Node *root = NULL;
  root = Insert(root, 33);
  root = Insert(root, 13);
  root = Insert(root, 53);
  root = Insert(root, 9);
  root = Insert(root, 21);
  root = Insert(root, 61);
  root = Insert(root, 8);
  root = Insert(root, 11);
  printTree(root, "", true);
  root = deleteNode(root, 13);
  cout << "After deleting " << endl;
  printTree(root, "", true);

  return 0;
}