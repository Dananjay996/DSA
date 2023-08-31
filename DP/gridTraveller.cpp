#include <bits/stdc++.h>
using namespace std;

long gridTravellerDP(int m, int n, vector<vector<long>> &dp){
    if(n == 0 || m == 0) return 0;
    if(n == 1 && m == 1) return 1;

    if(dp[m][n] != 0) return dp[m][n];

    dp[m][n] = gridTravellerDP(m-1, n,dp) + gridTravellerDP(m, n-1,dp);
    return dp[m][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int m,n;
    cin >> m >> n;

    vector<vector<long>> dp(m+1, vector<long>(n+1, 0));
    long numberOfWays = gridTravellerDP(m,n,dp);
    cout << numberOfWays << endl;
    return 0;
}

