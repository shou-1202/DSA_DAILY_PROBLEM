class Solution {
public:
    string processStr(string s) {
        string result = "";
        if(s.length()==1 && (s[0]=='*' || s[0] == '#'||s[0]=='%'))return result;
        if(s.length()==1 && isalpha(s[0]))return s;
        int n = s.length();

        for(int i = 0;i<n;i++){
            if(isalpha(s[i])){
                result += s[i];
            }
            else if(s[i]=='*' && !result.empty()){
                result.pop_back();
            }
            else if(s[i]=='#' && !result.empty()){
                result+=result;
            }
            else{
                if(!result.empty()){
                    reverse(result.begin(), result.end());
                }
            }
        }
        return result;
    }
};