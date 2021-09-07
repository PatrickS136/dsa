#include <bits/stdc++.h>

using namespace std;

typedef class Graph{
  public:
  int numVer;
  list<int> * adjMat;

  Graph(int num){
    numVer=num;
    adjMat=new list<int>[num];
    cout<<"Graph created\n";
  }

  void addEdge(int x, int y){
    for (auto i: adjMat[x]){
      if (i==y || x==y){
        cout<<"Invalid edge\n";
        return;
      }
    }
    adjMat[x].push_back(y);
    adjMat[y].push_back(x);
  }

  void delEdge(int x, int y){
    bool rem=false;
    for (auto i=adjMat[x].begin(); i!=adjMat[x].end(); i++){
      if (*i==y){
        adjMat[x].erase(i);
        cout<<"Removed\n";
        rem=true;
        break;
      }
    }
    if (rem){
      for (auto i=adjMat[y].begin(); i!=adjMat[y].end(); i++){
        if (*i==x){
          adjMat[y].erase(i);;
        }
      }
    }
    return;
  }

  void printArray(){
    for (int i=0; i<numVer; i++){
      cout<<"Row "<<i<<" : ";
      for (auto j:adjMat[i]){
        cout<<j<<" ";
      }
      cout<<"\n";
    }
  }

  ~Graph(){
    free(adjMat);
    cout<<"Graph erased\n";
  }

} G;

int main(void){
  ios::sync_with_stdio(0); 
  cin.tie(0);

  G g(4);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(2, 0);

  g.printArray();
  g.addEdge(2, 0);

  g.delEdge(0,1);

  g.printArray();
 

  return 0;
}