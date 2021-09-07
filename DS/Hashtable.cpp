#include <bits/stdc++.h>

using namespace std;
#define MAX 10

typedef class hashtable{
  private:
  list<pair<int,string>> tabel[MAX];
  public:
  hashtable();
  bool isEmpty();
  int hashfunction(int key);
  void insertElement(int key, string val);
  void deleteElement(int key);
  void searchTable(int key);
  void printHT();
} HT;

hashtable::hashtable(){
  cout<<"\nYou have created a hash table\n\n";
}

bool hashtable::isEmpty(){
  for (int i=0; i<MAX; i++){
    if (tabel[i].size()!=0){
      cout<<"Not empty\n\n";
      return false;
    }
  }
  cout<<"Empty\n\n";
  return true;
}

int hashtable::hashfunction(int key){
  return key%MAX;
}

void hashtable::insertElement(int key, string val){
  int index=hashfunction(key);
  bool keyexist=false;
  for (auto x=begin(tabel[index]); x!=end(tabel[index]); x++){
    if (x->first==key){
      keyexist=true;
      cout<<"Duplicate key, value replaced\n\n";
      x->second=val;
      return;
    }
  }

  if (!keyexist){
    tabel[index].emplace_back(key,val);
    cout<<"Added key : "<<key<<" and value : "<<val<<"\n\n";
    return;
  }
}

void hashtable::deleteElement(int key){
  int index=hashfunction(key);
  bool keyexist=false;
  for (auto x=begin(tabel[index]); x!=end(tabel[index]); x++){
    if (x->first==key){
      keyexist=true;
      cout<<"Key erased: "<<key<<"\n\n";
      tabel[index].erase(x);
      return;
    }
  }

  if (!keyexist){
    cout<<"Key doesn't exist\n\n";
  }

  return;
}

void hashtable::searchTable(int key){
  int index=hashfunction(key);
  bool keyexist=false;
  for (auto x=begin(tabel[index]); x!=end(tabel[index]); x++){
    if (x->first==key){
      cout<<"Key found : "<<key<<" with value : "<<x->second<<"\n\n";
      return;
    }
  }

  if (!keyexist){
    cout<<"Key doesn't exist\n\n";
  }

  return;
}

void hashtable::printHT(){
  if (isEmpty()){
    return;
  }
  for (int i=0; i<MAX; i++){
    if (tabel[i].size()==0){
      continue;
    }
    cout<<"Index "<<i<<" contains : \n";
    for (auto x:tabel[i]){
      cout<<"Key is : "<<x.first<<" value is : "<<x.second<<"\n";
    }
    cout<<"\n";
  }

  return;
}

int main(void){
  ios::sync_with_stdio(0); 
  cin.tie(0);

  HT lol;
  lol.isEmpty();
  lol.insertElement(10,"test10");
  lol.insertElement(10,"test10V2");
  lol.insertElement(100,"test100");
  lol.insertElement(29,"test100");
  lol.insertElement(56,"test100");
  lol.insertElement(77,"test100");
  lol.insertElement(98,"test100");
  lol.insertElement(12,"test100");
  lol.insertElement(41,"test100");
  lol.searchTable(10);
  lol.searchTable(10);
  lol.printHT();
  lol.isEmpty();


  return 0;
}