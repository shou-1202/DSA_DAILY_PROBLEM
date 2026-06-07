class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length())return "";
        unordered_map<char, int>m;
        for(char c: t){
            if(m.find(c)==m.end()){
                m[c] = 1;
            }
            else{
                m[c] += 1;
            }
        }
        int need = m.size();
        int minLen = INT_MAX;
        int index;
        int have = 0, left = 0;
        unordered_map<char,int>local;
        for(int i = 0; i<s.length();i++){
            local[s[i]]++;

            if(m.find(s[i])!=m.end() && local[s[i]] == m[s[i]]){
                have++;
            }

            while(have == need){
                int len = i - left +1;
                if(len < minLen){
                    minLen = len;
                    index = left;
                }

                local[s[left]]--;
                if(m.find(s[left])!=m.end() && local[s[left]] < m[s[left]]){
                    have--;
                }

                left++;
            }

        }
        return minLen == INT_MAX ? "" : s.substr(index, minLen);
    }
};