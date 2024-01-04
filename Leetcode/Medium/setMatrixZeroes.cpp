class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> idxs = vector<vector<int>>(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    idxs[i][j]++;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(idxs[i][j]){
                    vector<int> c(m,0);
                    matrix[i] = c;
                    for(int k=0; k<n; k++){
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
};
