class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp = vector<int>(nums.size(),1);

        for(int i=nums.size()-1;i>=0;i--){
            for(int j = i+1;j<nums.size();j++){
                cout << nums[i] <<  " " << nums[j] << endl;
                if(nums[j] > nums[i]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
