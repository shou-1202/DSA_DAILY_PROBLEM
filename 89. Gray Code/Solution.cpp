class Solution {
public:

    vector<int> grayCode(int n) {
        if(n==1){
            return {0,1};
        }
        vector<int>temp = grayCode(n-1);
        vector<int>ans = temp;
        reverse(temp.begin(), temp.end());
        int a = pow(2, n-1);
        for(int i = 0; i<temp.size();i++){
            ans.push_back(temp[i] + a); 
        }
        return ans;
    }
};