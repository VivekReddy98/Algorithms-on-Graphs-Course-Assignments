#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set> 
using std::vector;
using std::pair;

bool explore(vector<vector<int> > &adj, int m, bool arr[], std::stack<int> s);

std::unordered_set<int, std::hash<int> , std::equal_to<int> > compSet;

int number_of_components(vector<vector<int> > &adj, int n) {
  int res = 0;
  bool arr[n] = {false};
  std::stack<int> s;
  std::unordered_set<int>::iterator it;
  for(int i=0; i<n; i++)
  {
    compSet.insert(i);
  }
  while(not(compSet.empty()))
  {
    it = compSet.begin();
    int element = *it;
    // std::cout << "root" << element << std::endl;
    explore(adj,element,arr,s);
    res += 1;
  }
 
  return res;
}


bool explore(vector<vector<int> > &adj, int m, bool arr[], std::stack<int> s){
  // std::cout << "explore:  " << m << std::endl;
  arr[m] = true;
  s.push(m);
  compSet.erase(m);
  vector<int>::iterator ptr; 
  for(ptr = adj[m].begin(); ptr<adj[m].end(); ptr++)
  {
    if(arr[*ptr]!=true)
    {
      // std::cout << "neighbour:  " << *ptr << std::endl;
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
  std::cout << number_of_components(adj, n);
}
