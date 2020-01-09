#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <utility>
#include <queue> 
#include <unordered_set> 

using namespace std;

struct location {
    int first;
    int second;
    location() {first = -1; second = -1;}
    location(int x, int y) {first = x; second = y;}
    bool operator==(const location& t) const {return (first == t.first && second == t.second);}
};

double distance(location loc1, location loc2) {return sqrt(pow(loc1.first-loc2.first, 2) + pow(loc1.second-loc2.second, 2));}

struct ds {
  location loc1;
  location loc2;
  double dis;
  ds(location i, location j) {
     loc1 = i;
     loc2 = j;
     dis = distance(loc1, loc2);
  }
  bool operator==(const ds& t) const {return ((loc1 == t.loc1 && loc2 == t.loc2) || (loc2 == t.loc1 && loc1 == t.loc2));}
  void print(){ 
      cout << dis << "  Point1: " << loc1.first << "," << loc1.second << "  Point2: " << loc2.first << "," << loc2.second << endl;
  }
};

struct Comparedis { 
    bool operator()(ds &d1, ds &d2) {return d1.dis > d2.dis;} 
}; 

class MyHashFunction { 
public: 
    unsigned long int operator()(const location& t) const
    { 
        return t.first*2000 + t.second; 
    } 
}; 


struct disjointSet{

    vector<unordered_set<location, MyHashFunction>> vecset;

    disjointSet() {}

    bool find(location &loc1, location &loc2){  
       int loc1_ptr = -1;
       int loc2_ptr = -1;

       for (int i=0; i<vecset.size(); i++){
          //cout << vecset[i].size() << " , ";   
          if (vecset[i].find(loc1) != vecset[i].end()) loc1_ptr = i;
          if (vecset[i].find(loc2) != vecset[i].end()) loc2_ptr = i;
       }
       
       //cout << loc1_ptr << "," << loc2_ptr << endl;

       if (loc1_ptr == -1 && loc2_ptr == -1) {
         vecset.push_back({loc1, loc2});
         return true;
       }
       else if (loc1_ptr == loc2_ptr) return false;
       else if ((loc1_ptr == -1 && loc2_ptr != -1) || (loc1_ptr != -1 && loc2_ptr == -1)) {
          if(loc1_ptr > loc2_ptr) vecset[loc1_ptr].insert(loc2);
          else if (loc2_ptr > loc1_ptr) vecset[loc2_ptr].insert(loc1);
          return true;
       }
       else {
         //cout << "Before Resizing: " << vecset.size() << endl;
         //cout << "Seriusly Fk me" << endl;
         //unordered_set<location, MyHashFunction> tempset = vecset[min(loc1_ptr, loc2_ptr)];
         //tempset.insert(vecset[max(loc1_ptr, loc2_ptr)].begin(), vecset[max(loc1_ptr, loc2_ptr)].end());
         //cout << "Before Deletion: " << tempset.size() << endl;
         vecset[min(loc1_ptr, loc2_ptr)].insert(vecset[max(loc1_ptr, loc2_ptr)].begin(), vecset[max(loc1_ptr, loc2_ptr)].end());
         vecset.erase(vecset.begin()+max(loc1_ptr, loc2_ptr), vecset.begin()+max(loc1_ptr, loc2_ptr)+1);
         //vecset.erase(vecset.begin()+min(loc1_ptr, loc2_ptr), vecset.begin()+min(loc1_ptr, loc2_ptr)+1);
         //cout << "After Deletion: " << tempset.size() << endl;
         //vecset.push_back(tempset);
         //cout << "After Resizing: " << vecset.size() << endl;
       }
       //cout << "Stage3 Level2: Crossed " << endl;
       return true;
    }
};

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  vector<ds> vec;   
  for (int i = 0; i<x.size();i++){
     for (int j = i; j<x.size();j++){
        if (i==j) continue;
        else
        {
          vec.push_back(ds(location(x[i],y[i]), location(x[j],y[j])));
        } 
     }
  }

  //cout << "Stage1_Crossed" << endl;

  disjointSet disjSet;

  priority_queue<ds, vector<ds>, Comparedis> pq(vec.begin(), vec.end());

  //cout << "Stage2_Crossed" << endl;

  int numEdgesReq = x.size()-1;
  int num=0;
  
  while(num<numEdgesReq) {
    ds ds_top = pq.top();
    pq.pop();
    
    if(disjSet.find(ds_top.loc1, ds_top.loc2)) {
      //ds_top.print();
      num++;
      result += (double)ds_top.dis;
    }
  }
  
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
