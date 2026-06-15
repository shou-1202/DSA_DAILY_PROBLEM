class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int i = 0;
        bool seeDecimal = false, seeExponent = false, seeDigit = false;
        for(i; i<s.length();i++){
            if(s[i] >= '0' && s[i] <= '9'){
                seeDigit = true;
                continue;
            }
            else if(s[i] == '+' || s[i] == '-'){
                if(i==0 || s[i-1] == 'e' || s[i-1]=='E'){
                    
                    continue;
                }
                else{
                    return false;
                }
            }
            else if(s[i] == '.'){
                if(seeDecimal  || seeExponent){
                    return false;
                }

                seeDecimal = true;
            }
            else if((s[i] == 'e' || s[i] == 'E')){
                if(seeExponent || !seeDigit){
                    return false;
                }
                seeDigit = false;
                seeExponent = true;
            }
            else{
                return false;
            }
        }
        return seeDigit;
    }
};