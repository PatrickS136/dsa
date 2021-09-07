#include <bits/stdc++.h>

using namespace std;

typedef class BFSgraph{

  int numVer;
  bool * visited;
  list<int> * adjList;

  public:
  BFSgraph(int num){
    cout<<"\nYou have created a graph !\n\n";
    numVer=num;
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
    adjList[dest].push_back(src);
    return;
  }

  void BFS(int src){
    visited=new bool[numVer];
    list<int> qu;
    qu.push_back(src);
    for (int i = 0; i < numVer; i++){
      visited[i] = false;
    }
    visited[src]=true;

    while (!(qu.empty())){
      for (auto x : adjList[qu.front()]){
        if (!visited[x]){
          qu.push_back(x);
          visited[x]=true;
        }
      }
      cout<<qu.front()<<" ";
      qu.pop_front();
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

  g.BFS(2);

  cout<<endl;

  g.addEdge(2, 3);

  g.BFS(0);

  cout<<endl;

  return 0;
}