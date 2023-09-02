#include <bits/stdc++.h>
using namespace std;

bool checkStrings(string s1, string s2) {
    unordered_map<char,int> s1Oddmp, s1Evenmp, s2Oddmp, s2Evenmp;

    for(int i=0; i<s1.length(); i++){
        if(i%2){
            s1Oddmp[s1[i]]++;
            s2Oddmp[s2[i]]++;
        }else{
            s1Evenmp[s1[i]]++;
            s2Evenmp[s2[i]]++;
        }
    }

    return (s1Oddmp == s2Oddmp) && (s1Evenmp == s2Evenmp);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin>>s1>>s2;

    cout << boolalpha << checkStrings(s1,s2) << endl;    

    return 0;
}