#include <bits/stdc++.h>

using namespace std;

typedef class Graph{
  public:
  int numVer;
  bool ** adjMat;

  Graph(int num){
    numVer=num;
    adjMat=new bool*[num];
    for (int i=0; i<num; i++){
      adjMat[i]=new bool[num];
      for (int j=0; j<num; j++){
        adjMat[i][j]=false;
      }
    }
    cout<<"Graph created\n";
  }

  void addEdge(int x, int y){
    adjMat[x][y]=true;
    adjMat[y][x]=true;
  }

  void delEdge(int x, int y){
    adjMat[x][y]=false;
    adjMat[y][x]=false;
  }

  void printArray(){
    for (int i=0; i<numVer; i++){
      cout<<"Row "<<i+1<<" : ";
      for (int j=0; j<numVer; j++){
        cout<<adjMat[i][j]<<" ";
      }
      cout<<"\n";
    }
  }

  ~Graph(){
    for (int i=0; i<numVer; i++){
        free(adjMat[i]);
    }
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
  g.addEdge(2, 0);
  g.addEdge(2, 3);

  g.printArray();
 

  return 0;
}