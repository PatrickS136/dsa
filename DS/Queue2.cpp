#include <bits/stdc++.h>

using namespace std;

#define MAX 10

typedef class queue{
  private:
  int items[MAX],front,rear;

  public:
  queue(){
    cout<<"\nYou have created a queue\n\n";
    front=-1;
    rear=-1;
  }

  bool isEmpty(){
    if (front==-1){
      cout<<"The queue is empty\n\n";
      return true;
    }
    return false;
  }

  bool isFull(){
    if (rear==MAX-1){
      cout<<"The queue is full\n\n";
      return true;
    }
    return false;
  }

  void enqueue(int num){
    if (isFull()){
      return;
    }
    if (isEmpty()){
      front++;
    }
    rear++;
    items[rear]=num;

    cout<<"You have added : "<<items[rear]<<"\n\n";

    return;
  }

  void dequeue(){
    if (isEmpty()){
      return;
    }
    if (front==rear){
      cout<<"You have removed : "<<items[front]<<"\n\n";
      front=-1;
      rear=-1;
      return;
    }

    cout<<"You have removed : "<<items[front]<<"\n\n";
    front++;
    
    return;
  }

  void peek(){
    if (isEmpty()){
      return;
    }
    cout<<"The front element is : "<<items[front]<<"\n\n";
    return;
  }

  void printQueue(){
    if (isEmpty()){
      return;
    }
    cout<<"The elements are : ";
    for (int i=front; i<=rear; i++){
      cout<<items[i]<<" ";
    }
    cout<<"\n\n";

    return;
  }

} que;

int main(void){

  que q;

  q.dequeue();
  q.enqueue(1);

  q.printQueue();

  q.dequeue();
  q.printQueue();

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);
  q.enqueue(7);
  q.enqueue(8);
  q.enqueue(9);
  q.enqueue(10);
  q.enqueue(1);

  q.dequeue();
  q.printQueue();
  q.dequeue();
  q.printQueue();

  return 0;
}