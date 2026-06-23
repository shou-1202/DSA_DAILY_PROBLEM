class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // c == '*'
                minOpen--; // Treat as ')'
                maxOpen++; // Treat as '('
            }

            // Too many ')' encountered
            if (maxOpen < 0) {
                return false;
            }
            
            // We can't have a negative number of open parentheses
            // This just means we used a '*' as a ')' when we didn't need to.
            if (minOpen < 0) {
                minOpen = 0;
            }
        }

        // If minOpen is 0, we perfectly matched everything
        return minOpen == 0;
    }
};