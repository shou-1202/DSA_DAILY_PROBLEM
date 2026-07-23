class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int TotalSum = 0;
        for(int i = 0; i<nums.size(); i++){
            TotalSum += nums[i];
        }
        if(TotalSum%2!= 0){
            return false;
        }
        int target = TotalSum/2;
        vector<int>prev(target+1, false), curr(target+1, false);
        if(nums[0]<=target)prev[nums[0]]=true;
        prev[0] = true;
        for(int i = 1; i<nums.size(); i++){
            for(int j = 1; j<=target; j++){
                curr[0] = true;
                bool notPick = prev[j];
                bool pick = false;
                if(nums[i]<=j)pick = prev[j-nums[i]];

                curr[j] = pick||notPick;
            }
            prev = curr;
        }

        return prev[target];
    }
};