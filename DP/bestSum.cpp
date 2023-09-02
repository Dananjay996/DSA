#include <bits/stdc++.h>
using namespace std;

vector<long> bestSum(vector<long>& array, long target){
    if(target == 0) return {};
    if(target < 0) return {-1};
    vector<long> bestCombination = {};

    for(long num : array){
        long remainder = target - num;
        vector<long> remainderCombination = bestSum(array, remainder);
        if(remainderCombination.size() > 0 && remainderCombination[0] != -1){
            vector<long> combination = remainderCombination;
            combination.push_back(num);
            if(bestCombination.size() == 0 || combination.size() < bestCombination.size()){
                bestCombination = combination;
            }
        }
    }

    for(long n : bestCombination) cout << n << " ";

    return bestCombination;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long n,target;
    cin >> n;
    vector<long> array(n);
    for(long i=0; i<n; i++) cin >> array[i];
    cin >> target;

    vector<long> answer = bestSum(array, target);

    for(long num : answer) cout << num << " ";

    return 0;
}