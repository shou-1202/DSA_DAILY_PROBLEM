class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        for(int i =0;i<landStartTime.size();i++){
            for(int j = 0;j<waterStartTime.size();j++){
                int temp = 0;
                if(landStartTime[i]<=waterStartTime[j]){
                   temp = landStartTime[i]+landDuration[i];
                   if(waterStartTime[j] <= temp){
                    temp += waterDuration[j];
                   }
                   else{
                    temp += (waterStartTime[j] - temp);
                    temp+= waterDuration[j];
                   }
                   ans = min(ans, temp);
                }
                else{
                   temp = waterStartTime[j]+waterDuration[j];
                   if(landStartTime[i] <= temp){
                    temp += landDuration[i];
                   }
                   else{
                    temp += (landStartTime[i] - temp);
                    temp+= landDuration[i];
                   }
                   ans = min(ans, temp);
                }
            }
        }
        return ans;
    }
};