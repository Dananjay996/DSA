#include <bits/stdc++.h>
using namespace std;

deque<deque<string>> allConstruct(deque<string> words, string target){
    if(target == "") return {{}};

    deque<deque<string>> result;

    for(string w : words){
        if(target.find(w) == 0){
            string suffix = target.substr(w.length());
            deque<deque<string>> suffixWays = allConstruct(words, suffix);
            for(deque<string> way : suffixWays){
                way.push_front(w);
                result.push_back(way);
            }
        }
    }

    return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<string> words;
    string target;
    int n;

    cin >> target >> n;
    words.resize(n);
    for(int i=0; i<n; i++) cin >> words[i];

    deque<deque<string>> answer = allConstruct(words, target);

    sort(answer.begin(), answer.end(), [](deque<string> a, deque<string> b){
        return a.size() < b.size();
    });

    for(deque<string> way : answer){
        for(string w : way) cout << w << " ";
        cout << endl;
    }    

    return 0;
}