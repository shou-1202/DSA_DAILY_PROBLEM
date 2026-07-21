class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 1; i<n;i++){
            for(int j = 0;j<m;j++){
                int p = INT_MAX;
                for(int k = 0; k<m;k++){
                    if(k==j)continue;
                    p = min(p, grid[i][j]+grid[i-1][k]);
                }
                grid[i][j] = p;
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i<m; i++){
            ans = min(ans, grid[n-1][i]);
        }

        return ans;
    }
};