class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        
        // Binary search on the value range
        while (low < high) {
            // Avoids potential integer overflow compared to (low + high) / 2
            int mid = low + (high - low) / 2; 
            
            if (countLessOrEqual(matrix, mid, n) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
    
private:
    int countLessOrEqual(const vector<vector<int>>& matrix, int mid, int n) {
        int count = 0;
        int c = 0;
        int r = n - 1;
        
        // Start from the bottom-left corner
        while (r >= 0 && c < n) {
            if (matrix[r][c] <= mid) {
                // If current is <= mid, everything above it is also <= mid
                count += (r + 1);
                c++; // Move right
            } else {
                r--; // Move up
            }
        }
        
        return count;
    }
};