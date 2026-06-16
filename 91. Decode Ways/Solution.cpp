class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==1 && s[0]=='0')return 0;
        if(s.length()==1)return 1;
        
        int n = s.length();
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        if(s[0]!='0'){
            dp[1] = 1;
        }
        else{
            dp[1] = 0;
        }
        string a;
        int num;
        for(int i = 2; i<=n;i++){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }

            a = s.substr(i-2, 2);
            num = stoi(a);
            if(num>=10 && num<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};