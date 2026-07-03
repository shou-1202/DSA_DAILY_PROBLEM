class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length())return "0";
        if(num.length()==1)return "0";
        string ans = "";
        for(char c:num){
            while(ans.length()>0 &&  k>0 && ans.back()>c){
                ans.pop_back();
                k--;
            }
            if(ans.length()>0 || c!='0'){
                ans.push_back(c);
            }
        }
        while(k>0 && ans.length()>0){
            ans.pop_back();
            k--;
        }
        return ans.empty() ? "0": ans;
    }
};