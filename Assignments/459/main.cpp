#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;

typedef vector<int> vi;     // vector of integers
typedef pair<int, int> ii;  // pair of integers
typedef vector<ii> vii;     // vector of pairs

const int VISITED = 1;
const int UNVISITED = -1;

vi been_visited;            // container to keep track of who get visited
vector<vii> AdjList;        // AdjList stores our edge lists

int count = 0;

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil(
void DFS(int v) {
      been_visited[v]=VISITED;
      for (int i = 0; i <(int)AdjList[v].size(); i++){
        ii x=AdjList[v][i];
      
      // Call the recursive helper function
      // to print DFS traversal
        if(been_visited[x.first] == UNVISITED){
          DFS(x.first);
        }
      }
}

void clean(int v){
  for(int i = 0; i < v; i++)
  {
    AdjList[i].clear();
    been_visited[i] = UNVISITED;
  }
}
// Driver code
int main() {
    int n;  
    string temp;
    cin >> n; // read in number of instances
    int count2 = n;
    for (int i = 0; i < n; i++) {
      count2--;
        char ve; // max node
        cin >> ve;
        int v = ve - 64;
        AdjList.resize(v + 1);
        been_visited.resize(v+1, UNVISITED);
        cin.ignore();
        int t1, t2;
        while (getline(cin, temp)) {
          if(temp == ""){
             break;
          }
          t1 = temp[0] - 65;
          t2 = temp[1] - 65;
           AdjList[t1].push_back(make_pair(t2, 10));
           AdjList[t2].push_back(make_pair(t1, 10));
        }
        for (int j = 0; j < v; j++) {
            if(been_visited[j] == UNVISITED){
                DFS(j);
                count++;
            }
        }
      if(count2==0){
        cout << count << endl;
      }
      else{
          cout << count << endl << endl;
      }
      count = 0;
      clean(v);
      been_visited.clear();
    }
    return 0;
}
