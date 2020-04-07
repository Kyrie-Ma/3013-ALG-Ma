#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;
bool visited[10000];
// Graph class represents a directed graph
// using adjacency list representation
class Graph {
    int V; // No. of vertices
    vector<int> *adj;
    int count;

public:
    Graph(int V); // Constructor
    int print();
    // function to add an edge to graph
    void addEdge(int v, int w);
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
    void clean(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v);
}


// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil(
void Graph::DFS(int v) {
    // Mark all the vertices as not visited
    //bool *visited = new bool[V];
    if(visited[v] == true)
      return;
    visited[v]=true;
    int x;
    for (int i = 0; i <adj[v].size(); i++)
      x=adj[v][i];
    // Call the recursive helper function
    // to print DFS traversal
    if(visited[x] == false)
      DFS(x);
}

int Graph::print(){
  count--;
  return count;
}

void Graph::clean(int v){
  for(int i = 0; i < v; i++)
  {
    adj[i].clear();
    visited[i] = false;
  }
}
// Driver code
int main() {
    int n;  int count2 = 0;  string temp;
    cin >> n; // read in number of instances
    for (int i = 0; i < n; i++) {

        char ve; // max node
        cin >> ve;
        int v = ve - 65+1;
        Graph g(v);
        cin.ignore();
        int t1, t2;
        while (getline(cin, temp)) {
          if(temp[0]== '\0')
            break;
          t1 = temp[0] - 65;
          t2 = temp[1] - 65;
          g.addEdge(t1, t2);
        }
         for (int j = 0; j < v; j++) {
           if(visited[j] == false){
         	    g.DFS(j);
              count2++;
           }
         }
      cout << count2 << endl << endl;
      count2 = 0;
      g.clean(v);
    }
    return 0;
}
