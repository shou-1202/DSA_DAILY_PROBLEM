class Solution {
public:
    int helper(int n, unordered_map<int, int>& dp){
        if(n==0)return 0;
        if(n==1)return 1;
        if(dp.find(n) != dp.end())return dp[n];
        int two = 1e9, three = 1e9;
        two = (n%2)+1+helper(n/2, dp);
        three = (n%3)+1+helper(n/3, dp);
        
        return dp[n] = min(two, three);
    }
    int minDays(int n) {
        unordered_map<int, int>dp;
        return helper(n, dp);
    }
};