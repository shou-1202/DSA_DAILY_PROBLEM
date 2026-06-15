class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        if(strs.size()==1 || (strs.size()==1 && strs[0].length()==0)){
            ans.push_back(strs);
            return ans;
        }
        unordered_map<string, vector<string>>m;
        for(int i =0;i<strs.size();i++){
            string original = strs[i];

            string sorted = original;
            sort(sorted.begin(), sorted.end());

            m[sorted].push_back(original);
        }
        for(const auto&it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};