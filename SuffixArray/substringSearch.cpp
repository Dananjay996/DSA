#include <bits/stdc++.h>

using namespace std;

void radix_sort(vector<pair<pair<int,int>,int>> &a){
    int n = a.size();
    {
        vector<int> cnt(n);
        for(int i=0; i<n; i++) cnt[a[i].first.second]++;

        vector<int> pos(n);
        vector<pair<pair<int,int>,int>> a_new(n);

        pos[0] = 0;
        for(int i=1; i<n; i++){
            pos[i] = pos[i-1] + cnt[i-1];
        }

        for(int i=0; i<n; i++){
            int value = a[i].first.second;
            a_new[pos[value]] = a[i];
            pos[value]++;
        }
        a = a_new;
    }
    {
        vector<int> cnt(n);
        for(int i=0; i<n; i++) cnt[a[i].first.first]++;

        vector<int> pos(n);
        vector<pair<pair<int,int>,int>> a_new(n);

        pos[0] = 0;
        for(int i=1; i<n; i++){
            pos[i] = pos[i-1] + cnt[i-1];
        }

        for(int i=0; i<n; i++){
            int value = a[i].first.first;
            a_new[pos[value]] = a[i];
            pos[value]++;
        }
        a = a_new;
    }
}

void solve(string p, vector<int> &parr,string s,int l, int r){
    int len = p.length();
//    int n = parr.size()-1;
//    for(const int& num : parr){
//        if(n - num < l){
//            continue;
//        }
//        if(p == s.substr(num,l)){
//            cout << "Yes" << '\n';
//            return;
//        }
//    }
//    cout << "No" << '\n';
//    return;

    while (l <= r) {
        int mid = l + (r-l)/2;
        int index = parr[mid];
        string suffix = s.substr(index,len);
        if(suffix == p){
            cout << "Yes" << '\n';
            return;
        }
        bool value = lexicographical_compare(p.begin(),p.end(),suffix.begin(),suffix.end());
        if(value){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << "No" << '\n';
}

vector<int> suffixArray(string &s){
    int n = s.length();
    vector<int> p(n),c(n);
    {
        vector<pair<char,int>> v(n);
        for(int i=0; i<n; i++) v[i] = {s[i],i};
        sort(v.begin(),v.end());

        for(int i=0; i<n; i++) p[i] = v[i].second;
        c[p[0]] = 0;
        for(int i=1; i<n; i++){
            if(v[i].first == v[i-1].first){
                c[p[i]] = c[p[i-1]];
            }else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }

    int k = 0;
    while((1 << k) < n){
        vector<pair<pair<int,int>,int>> a(n);
        for(int i=0; i<n; i++) a[i] = {{c[i],c[(i + (1 << k))%n]} , i};

        radix_sort(a);

        for(int i=0; i<n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i=1; i<n; i++){
            if(a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            }else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
        k++;
    }

    return p;
}

int main(){
    string s;
    cin >> s;

    vector<int> parr = suffixArray(s);
    int t;
    cin >> t;
    while(t--){
        string p;
        cin >> p;
        solve(p,parr,s,0,parr.size()-1);
    }

    return 0;
}
