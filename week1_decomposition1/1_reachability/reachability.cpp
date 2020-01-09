#include <iostream>
#include <vector>
#include <stack> 

using std::vector;
using std::pair;

bool explore(vector<vector<int> > &adj, int m, bool arr[], std::stack<int> s);

int reach(vector<vector<int> > &adj, int x, int y, int n) {
  //write your code here
  bool arr[n] = {false};
  std::stack <int> s;
  s.push(x);
  arr[x] = true;
  explore(adj,x,arr,s);
  // for (int i = 0; i<n; i++)
  // {
  //   std::cout << arr[i] << '\t' << std::endl;
  // }
  if(arr[y]==true)
  {
    return 1;
  }
  return 0;
  }

bool explore(vector<vector<int> > &adj, int m, bool arr[], std::stack<int> s){
  // std::cout << "explore:  " << m << std::endl;
  vector<int>::iterator ptr; 
  for(ptr = adj[m].begin(); ptr<adj[m].end(); ptr++)
  {
    if(arr[*ptr]!=true)
    {
      // std::cout << "neighbour:  " << *ptr << std::endl;
      arr[*ptr] = true;
      s.push(*ptr);
      explore(adj,*ptr,arr,s);
    }
  }
  // std::cout << "popping out:  " << s.top() << std::endl;
  s.pop();
  return true;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1, n);
}
