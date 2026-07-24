class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // 1. Group cells by value. map automatically sorts keys ascending.
        map<int, vector<pair<int, int>>> valToCells;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                valToCells[mat[i][j]].push_back({i, j});
            }
        }

        // 2. 1D tracking arrays replacing the inner loops
        vector<int> row_max(m, 0);
        vector<int> col_max(n, 0);
        int ans = 0;

        // 3. Process batches of identical values
        for (auto& [val, cells] : valToCells) {
            
            // Temporary array to hold answers for this specific value batch
            vector<int> current_paths(cells.size());
            
            // Step A: Calculate the best path for all cells in this batch
            for (int k = 0; k < cells.size(); k++) {
                int r = cells[k].first;
                int c = cells[k].second;
                
                // O(1) lookup instead of O(M+N) loops!
                current_paths[k] = 1 + max(row_max[r], col_max[c]);
                ans = max(ans, current_paths[k]);
            }
            
            // Step B: Update the tracking arrays AFTER all calculations are done
            for (int k = 0; k < cells.size(); k++) {
                int r = cells[k].first;
                int c = cells[k].second;
                
                row_max[r] = max(row_max[r], current_paths[k]);
                col_max[c] = max(col_max[c], current_paths[k]);
            }
        }

        return ans;
    }
};