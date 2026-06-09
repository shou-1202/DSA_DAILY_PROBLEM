class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0;
        int right = height.size() - 1;
        
        int left_max = 0;
        int right_max = 0;
        
        int total_water = 0;

        while (left < right) {
            // The right wall is taller, so the bottleneck is on the left
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left]; // Update max wall, no water can be trapped
                } else {
                    total_water += left_max - height[left]; // Trap water
                }
                left++;
            } 
            // The left wall is taller (or equal), so the bottleneck is on the right
            else {
                if (height[right] >= right_max) {
                    right_max = height[right]; // Update max wall
                } else {
                    total_water += right_max - height[right]; // Trap water
                }
                right--;
            }
        }
        
        return total_water;
    }
};