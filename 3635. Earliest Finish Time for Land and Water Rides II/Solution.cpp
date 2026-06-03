class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int result_land = INT_MAX;
        int result_water = INT_MAX;
        int ans = 0;
        int n = landStartTime.size();
        int earliest_land_time = INT_MAX;
        int earliest_water_time = INT_MAX;
        for(int i=0;i<n;i++){
            earliest_land_time = min(earliest_land_time, landStartTime[i]+landDuration[i]);
        }
        int m = waterStartTime.size();
        ans+=earliest_land_time;
        for(int i = 0; i<m;i++){
            ans = earliest_land_time;
            if(waterStartTime[i]<=earliest_land_time){
                ans = ans+waterDuration[i];
                result_land = min(result_land, ans);
            }
            else{
                ans = waterDuration[i]+waterStartTime[i];
                result_land = min(result_land, ans);
            }
        }
        for(int i=0;i<m;i++){
            earliest_water_time = min(earliest_water_time, waterStartTime[i]+waterDuration[i]);
        }
        for(int i = 0; i<n;i++){
            ans = earliest_water_time;
            if(landStartTime[i]<=earliest_water_time){
                ans = ans+landDuration[i];
                result_water = min(result_water, ans);
            }
            else{
                ans = landDuration[i]+landStartTime[i];
                result_water = min(result_water, ans);
            }
        }
        return min(result_land, result_water);
    }
};