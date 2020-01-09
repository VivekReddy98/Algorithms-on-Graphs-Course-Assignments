#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

//  std::cout << "Size of the queue" << Que.size() << std::endl;       
//  for(int i: visited_arr) std::cout << i << "\t";
//  std::cout << std::endl;

int bipartite(vector<vector<int> > &adj, int nodes) {
  vector<int>::iterator ptr; 
  queue<int> Que;
  int parent;
  int visited_arr[nodes];
  for(int i=0; i<nodes; i++) visited_arr[i]=0;

  for(int i=0; i<nodes; i++){
    if (visited_arr[i]==0){
      Que.push(i);
      visited_arr[0] = -1; 
      while(!Que.empty()){
        parent = Que.front();
        Que.pop();
        for(ptr = adj[parent].begin(); ptr<adj[parent].end(); ptr++)
          {
            if (visited_arr[*ptr]==0){
            if(visited_arr[parent] == -1) {
              Que.push(*ptr);
              visited_arr[*ptr] = 1;
            }
            else{
              Que.push(*ptr);
              visited_arr[*ptr] = -1;
            } }
            else {
              if(visited_arr[*ptr] == visited_arr[parent]){
                return 0;
              }
            }  
          }
      }
    }    
  }
  return 1;
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
  std::cout << bipartite(adj, n);
}
