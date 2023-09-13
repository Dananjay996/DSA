class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        vector<int> candies(ratings.size());
        fill(candies.begin(), candies.end(),1);

        for(int i=1; i<ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1]+1;
            }
        }

        for(int i=ratings.size()-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i],candies[i+1]+1);
            }
        }

        for(int n:candies){
            sum += n;
        }

        return sum;
    }
};
