class Solution {
public:
    bool isPalindrome(string_view s){
        int left = 0, right = s.length()-1;
        while(left<right){
            if(s[left++]!=s[right--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string_view, int>m;
        vector<vector<int>>ans;

        for(int i = 0; i<words.size();i++){
            m[words[i]] = i;
        }

        for(int i = 0;i<words.size();i++){
            string_view word = words[i];
            for(int j = 0;j<=word.length();j++){
                string_view prefix = word.substr(0,j);
                string_view suffix = word.substr(j);

                if(isPalindrome(prefix)){
                    string revSuffix(suffix.rbegin(), suffix.rend());

                    if(m.find(revSuffix)!=m.end() && m[revSuffix]!=i){
                        ans.push_back({m[revSuffix], i});
                    }
                }
                if(j!=words[i].length() && isPalindrome(suffix)){
                    string revPrefix(prefix.rbegin(), prefix.rend());

                    if(m.find(revPrefix)!=m.end() && m[revPrefix]!=i){
                        ans.push_back({i, m[revPrefix]});
                    }
                }
            }
        }
        return ans;
    }
};