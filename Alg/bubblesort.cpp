#include <bits/stdc++.h>

using namespace std;

void printArray(int array[], int size){
  for (int i=0; i<size; i++){
    cout<<array[i];
    if (i!=size-1){
      cout<<" ";
    }
    else{
      cout<<"\n";
    }
  }
}

int main(void){
  ios::sync_with_stdio(0); 
  cin.tie(0);

  int x[]={3,7,1,2,0,9,-10};
  int size=7;

  for (int unsorted=size; unsorted>0; unsorted--){
    bool swapped=false;
    for (int i=1; i<unsorted; i++){
      if (x[i]<x[i-1]){
        swap(x[i],x[i-1]);
        swapped=true;
      }
    }
    if (!swapped){
      break;
    }
  }

  printArray(x,size);


  return 0;
}