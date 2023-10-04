#include <bits/stdc++.h>

struct segmentTree{
  int size;
  std::vector<long long> arr;

  void init(int n){
    while(size < n) size *= 2;
    arr.assign(2*size, 0);
  }

  void set(int i, int v){

  }

  
};

int main(){
  
  segmentTree st;
  int n;
  std::cin >> n;
  for(int i=0; i<n; i++){
    int v;
    std::cin >> v;
    st.set(i,v);
  }
}
