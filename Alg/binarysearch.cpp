#include <bits/stdc++.h>

using namespace std;

void merge(int array[],int p, int q, int r){
  int len1=q-p+1;
  int len2=r-q;

  int x[len1];
  int y[len2];
  
  for (int i=0; i<len1; i++){
    x[i]=array[p+i];
  }
  for (int i=0; i<len2; i++){
    y[i]=array[q+1+i];
  }

  int j=0, k=0, l=p;

  while (j<len1 && k<len2){
    if (x[j]<=y[k]){
      array[l]=x[j];
      j++;
    }
    else{
      array[l]=y[k];
      k++;
    }
    l++;
  }

  while (j<len1){
    array[l]=x[j];
    j++;
    l++;
  }

  while (k<len2){
    array[l]=y[k];
    k++;
    l++;
  }
  return;
}

void mergesort(int array[], int p, int r){
  if (p>=r){
    return;
  }
  int mid=p+(r-p)/2;
  mergesort(array,p,mid);
  mergesort(array,mid+1,r);
  merge(array,p,mid,r);
  return;
}

int binarysearch(int array[], int p, int q, int num){
  if (p>q){
    return -1;
  }
  int mid=p+(q-p)/2;
  if (array[mid]==num){
    return mid;
  }
  else if (array[mid]>=num){
    return binarysearch(array,p,mid-1,num);
  }
  else{
    return binarysearch(array,mid+1,q,num);
  }
}

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

  mergesort(x,0,size-1);

  printArray(x,size);

  cout<<"Index for -10 is : "<<binarysearch(x,0,size-1,-10);


  return 0;
}