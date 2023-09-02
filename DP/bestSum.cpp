#include <bits/stdc++.h>
using namespace std;

vector<int> bestSum(vector<int>& array, int target){
    if(target == 0) return {};
    if(target < 0) return {-1};
    vector<int> bestCombination = {};

    for(int num : array){
        int remainder = target - num;
        vector<int> remainderCombination = bestSum(array, remainder);
        if(remainderCombination.size() > 0 && remainderCombination[0] != -1){
            vector<int> combination = remainderCombination;
            combination.push_back(num);
            if(bestCombination.size() == 0 || combination.size() < bestCombination.size()){
                bestCombination = combination;
            }
        }
    }

    for(int n : bestCombination) cout << n << " ";

    return bestCombination;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,target;
    cin >> n;
    vector<int> array(n);
    for(int i=0; i<n; i++) cin >> array[i];
    cin >> target;

    vector<int> answer = bestSum(array, target);

    for(int num : answer) cout << num << " ";

    return 0;
}