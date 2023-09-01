class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> c(32,0);
        vector<int> t(32,0);
        int s = 0,ops = 0, j = 32;

        for(int i=0;i<nums.size(); i++){
            int x = nums[i];
            c[int(log2(x))]++;
            s += x;
        }

        for(int i=0;i<t.size()-1;i++){
            int bit = 1 << i;
            cout << bit << " " << (target&bit) << endl;

            if(target&bit){
                if(c[i]) c[i]--;
                else j = min(j,i);
            }

            if(c[i] && j < i){
                c[i]--;
                ops += i-j;
                j = 32;
            }

            c[i+1] += c[i]/2;
        }

        return j < 32 ? -1 : ops;

    }
};