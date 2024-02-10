//#include <bits/stdc++.h>
//
//using namespace std;
//
//void radix_sort(vector<pair<pair<int,int>,int>> &v){
//    int n = v.size();
//    {
//        vector<int> cnt(n);
//        for(auto &a : v){
//            cnt[a.first.second]++;
//        }
//        vector<pair<pair<int,int>,int>> v_new(n);
//        vector<int> pos(n);
//        pos[0] = 0;
//        for(int i=1; i<n; i++){
//            pos[i] = pos[i-1] + cnt[i-1];
//        }
//
//        for(int i=0; i<n; i++){
//            v_new[pos[v[i].first.second]] = v[i];
//            pos[v[i].first.second]++;
//        }
//
//        v = v_new;
//    }
//    {
//       vector<int> cnt(n);
//        for(auto &a : v){
//            cnt[a.first.first]++;
//        }
//        vector<pair<pair<int,int>,int>> v_new(n);
//        vector<int> pos(n);
//        pos[0] = 0;
//        for(int i=1; i<n; i++){
//            pos[i] = pos[i-1] + cnt[i-1];
//        }
//
//        for(int i=0; i<n; i++){
//            v_new[pos[v[i].first.first]] = v[i];
//            pos[v[i].first.first]++;
//        }
//
//        v = v_new;
//    }
//}
//
//int main(){
//    string s;
//    cin >> s;
//    s += '$';
//    int n = s.length();
//    vector<int> p(n), c(n);
//
//    {
//        // k = 0
//        vector<pair<char,int>> v(n);
//        for(int i=0; i<n; i++) v[i] = {s[i],i};
//        sort(v.begin(), v.end());
//        for(int i=0; i<n; i++) p[i] = v[i].second;
//
//        c[p[0]] = 0;
//        for(int i=1; i<n; i++){
//           if(v[i].first == v[i-1].first) {
//            c[p[i]] = c[p[i-1]];
//           }else{
//            c[p[i]] = c[p[i-1]] + 1;
//           }
//        }
//    }
//
//    /// Now for other K's
//    int k = 0;
//    while((1 << k) < n){
//        // k -> k+1
//        vector<pair<pair<int,int>,int>> v(n);
//        for(int i=0; i<n; i++){
//            v[i] = {{c[i],c[(i + (1 << k))%n]},i};
//        }
//        radix_sort(v);
//        for(int i=0; i<n; i++) p[i] = v[i].second;
//
//        c[p[0]] = 0;
//        for(int i=1; i<n; i++){
//           if(v[i].first == v[i-1].first) {
//            c[p[i]] = c[p[i-1]];
//           }else{
//            c[p[i]] = c[p[i-1]] + 1;
//           }
//        }
//        k++;
//    }
//
//    for(int i=0; i<n; i++){
//        cout << p[i] << " ";
//    }
//    cout << '\n';
//}
