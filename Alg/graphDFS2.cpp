#include <bits/stdc++.h>

using namespace std;

typedef class dfsgraph{

  int numVer;
  bool * visited;
  list<int> * adjList;

  public:
  dfsgraph(int num){
    cout<<"\nYou have created a graph !\n\n";
    numVer=num;
    visited=new bool[num];
    adjList=new list<int>[num];
  }

  void addEdge(int src, int dest){
    for (auto x : adjList[src]){
      if (dest==x || x==src){
        cout<<"Invalid edge\n\n";
        return;
      }
    }

    adjList[src].push_back(dest);
    return;
  }

  void resetVisit(){
    for (int i=0; i<numVer; i++){
      visited[i]=false;
    }
  }

  void DFS(int src){
    visited[src]=true;

    cout<<src<<" ";

    for (auto x : adjList[src]){
      if (!visited[x]){
        DFS(x);
      }
    }
    return;
  }

} graph;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);

  g.DFS(2);

  cout<<endl;

  g.resetVisit();

  g.addEdge(2, 3);

  g.DFS(0);

  cout<<endl;

  return 0;
}