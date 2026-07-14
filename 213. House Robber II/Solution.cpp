class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>temp1;
        vector<int>temp2;
        for(int i = 0; i<n;i++){
            if(i==0){
                temp1.push_back(nums[i]);
            }
            else if(i==n-1){
                temp2.push_back(nums[i]);
            }
            else{
                temp1.push_back(nums[i]);
                temp2.push_back(nums[i]);
            }
        }
        int prev2 = temp1[0];
        int prev = temp1[0];
        int ans = 0;
        for(int i = 1; i<temp1.size(); i++){
            int pick = temp1[i];
            if(i>1)pick += prev2;
            int nonPick = prev;
            ans = max(pick, nonPick);
            prev2 = prev;
            prev = ans;
        }
        prev2 = temp2[0];
        int prev3 = temp2[0];
        for(int i = 1;i<temp2.size();i++){
            int pick = temp2[i];
            if(i>1)pick += prev2;
            int nonPick = prev3;
            ans = max(pick, nonPick);
            prev2 = prev3;
            prev3 = ans;
        }
        return max(prev, prev3);
    }
};