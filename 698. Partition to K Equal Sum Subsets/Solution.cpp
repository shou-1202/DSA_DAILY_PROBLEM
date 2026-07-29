class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        // If total sum is not divisible by k, it's impossible
        if (totalSum % k != 0) return false;
        
        int subsetSum = totalSum / k;
        int n = nums.size();
        
        // OPTIMIZATION 1: Sort in descending order. 
        // Placing larger numbers first drastically prunes the recursion tree 
        // because they have fewer valid combinations.
        sort(nums.rbegin(), nums.rend());
        
        // If the largest single element is greater than the target, it's impossible
        if (nums[0] > subsetSum) return false;
        
        // dp array initialized to -1. Size is 2^n.
        // dp[mask] = 1 means true, dp[mask] = 0 means false, -1 means uncalculated.
        vector<int> dp(1 << n, -1);
        
        return memoize(nums, 0, 0, subsetSum, dp);
    }
    
private:
    bool memoize(vector<int>& nums, int mask, int currentSum, int subsetSum, vector<int>& dp) {
        int n = nums.size();
        
        // Base case: When the mask is all 1s (e.g., 111111 for n=6), all elements are used.
        if (mask == (1 << n) - 1) return true;
        
        // If we have already calculated this exact state of visited elements, return the cached result.
        if (dp[mask] != -1) return dp[mask] == 1;
        
        for (int i = 0; i < n; i++) {
            // Check if the i-th bit is NOT set (meaning nums[i] is unused)
            if (!(mask & (1 << i))) {
                
                // If we can add this number without exceeding the target
                if (currentSum + nums[i] <= subsetSum) {
                    
                    // If the sum hits subsetSum, we wrap it back to 0 for the next subset.
                    int nextSum = (currentSum + nums[i]) % subsetSum;
                    
                    // Recursively call with the i-th bit turned ON using Bitwise OR (|)
                    if (memoize(nums, mask | (1 << i), nextSum, subsetSum, dp)) {
                        return dp[mask] = 1;
                    }
                }
            }
        }
        
        // If no combination works from this state, cache it as false (0)
        dp[mask] = 0;
        return false;
    }
};