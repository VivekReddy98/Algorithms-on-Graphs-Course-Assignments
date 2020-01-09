#include <iostream>
#include <vector>
#include <queue> 

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t, int nodes) {
  int visited_arr[nodes];
  for(int i=0; i<nodes; i++) visited_arr[i]=-1;
  
  vector<int>::iterator ptr; 
  queue<int> Que;
  
  visited_arr[s] = 0; 
  for(ptr = adj[s].begin(); ptr<adj[s].end(); ptr++)
  {
    Que.push(*ptr);
    visited_arr[*ptr] = 1;
  }
  
  int parent;
  while(!Que.empty()){
    parent = Que.front();
    Que.pop();
    for(ptr = adj[parent].begin(); ptr<adj[parent].end(); ptr++)
      {
        if (visited_arr[*ptr]<0){
         Que.push(*ptr);
        //  std::cout << "Size of the queue" << Que.size() << std::endl;
         visited_arr[*ptr] = visited_arr[parent] + 1;
        //  for(int i: visited_arr) std::cout << i << "\t";
        //  std::cout << std::endl;
        }  
      }
  }
  return visited_arr[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t, n);
}
