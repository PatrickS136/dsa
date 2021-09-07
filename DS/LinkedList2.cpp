#include <bits/stdc++.h>

using namespace std;

typedef class Nodes{
  public:
  int val;
  Nodes * next;
} node;

void insertBegin(node ** head, node * x){
  x->next=*head;
  *head=x;

  cout<<"This value is inserted to the beginning : "<<x->val<<"\n\n";

  return;
}

void insertEnd(node * head, node * x){
  node * end=head;
  while(end->next!=NULL){
    end=end->next;
  }

  end->next=x;
  x->next=NULL;

  cout<<"This value is inserted to the end : "<<x->val<<"\n\n";

  return;
}

void insertNode(node * prev, node * x){

  if (prev==NULL){
    cout<<"The previous node cannot be NULL\n\n";
    return;
  }

  x->next=prev->next;
  prev->next=x;

  cout<<"This value is inserted in the list : "<<x->val<<"\n\n";

  return;
}

void delet(node * head, node * x){
  if (x->next==NULL || x==head){
    delete x;
    x=NULL;
    return;
  }
  node * current=head;
  while (current->next!=x){
    current=current->next;
  }
  cout<<"This value is deleted from the list : "<<x->val<<"\n\n";
  current->next=x->next;
  delete x;
  

  return;
}

void printLL(node * head){
  node * current=head;
  while (current!=NULL){
    cout<<current->val<<" ";
    current=current->next;
  }
  cout<<"\n\n";
}

int main(void){
  ios::sync_with_stdio(0); 
  cin.tie(0);

  node * head=NULL;

  node * first=new node;
  node * second=new node;

  first->val=1;
  second->val=2;

  first->next=second;
  second->next=NULL;

  head=first;

  printLL(head);

  node * newnode=new node;
  newnode->val=0;

  node * newend=new node;
  newend->val=3;

  insertBegin(&head, newnode);
  insertEnd(head, newend);

  node * newmid=new node;
  newmid->val=0;

  insertNode(first, newmid);
  delet(head, first);

  printLL(head);

  delete first;
  delete second;


  return 0;
}