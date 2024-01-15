class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int,int> PlayersWon;
        map<int,int> PlayersLost;

        for(auto v : matches){
            PlayersWon[v[0]]++;
            PlayersLost[v[1]]++;
        }

        for(auto val : PlayersWon){
            if(PlayersLost.find(val.first) == PlayersLost.end()){
                ans[0].push_back(val.first);
            }
        }

        for(auto val : PlayersLost){
            if(val.second == 1){
                ans[1].push_back(val.first);
            }
        }

        return ans;

    }
};
