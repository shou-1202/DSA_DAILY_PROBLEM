class Solution {
public:
    int helper(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        if(matrix[i][j] == -1)return -1e8;
        if(dp[i][j]!=-1)return dp[i][j];

        int num = matrix[i][j];
        matrix[i][j]= -1;
        int left = 1;
        if(j>0 && num < matrix[i][j-1])left += helper(matrix, i, j-1, dp);
        int right = 1;
        if(j<matrix[i].size()-1 && num < matrix[i][j+1])right += helper(matrix, i, j+1, dp);
        int up = 1;
        if(i>0 && num < matrix[i-1][j])up += helper(matrix, i-1, j, dp);
        int down = 1;
        if(i<matrix.size()-1 && num < matrix[i+1][j])down += helper(matrix, i+1, j, dp);
        matrix[i][j]=num;

        return dp[i][j] = max(left, max(right, max(up, down)));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        vector<vector<int>>dp(m, vector<int>(n, -1));
        
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                int res = helper(matrix, i, j, dp);
                ans = max(ans, res);
            }
        }
        return ans;
    }
};