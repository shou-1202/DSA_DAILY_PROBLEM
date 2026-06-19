class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>dp(rowIndex+1, vector<int>(rowIndex+1, 0));
        for(int i=0; i<=rowIndex;i++){
            dp[i][0] = 1;
        }

        for(int i =1; i<=rowIndex; i++){
            for(int j=1;j<=rowIndex;j++){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
        vector<int>ans;
        int i = 0;
        while(i<=rowIndex){
            ans.push_back(dp[rowIndex][i]);
            i++;
        }
        return ans;
    }
};