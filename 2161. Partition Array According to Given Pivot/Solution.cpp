class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        if(nums.size()==1)return nums;
        vector<int>left;
        vector<int>right;
        vector<int>mid;
        for(int i: nums){
            if(i <pivot){
                left.push_back(i);
            }
            else if(i > pivot){
                right.push_back(i);
            }
            else{
                mid.push_back(i);
            }
        }
        left.insert(left.end(), mid.begin(), mid.end());
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};