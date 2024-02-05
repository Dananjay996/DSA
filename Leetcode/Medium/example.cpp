#include <bits/stdc++.h>
using namespace std;

bool cmp(string& s1,string& s2){
  return s1.length() > s2.length();
}

int main(){
  vector<string> v;
  int n; cin >> n;
  for(int i=0; i<n; i++){
    string s;
    cin >> s; 
    v.push_back(s);
  }
  sort(v.begin(),v.end(),cmp);
  for(string s :v){
    cout << s << '\t';
  }
  cout << endl;
}
