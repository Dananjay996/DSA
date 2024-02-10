class Solution {
public:
    map<int,int> dp;
    int dfs(int index, vector<int>& arr, int k){
        if(index >= arr.size()){
            return 0;
        }

        try{
            int value = dp.at(index);
            return value;
        }catch(const std::out_of_range& e){
            // Do nothing...
        }

        int currMax = 0, res = INT_MIN;
        int minv = min(int(arr.size()),index+k);
        for(int j=index; j < minv;j++){
            int windowSize = j - index + 1;
            currMax = max(currMax,arr[j]);
            
            res = max(res,currMax * windowSize + dfs(j+1,arr,k));
        }
        dp[index] = res;
        return res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return dfs(0,arr,k);
    }
};
