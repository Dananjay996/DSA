class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);

        dp[0] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j*j <= i; j++){
                dp[i] = min(dp[i],1+dp[i-j*j]);
            }
        }

        return dp[n];
    }
};


// Any natural number can be expressed as a sum of 4 perfect squares

