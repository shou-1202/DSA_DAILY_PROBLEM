class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int count = INT_MAX, sum = 0;
        int left = 0, right = 0;
        while(right<n){
            sum+=nums[right];
            while(sum>=target){
                count = min(count, right-left+1);
                sum-=nums[left];
                left++;
            }
            right++;
        }
        if(count==INT_MAX)return 0;
        return count;
    }
};