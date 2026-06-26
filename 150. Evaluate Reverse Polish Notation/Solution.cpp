class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i = 0; i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int num1 = s.top();s.pop();
                int num2 = s.top();s.pop();

                if(tokens[i] == "+"){
                    s.push(num1+num2);
                }
                else if(tokens[i]=="-"){
                    s.push(num2-num1);
                }
                else if(tokens[i] == "*"){
                    s.push(num1*num2);
                }
                else{
                    if(num1!=0){
                        s.push(num2/num1);
                    }
                }
            }
            else{
                int num = stoi(tokens[i]);
                s.push(num);
            }
        }
        return s.top();
    }
};