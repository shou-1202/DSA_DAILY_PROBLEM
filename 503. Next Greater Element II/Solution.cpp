class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n , -1);
        if(n == 1){
            return result;
        }
        stack<int>s;
        int count = 0, i = 0;
        while(count<2*n){
            while(!s.empty() && nums[s.top()] < nums[i]){
                result[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
            i = (i+1)%n;
            count++;
        }
        return result;
    }
};