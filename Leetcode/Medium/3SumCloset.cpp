class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3){
            return -1;
        }

        sort(nums.begin(),nums.end());
        int diff = INT_MAX,ans;

        for(int i=0; i<nums.size()-2; i++){
            int j = i+1, k = nums.size()-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum-target) < diff){
                    diff = abs(sum-target);
                    ans = sum;
                }

                if(sum > target) k--;
                else j++;
            }
        }

        return ans;
    }
};
