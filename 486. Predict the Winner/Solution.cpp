class Solution {
public:
    bool helper(int i, int j, int score1, int score2, int player1, int player2, vector<int>& nums){
        if(i==j){
            if(player1){
                score1 += nums[i];
                return score1>=score2;
            }
            else{
                score2 += nums[i];
                return score2>=score1;
            }
        }
        int p = false, q = false;
        if(player1){
            p = helper(i+1, j, score1+nums[i], score2, 0, 1, nums);
            if(p)return true;
            q = helper(i, j-1, score1+nums[j], score2, 0, 1, nums);
            return q;
        }
        else{
            p = helper(i+1, j, score1, score2+nums[i], 1, 0, nums);
            if(!p)return false;
            q = helper(i, j-1, score1, score2+nums[j], 1, 0, nums);
            return q;
        }
        if(player2){
            return true;
        }
        return false;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return helper(0, n-1, 0, 0, 1, 0, nums);
    }
};