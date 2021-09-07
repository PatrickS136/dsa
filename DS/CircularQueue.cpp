#include <bits/stdc++.h>

using namespace std;

#define MAX 5

typedef class circQueue{
  public:
  int items[MAX],front,rear;
  public:
  circQueue(){
    cout<<"\nYou have created a circular queue!\n\n";
    front=-1;
    rear=-1;
  }

  bool isFull(){
    if ((front==0 && rear==MAX-1)||(front==rear+1)){
      return true;
    }
    return false;
  }

  bool isEmpty(){
    if (front==-1 && rear==-1){
      return true;
    }
    return false;
  }

  void enqueue(int num){
    if ((isFull())){
      cout<<"Queue is full\n\n";
      return;
    }
    if (front==-1){
      front=0;
    }
      rear=(rear+1)%MAX;
      items[rear]=num;
    return;
  }

  void dequeue(){
    if (isEmpty()){
      cout<<"Queue is empty\n\n";
      return;
    }
    if (front == rear) {
      front = -1;
      rear = -1;
      return;
    }
    front=(front+1)%MAX;
    return;
  }

  void peek(){
    if (isEmpty()){
      cout<<"Queue is empty\n\n";
      return;
    }
    cout<<"The front element is : "<<items[front]<<endl<<endl;
    return;
  }

  void dispCQ(){
    if (isEmpty()){
      cout<<"Queue is empty\n\n";
      return;
    }
    cout<<"The queue contains : ";
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
    cout<<"\n\n";
    return;
  }

} cq;

int main(void){
  ios::sync_with_stdio(0); 
  cin.tie(0);

  cq x;

  x.dequeue();

  x.enqueue(1);
  x.enqueue(2);
  x.enqueue(3);
  x.enqueue(4);
  x.enqueue(5);
  x.dequeue();
  x.dequeue();
  x.dequeue();
  x.enqueue(6);
  x.enqueue(7);
  x.dequeue();
  x.enqueue(8);
  x.enqueue(9);
  x.enqueue(0);
  cout<<"Front is : "<<x.front<<" rear is : "<<x.rear<<endl;

  x.dispCQ();


  return 0;
}