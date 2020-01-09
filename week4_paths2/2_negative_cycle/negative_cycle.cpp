#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <climits>
#include <utility>
#include <algorithm>

#define MAX (int)100000;

using namespace std;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  vector<bool> visited_nodes(adj.size(), false);
  for(int node=0;node<adj.size();node++){
    if(visited_nodes[node]) continue;
    int source = node;
    vector<int> shortestDis(adj.size(), 100000);
    shortestDis[source] = 0;
    for(int itr=1;itr<=adj.size();itr++){
      for(int i=0;i<adj.size();i++){
        
        for(int j=0;j<adj[i].size();j++){
          if(shortestDis[adj[i][j]]>cost[i][j]+shortestDis[i]) {
            //cout << itr << " edge u: " << i+1 << " edge v: " << adj[i][j]+1 << " source: " << source+1 << endl;
            //cout << "Initial_dis: " << shortestDis[adj[i][j]] << " Final_dis: " << cost[i][j] << " + " << shortestDis[i] << endl; 
            if(itr==adj.size()){
              return 1;
            }
            shortestDis[adj[i][j]]=shortestDis[i]+cost[i][j];
            visited_nodes[adj[i][j]] = true;
        }
      }
    }
   }
   }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
