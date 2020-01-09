#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <climits>
#include <utility>
#include <algorithm>

#ifdef INT_MIN
#endif

using namespace std;
typedef pair<int, int> iPair;  

int distance(vector<vector<int> > &adj, vector<vector<int>> &cost, int s, int t) {
  //vector<int>::iterator itr;
  priority_queue<iPair, vector <iPair>, greater<iPair>> pq; 
  pair<int, int> minInHeap;

  int shortestDis[adj.size()];
  bool visited_vertices[adj.size()];
  for(int i=0;i<adj.size();i++){
    shortestDis[i] = INT_MAX; 
    visited_vertices[i] = false;
  }

  shortestDis[s] = 0;
  visited_vertices[s] = true;
  pq.push(make_pair(0, s));
  // for(int i = 0; i<adj[s].size(); i++) {
  //   shortestDis[adj[s][i]] = cost[s][i];
  //   pq.push(std::make_pair(-1*cost[s][i], adj[s][i]));
  // }
  //cout << "fuck me" << endl;
  while(!pq.empty()) {
    minInHeap = pq.top();
    //cout << "minCost " << minInHeap.first << " Node: " << minInHeap.second << endl;
    pq.pop();
    visited_vertices[minInHeap.second] = true;
    for(int i=0;i<adj[minInHeap.second].size();i++) {
      if(!visited_vertices[adj[minInHeap.second][i]]){
        if(shortestDis[adj[minInHeap.second][i]]>cost[minInHeap.second][i]+shortestDis[minInHeap.second]) {
           shortestDis[adj[minInHeap.second][i]] = cost[minInHeap.second][i]+shortestDis[minInHeap.second];
           //cout << "shortestDistance: " << shortestDis[adj[minInHeap.second][i]] <<  " Node" << adj[minInHeap.second][i] << endl;
           pq.push(make_pair(shortestDis[adj[minInHeap.second][i]], adj[minInHeap.second][i]));
        }
      }
    }
  }
  
  if(visited_vertices[t]){
      return shortestDis[t];
  }
  return -1;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  int dis = distance(adj, cost, s, t);
  std::cout << dis << std::endl;
  return dis;
}
