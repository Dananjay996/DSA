class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int rc = 0,lc = 0,uc = 0;
        for(char c : moves){
            if(c == 'R') rc++;
            if(c == 'L') lc++;
            if(c == '_') uc++;
        }
        return abs(lc-rc)+uc;
    }
};