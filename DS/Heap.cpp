#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

void heapify(vector<int> &array, int i){
  int size=array.size();
  int largest=i;
  int leftchild=2*i+1;
  int rightchild=leftchild+1;

  if (leftchild<size && array[largest]<array[leftchild]){
    largest=leftchild;
  }
  if (rightchild<size && array[largest]<array[rightchild]){
    largest=rightchild;
  }

  if (largest!=i){
    swap(&array[largest],&array[i]);
    heapify(array, largest);
  }
  return;
}

void insert(vector<int> &array, int data){
  int size=array.size();
  array.push_back(data);
  if (size!=0){
    int size=array.size();
    for (int i=(size/2)-1; i>=0; i--){
      heapify(array,i);
    }
  }
  return;
}

void deletenode(vector<int> &array, int data){
  int size=array.size();
  int i;
  for (i=0; i<size; i++){
    if (array[i]==data){
      break;
    }
  }
  swap(&array[i],&array[size-1]);
  array.pop_back();
  for (int j=(size/2)-1; j>=0; j--){
    heapify(array,j);
  }
  return;
}

void printArray(vector<int> &hT)
{
  for (int i = 0; i < hT.size(); i++){
    cout << hT[i] << " ";
  }
  cout << "\n";
  return;
}

int main(void){
  ios::sync_with_stdio(0); 
  cin.tie(0);

  vector<int> heapTree;

  insert(heapTree, 3);
  insert(heapTree, 9);
  insert(heapTree, 2);
  insert(heapTree, 1);
  insert(heapTree, 4);
  insert(heapTree, 5);

  cout << "Max-Heap array: ";
  printArray(heapTree);

  deletenode(heapTree, 4);
  insert(heapTree, 10);

  cout << "After deleting an element: ";

  printArray(heapTree);

  return 0;
}