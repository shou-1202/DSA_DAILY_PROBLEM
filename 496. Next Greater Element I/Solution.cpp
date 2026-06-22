class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int p = nums1.size();
        stack<int>s;
        unordered_map<int, int>m;
        for(int i = 0; i<n;i++){
            while(!s.empty() && s.top() <nums2[i]){
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while(!s.empty()){
            m[s.top()] = -1;
            s.pop();
        }
        for(int i = 0; i<p;i++){
            if(m.find(nums1[i]) != m.end()){
                nums1[i] = m[nums1[i]];
            }
        }
        return nums1;
    }
};