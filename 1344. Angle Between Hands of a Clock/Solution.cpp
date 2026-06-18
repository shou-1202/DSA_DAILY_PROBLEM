class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12 && minutes == 0)return 0;
        double ans = 0;
        if(minutes == 0){
            if(hour<=6){
                ans = hour*30;
            }
            else{
                ans = (12-hour)*30;
            }
            return ans;
        }
        double travelByHourHand = ((double(minutes)/12)*6)+(30*hour);
        double travelByMinuteHand = minutes*6;

        ans = abs(travelByHourHand - travelByMinuteHand);
        if(ans>180){
            return 360-ans;
        }
        return ans;
        
    }
};