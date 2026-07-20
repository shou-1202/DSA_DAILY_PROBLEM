class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n);
        for(int i = 0; i<n; i++){
            dp[i] = vector<int>(i+1, -1);
        }
        dp[0][0] = triangle[0][0];
        for(int i=1; i<n; i++){
            for(int j = 0; j<triangle[i].size(); j++){
                long long k = 0;
                if(j<0 || j>=triangle[i-1].size()){
                    k = INT_MAX;
                }
                else{
                    k = dp[i-1][j]+triangle[i][j];
                }
                long long p = 0;
                if(j>0 && j<= triangle[i-1].size()){
                    p = dp[i-1][j-1] + triangle[i][j];
                }
                else{
                    p = INT_MAX;
                }
                dp[i][j] = min(k, p);
            }
        }
        long long ans = INT_MAX;
        for(int k = 0; k<n; k++){
            long long res = dp[n-1][k];
            ans = min(res, ans);
        }
        return (int)ans;
    }
};