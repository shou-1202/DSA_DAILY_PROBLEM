class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maximum(n, -1e9), minimum(n, 1e9);
        maximum[0] = nums[0];
        for(int i = 1; i<n; i++){
            maximum[i] = max(nums[i], maximum[i-1]);
        }
        minimum[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            minimum[i] = min(minimum[i+1], nums[i]);
        }

        int idx = INT_MAX, score = INT_MAX;
        for(int i = 0; i<n; i++){
            int temp = maximum[i] - minimum[i];
            if(temp<score && temp<=k){
                score = temp;
                idx = min(idx, i);
            }
        }
        if(idx == INT_MAX)return -1;
        return idx;
    }
};