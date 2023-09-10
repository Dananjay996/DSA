class Solution {
public:
    int countOrders(int n) {
        long ans = 1;
        while(2*n>0){
            long val = (2*n*(2*n-1))/2;
            ans = (ans*val)%(int((1e9+7)));
            n -= 1;
        }
        return int(ans);
    }
};