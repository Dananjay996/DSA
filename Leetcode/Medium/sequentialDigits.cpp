class Solution {
// 6 7 8
// 7 8 9
// 8 9 10 -> Not valid
public:
    vector<int> sequentialDigits(int low, int high) {
        int leftDigits = to_string(low).length(), rightDigits = to_string(high).length();

        vector<int>answer;

        for(int digitLength = leftDigits; digitLength <= rightDigits; digitLength++){
            for(int i=1; i<10; i++){
                if(i + digitLength > 10){
                    break;
                }
                int num = i;
                for(int val = 1; val < digitLength; val++){
                    int digit = num%10 + 1;
                    num *= 10;
                    num += digit;
                }
                if(low <= num && num <= high){
                    answer.push_back(num);
                }
            }
        }

        return answer;
    }
};
