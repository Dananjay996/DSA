class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.length()-1;

        while(l < r){
            if(s[l] != s[r]) break;
            char currChar = s[l];
            l++;
            int prevR = r;
            while(l <= r && s[l] == currChar)  l++;
            while(r >= l && s[r] == currChar) r--;
            
            if(r == prevR) return prevR - l+1;
        }

        cout << "Reached";

        return r - l+1;
    }
};
