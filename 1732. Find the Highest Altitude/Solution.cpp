class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        highest = max(gain[0], highest);
        for(int i = 1;i<gain.size();i++){
            gain[i] += gain[i-1];
            highest = max(gain[i], highest); 
        }
        return highest;
    }
};