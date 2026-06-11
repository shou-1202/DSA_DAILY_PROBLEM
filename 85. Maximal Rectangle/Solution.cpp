class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int>heights(n+1, 0);
        int ans = 0;
        int width;
        stack<int>s;
        for(int row = 0; row<matrix.size();row++){
            for(int col = 0; col<matrix[0].size();col++){
                if(matrix[row][col] == '0'){
                    heights[col] = 0;
                }
                else{
                    heights[col]++;
                }
            }
            for(int i = 0;i<heights.size();i++){
                if(s.empty()){
                    s.push(i);
                }
                else{
                    if(heights[i]>=heights[s.top()]){
                        s.push(i);
                    }
                    else{
                        while(!s.empty() && heights[i]<heights[s.top()]){
                            int index = s.top();
                            s.pop();
                            if(!s.empty()){
                                width = i - s.top() - 1;
                            }
                            else{
                                width = i;
                            }
                            ans = max(ans, width*heights[index]);
                        }
                        s.push(i);
                    }
                }
            }
            while(!s.empty()){
                s.pop();
            }
        }
        return ans;
    }
};