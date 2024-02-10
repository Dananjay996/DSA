#include <bits/stdc++.h>

using namespace std; 

void previousGreater(vector<int>& v){
  stack<int> s;
  vector<int> previousGreaterArray(v.size(),-1);
  for (size_t i = 0; i < v.size(); i++) {
    while(!s.empty() && v[s.top()] < v[i]){
      s.pop();
    }
    if(!s.empty()){
      previousGreaterArray[i] = s.top();
    }
    s.push(i);
  }


  for(int val : previousGreaterArray){
    if(val != -1){
      cout << v[val] << " ";
    }else{
      cout << -1 << " ";
    }
  }
  cout << endl;
}

int main(){
  vector<int> arr;
  int n;
  cin >> n;

  for (size_t i = 0; i < n; i++) {
    int v; cin >> v;
    arr.push_back(v);
  }

  previousGreater(arr);

}
