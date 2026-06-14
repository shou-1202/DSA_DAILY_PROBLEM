class Solution {
private:
    // Our cache to store previously calculated string pairs
    unordered_map<string, bool> memo;

public:
    bool isScramble(string s1, string s2) {
        // 1. Base cases
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        int n = s1.length();
        
        // 2. Optimization: Anagram Check
        // If s1 and s2 don't have the exact same characters, they can never be scrambled.
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        
        // 3. Memoization Check
        // Have we evaluated this exact pair before?
        string key = s1 + "_" + s2;
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        // 4. Try all possible split points
        for (int i = 1; i < n; i++) {
            
            // Case 1: The two pieces were NOT swapped
            bool no_swap = isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                           isScramble(s1.substr(i), s2.substr(i));
            
            if (no_swap) {
                memo[key] = true;
                return true;
            }
            
            // Case 2: The two pieces WERE swapped
            bool swap_case = isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                             isScramble(s1.substr(i), s2.substr(0, n - i));
                        
            if (swap_case) {
                memo[key] = true;
                return true;
            }
        }
        
        // 5. If we loop through every split point and nothing worked, it's false.
        memo[key] = false;
        return false;
    }
};