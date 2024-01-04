class Solution {
public:
    string longestPalindrome(string s) {
        string answer = "";
        int maxLen = 0;

        for(int i=0; i<s.length(); i++){
            // Odd length 
            int l = i, r = i;
            while(l >=0 && r < s.length() && s[l]==s[r]){
                if(r-l+1 > maxLen){
                    maxLen = r-l+1;
                    answer = s.substr(l,r-l+1);
                }
                l--;
                r++;
            }

            // Even length
            l = i, r = i+1;
            while(l >=0 && r < s.length() && s[l]==s[r]){
                if(r-l+1 > maxLen){
                    maxLen = r-l+1;
                    answer = s.substr(l,r-l+1);
                    cout << l << " " << r;
                }
                l--;
                r++;
            }
        }

        return answer;
    }
};