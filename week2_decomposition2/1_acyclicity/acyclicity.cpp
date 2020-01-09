#include <iostream>
#include <vector>

using std::vector;
using std::pair;


bool traverse(vector<vector<int> > &adj, bool fwd_arr[], bool sink_nodes[], int node);

int acyclic(vector<vector<int> > &adj, int n) {

  bool fwd_arr[n] = {false};
  bool sink_nodes[n] = {false};
  for(int i = 0; i<n; i++)
  {
    if(sink_nodes[i] == false)
    {
      if(not(traverse(adj, fwd_arr, sink_nodes, i)))
      {
        return 1;
      }
    }
  }
  return 0;
}

bool traverse(vector<vector<int> > &adj, bool fwd_arr[], bool sink_nodes[], int node)
{
  // std::cout << "Traverse:  " << node+1 << "fwd_true: " << fwd_arr[node] << std::endl;
  if(fwd_arr[node] == true)
  {
    return false;
  }
  fwd_arr[node] = true;
  vector<int>::iterator ptr; 
  bool has_no_cycle = true;
  for(ptr = adj[node].begin(); ptr<adj[node].end(); ptr++)
  {
    if(sink_nodes[*ptr]==false)
    {
      has_no_cycle = traverse(adj, fwd_arr, sink_nodes, *ptr);
    }
    if(not(has_no_cycle))
    {
      break;
    }
  }
  sink_nodes[node] = true;
  // std::cout << "Node " <<  node+1 << " Has no Cycle " << has_no_cycle << " Sink Check" << sink_nodes[node] << std::endl;
  return has_no_cycle;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj, n);
}
