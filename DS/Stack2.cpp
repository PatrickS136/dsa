#include <bits/stdc++.h>

using namespace std;

#define MAX 10

typedef class stack{
  private: 
  int items[MAX], top;

  public:
  stack(){
    cout<<"\nYou have created a stack\n\n";
    top=-1;
  }

  bool isEmpty(){
    if (top==-1){
      cout<<"STACK IS Empty\n\n";
      return true;
    }
    return false;
  }

  bool isFull(){
    if (top==MAX-1){
      cout<<"STACK IS FULL\n\n";
      return true;
    }
    return false;
  }

  void push(int num){
    if (isFull()){
      return;
    }
    top++;
    items[top]=num;
    cout<<"ITEM PUSHED IS : "<<items[top]<<"\n\n";
    return;
  }

  void pop(){
    if (isEmpty()){
      return;
    }
    top--;
    cout<<"ITEM POPPED IS : "<<items[top+1]<<"\n\n";
    return;
  }

  void peek(){
    if (isEmpty()){
      return;
    }
    cout<<"THE TOP ITEM IS : "<<items[top]<<endl;
  }

  void printStack(){
    if (isEmpty()){
      return;
    }
    cout<<"The items in the stack are : ";
    for (int i=0; i<=top; i++){
      cout<<items[i]<<" ";
    }
    cout<<"\n\n";
    return;
  }

} sta;

int main(void){

  sta s;
  s.pop();

  s.push(1);
  s.printStack();

  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  s.printStack();

  s.pop();

  s.printStack();

  return 0;
}