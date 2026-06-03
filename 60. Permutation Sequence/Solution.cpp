class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums(n);
        for(int i = 0; i<n;i++){
            nums[i] = i+1;
        }
        string ans = "";
        int i = n-2;
        int count = 1;
        while(count<k){
            while(i>=0 && nums[i]>nums[i+1]){
               i--;
            }
            if(i>=0){
               int j = n-1;
               while(nums[j]<nums[i]){
                j--;
               }
               swap(nums[j], nums[i]);
               count+=1;
            }
            reverse(nums.begin()+i+1, nums.end());
            i = n-2;
        }
        for(int i = 0; i<n; i++){
            ans += (nums[i] + '0');
        }
        return ans;
    }
};