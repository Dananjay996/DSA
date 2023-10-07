#include <iostream>
#include <vector>


struct segmentTree{
  int size;
  std::vector<long long> arr;

  void init(int n){
    size = 1;
    while(size < n) size *= 2;
    arr.assign(2*size, 0LL);
  }

  void set(int i, int v, int x, int lx, int rx){
    if(rx - lx == 1){
      arr[x] = v;
      return;
    }
    int m = (lx+rx)/2;
    if(i < m){
      set(i, v, 2*x +1, lx, m);
    }else{
      set(i, v, 2*x +2, m, rx);
    }

    arr[x] = arr[2*x + 1] + arr[2*x + 2];
  }

  void set(int i, int v){
    set(i, v, 0, 0, size);
  }

  long long sum(int l, int r, int x, int lx, int rx){
    if(l >= rx || r <= lx) return 0LL;
    if(r >= rx && l <= lx) return arr[x];

    int mid = (lx + rx)/2;
    return sum(l,r,2*x+1,lx,mid) + sum(l,r,2*x+2,mid,rx);
  }

  long long sum(int l, int r){
    return sum(l,r,0,0,size);
  }

  
};

int main(){
  
  int n,m;
  std::cin >> n >> m;
  segmentTree st;
  st.init(n);
  for(int i=0; i<n; i++){
    int v;
    std::cin >> v;
    st.set(i,v);
  }
  while(m--){
    int op; 
    std::cin >> op;
    if(op == 1){
      int i,v;
      std::cin >> i >> v;
      st.set(i,v);
    }else{
      int l,r;
      std::cin >> l >> r;
      std::cout << st.sum(l,r) << '\n';
    }
  }
}
