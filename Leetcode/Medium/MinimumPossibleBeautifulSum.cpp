class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        set<int> s;

        long long ans = 0;

        for(int i=1;s.size()<n;i++){
            if(s.find(target-i) == s.end()){
                s.insert(i);
                ans += i;
            }
        }

        return ans;
    }
};