class Solution {
public:
    int minOperations(vector<int>& nums) {
       map<int,int> mp;

       for(int n : nums){
           mp[n]++;
       }

       int minOps = 0;

       for(auto& pair : mp){
           while(pair.second > 0){
               if(pair.second == 1) return -1;

                if(pair.second - 3 != 1){
                    minOps++;
                    pair.second -= 3;
                }else{
                    pair.second -= 2;
                    minOps++;
                }
           }
       }

       cout << minOps << endl;

       return minOps;
    }
}
