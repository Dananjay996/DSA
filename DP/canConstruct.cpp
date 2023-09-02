#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string word, vector<string> words, unordered_map<string,int>& dp){
    if(word == "") return true;
    if(dp.find(word) != dp.end()) return dp[word];

    for(string w : words){
        if(word.find(w) == 0){
            string suffix = word.substr(w.length());
            dp[suffix] = canConstruct(suffix,words,dp);
            if(dp[suffix]) return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<string,int> dp;

    string word;
    int n;
    cin >> word >> n;
    vector<string> words(n);
    for(int i=0; i<n; i++) cin >> words[i];

    cout << boolalpha << canConstruct(word, words,dp) << endl;

    return 0;
}