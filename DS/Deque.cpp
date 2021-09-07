#include <bits/stdc++.h>

using namespace std;

#define MAX 5

typedef class deque{
  public:
  int items[MAX], front, rear;
  deque(){
    front=-1;
    rear=-1;
    cout<<"\nYou have created a deque\n\n";
  }

  bool isEmpty(){
    if (front==-1 && rear==-1){
      return true;
    }
    return false;
  }

  bool isFull(){
    if (rear==MAX-1 || front==rear+1){
      return true;
    }
    return false;
  }

  void pushrear(int num){
    if (isFull()){
      cout<<"Deque is full\n\n";
      return;
    }
    if (front==-1){
      front=(front+1)%MAX;
    }
    rear=(rear+1)%MAX;
    items[rear]=num;
    return;
  }

  void poprear(){
    if (isEmpty()){
      cout<<"Deque is empty\n\n";
      return;
    }
    if (front==rear){
      front=-1;
      rear=-1;
      return;
    }
    rear=(rear-1)%MAX;
    return;
  }

  void pushfront(int num){
    if (isFull()){
      cout<<"Deque is full\n\n";
      return;
    }
    if (rear==-1){
      rear=(rear+1)%MAX;
      front=(front+1)%MAX;
      items[front]=num;
      return;
    }
    else{
    front=(front+4)%MAX;
    items[front]=num;
    return;
    }
  }

  void popfront(){
    if (isEmpty()){
      cout<<"Deque is empty\n\n";
      return;
    }
    if (front==rear){
      front=-1;
      rear=-1;
      return;
    }
    front=(front+6)%MAX;
    return;
  }

  void printdeque(){
    if (isEmpty()){
      cout<<"Deque is empty\n\n";
      return;
    }
    cout<<"Deque contains : ";
    if (front>rear){
      for (int i=front; i<MAX; i++){
        cout<<items[i];
      }
      for (int i=0; i<=rear; i++){
        cout<<items[i];
      }
    }
    else{
      for (int i=front; i<=rear; i++){
        cout<<items[i];
      }
    }
    return;
  }

} deq;

int main(void){
  ios::sync_with_stdio(0); 
  cin.tie(0);
  
  deq x;
  
  x.poprear();

  x.pushrear(1);
  x.pushrear(2);
  x.pushrear(3);
  x.pushrear(4);
  x.pushrear(5);

  x.popfront();
  x.poprear();
  x.pushfront(5);
  x.pushfront(1);

  x.printdeque();
  
  return 0;
}