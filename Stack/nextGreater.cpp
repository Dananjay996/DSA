#include <bits/stdc++.h>

using namespace std; 

void nextGreater(vector<int>& v){
  stack<int> s;
  vector<int> nextGreaterArray(v.size(),0);
  for (size_t i = 0; i < v.size(); i++) {
    while(!s.empty() && v[s.top()] < v[i]){
      int val = s.top();
      s.pop();
      nextGreaterArray[val] = i;
    }
    s.push(i);
  }


  for(int val : nextGreaterArray){
    cout << val << " ";
  }
}

int main(){
  vector<int> arr;
  int n;
  cin >> n;

  for (size_t i = 0; i < n; i++) {
    int v; cin >> v;
    arr.push_back(v);
  }

  nextGreater(arr);

}
