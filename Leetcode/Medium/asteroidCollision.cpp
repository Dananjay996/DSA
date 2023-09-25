class Solution {
public:
    bool diff(int a,int b){
        return ((a>0&&b<0));
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int,vector<int>> answer;
        int flg = 0;

        for(int n:asteroids){
            while(!answer.empty() && diff(answer.top(),n)){
                // if(answer.top() < 0){
                //     break;
                // }
                int v = answer.top();
                answer.pop();
                if(abs(v) > abs(n)){
                    answer.push(v);
                    flg = 1;
                    break;
                }
                if(abs(v) == abs(n)){
                    flg = 1;
                    break;
                }
            }
            if(!flg){
                answer.push(n);
            }
            flg = 0;
        }

        int *end = &answer.top()+1;
        int *begin = end - answer.size();

        vector<int> ans(begin,end);

        return ans; 
    }
};