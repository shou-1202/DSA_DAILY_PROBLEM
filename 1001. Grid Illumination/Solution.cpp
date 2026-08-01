#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        // Frequency maps to track how many lamps are illuminating a specific line
        unordered_map<int, int> row_cnt;
        unordered_map<int, int> col_cnt;
        unordered_map<int, int> diag1_cnt; // Main diagonal (row - col)
        unordered_map<int, int> diag2_cnt; // Anti-diagonal (row + col)
        
        // Track the exact positions of active lamps (set avoids duplicate lamps in input)
        set<pair<int, int>> active_lamps;

        // 1. Turn on the lamps
        for (const auto& lamp : lamps) {
            int r = lamp[0];
            int c = lamp[1];
            
            // Only add illumination if there isn't already a lamp at this exact spot
            if (active_lamps.insert({r, c}).second) {
                row_cnt[r]++;
                col_cnt[c]++;
                diag1_cnt[r - c]++;
                diag2_cnt[r + c]++;
            }
        }

        vector<int> ans;
        
        // 2. Process Queries
        for (const auto& q : queries) {
            int r = q[0];
            int c = q[1];

            // If the cell is illuminated by ANY row, col, or diagonal, it's bright.
            if (row_cnt[r] > 0 || col_cnt[c] > 0 || diag1_cnt[r - c] > 0 || diag2_cnt[r + c] > 0) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }

            // 3. Turn off any lamps in the 3x3 surrounding grid
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nr = r + i;
                    int nc = c + j;
                    
                    // If we find an active lamp in this 3x3 area
                    if (active_lamps.count({nr, nc})) {
                        active_lamps.erase({nr, nc}); // Remove the lamp
                        
                        // Decrement the illumination counts for the lines this lamp affected
                        row_cnt[nr]--;
                        col_cnt[nc]--;
                        diag1_cnt[nr - nc]--;
                        diag2_cnt[nr + nc]--;
                    }
                }
            }
        }

        return ans;
    }
};