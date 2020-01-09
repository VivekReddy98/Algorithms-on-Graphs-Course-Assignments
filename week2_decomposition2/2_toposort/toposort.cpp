#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;
int counter=0;

void dfs(vector<vector<int> > &adj, vector<int> &used, int arr[], int x) {
  if (used.at(x) == 0)
  {
  // std::cout << "Start at: " << x+1 << std::endl;
  vector<int>::iterator ptr; 
  for(ptr = adj[x].begin(); ptr<adj[x].end(); ptr++)
  {
      dfs(adj,used,arr,*ptr);
  }
  // std::cout << "Sink Found: " << x+1 << std::endl;
  arr[counter] = x;
  counter++;
  used.at(x) = 1;
  }
}     

void toposort(vector<vector<int> > adj, int arr[]) {
  int m = adj.size();
  vector<int> used(m, 0);
  
  for(int i =0; i<m; i++)
  {
    if(used.at(i)==0)
    {
      dfs(adj,used,arr,i);
    }
  }
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  int arr[n];
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  toposort(adj, arr);
  for(int i = n-1; i>=0; i--)
  {
    std::cout << arr[i] + 1 << " ";
  }
  // std::vector<int>::reverse_iterator rit = order.rbegin();
  // for (; rit != order.rend(); ++rit) {
  //   std::cout << order[*rit] + 1 << " ";
  // }
}
