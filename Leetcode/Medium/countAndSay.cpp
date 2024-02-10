class Solution {
public:
    string countAndSayCustom(int n, int curr,string currString){
        if(curr == n) return currString;
        string newCurrString = "";
        char prevChar = currString[0];
        int currCharCount = 1;
        for(int i=1; i<currString.size(); i++){
            if(currString[i] == prevChar){
                currCharCount++;
            }else{
                newCurrString += to_string(currCharCount) + string(1,prevChar);
                currCharCount = 1;
                prevChar = currString[i];
            }
        }

        newCurrString += to_string(currCharCount) + string(1,prevChar);
        return countAndSayCustom(n,curr+1,newCurrString);
    }
    string countAndSay(int n) {
        return countAndSayCustom(n,1,"1");
    }
};
