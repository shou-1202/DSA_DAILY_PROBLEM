class Solution {
public:
    int helper(vector<int>& boxes, int i, int j, int k, vector<vector<vector<int>>>& dp){
        if(i>j)return 0;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int orig_i = i;
        int orig_k = k;
        while(i<j && boxes[i] == boxes[i+1]){
            i++;k++;
        }
        int choice1 = -1e9;
        choice1 = (k+1)*(k+1) + helper(boxes, i+1, j, 0, dp);
        for(int m = i+1; m<=j; m++){
            if(boxes[i]==boxes[m]){
                int missionA = helper(boxes, i+1, m-1, 0, dp);
                int missionB = helper(boxes, m, j, k+1, dp);

                choice1 = max(missionA+missionB, choice1);

                
            }
        }
        return dp[orig_i][j][orig_k] = choice1;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return helper(boxes, 0, boxes.size()-1, 0, dp);
    }
};