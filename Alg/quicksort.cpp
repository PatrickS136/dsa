#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void tuker(int * a, int * b){
  int temp=*a;
  *a=*b;
  *b=temp;
  return;
}

int partition(int * arr, int l, int r){
  int i=l-1;

  for (int j=l; j<=r-1; j++){
    if (arr[j]<arr[r]){
      i++;
      tuker(&arr[i],&arr[j]);
    }
  }
  
  tuker(&arr[i+1],&arr[r]);
  return i+1;
}

void quicksort(int * arr, int l, int r){
  if (l>=r){
    return;
  }
  int pivot=partition(arr,l,r);
  quicksort(arr,l,pivot-1);
  quicksort(arr,pivot+1,r);
  return;
}

void printarray(int arr[], int len){
  for (int i=0; i<len; i++){
    cout<<arr[i]<<" ";
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr[]={5,9,-10,2,4,8,0,20,-100,-71};

  quicksort(arr,0,9);

  printarray(arr,10);

  //ull num;
  //cin>>num;

  //for (ull i=0; i<num; i++){
    
  //}

  
  return 0;
}