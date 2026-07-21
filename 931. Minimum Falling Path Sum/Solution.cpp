class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>dp(m, 0);
        for(int i = 0; i<m; i++){
            dp[i] = matrix[0][i];
        }
        for(int i = 1; i<n;i++){
            vector<int>temp(m, -1);
            for(int j = 0;j<m;j++){
                int p = INT_MAX, r = INT_MAX;
                if(j>0)p = matrix[i][j] + dp[j-1];
                int q = matrix[i][j] + dp[j];
                if(j<m-1)r = matrix[i][j] + dp[j+1];

                temp[j] = min(p, min(q, r));
            }
            dp = temp;
        }
        int ans = INT_MAX;
        for(int i = 0; i<m; i++){
            ans = min(ans, dp[i]);
        }

        return ans;
    }
};