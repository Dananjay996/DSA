#include <bits/stdc++.h>
using namespace std;

int canSum(vector<int>& array, int target, vector<int>& dp){
    if(target == 0) return 1;
    if(target < 0) return 0;

    if(dp[target] != -1) return dp[target];

    for(int num : array){
        int remainder = target - num;
        dp[target] = canSum(array, remainder, dp);
        if(dp[target]) return 1;
    }


    dp[target] = 0;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,target;
    cin >> n;
    vector<int> array(n);
    for(int i=0; i<n; i++) cin >> array[i];
    cin >> target;

    vector<int> dp(target+1, -1);

    bool canSumTarget = canSum(array, target, dp);

    //output as boolean
    cout << boolalpha << canSumTarget << endl;

    exit(0);
    return 0;
}