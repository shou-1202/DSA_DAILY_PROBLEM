class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size() * words[0].size();
        vector<int> ans;
        if(s.length() < n) return ans;
        
        unordered_map<string, int> m;
        for(int i = 0; i < words.size(); i++){
            m[words[i]] += 1;
        }
        
        int j = words[0].size();
        
        // FIX 1: The Offset Loop. 
        // We run your while loop 'j' times to make sure we don't skip indices 1, 2, etc.
        for (int offset = 0; offset < j; offset++) {
            int i = offset;       // Your 'i' (the start of the valid window)
            int right = offset;   // We add a 'right' pointer to scan ahead
            int words_found = 0;
            unordered_map<string, int> temp; // Your temp map
            
            // Your original while loop concept, scanning to the end of the string
            while (right + j <= s.length()) {
                string a = s.substr(right, j);
                right += j; 
                
                // If it's a valid word from the original list
                if (m.find(a) != m.end() && m[a] != 0) {
                    temp[a]++;
                    words_found++;
                    
                    // FIX 2: The memory fix.
                    // Instead of clearing the map and starting over when we have too many of a word,
                    // we use your `i += j` jump to shrink the window from behind, removing words
                    // from 'temp' until the window is valid again!
                    while (temp[a] > m[a]) {
                        string left_word = s.substr(i, j);
                        temp[left_word]--;
                        words_found--;
                        i += j; // <-- There is your exact jump!
                    }
                    
                    // Did we find all the words?
                    if (words_found == words.size()) {
                        ans.push_back(i);
                    }
                } else {
                    // The word isn't in our list at all. 
                    // Now we are forced to clear the map and jump 'i' forward.
                    temp.clear();
                    words_found = 0;
                    i = right; 
                }
            }
        }
        return ans;
    }
};