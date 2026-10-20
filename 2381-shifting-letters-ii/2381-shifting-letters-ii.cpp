class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        // Step 1: Integer array for difference logic
        vector<int> diff(n + 1, 0); 
        
        // Step 2: O(1) Range Updates
        for (auto& shift : shifts) {
            int st = shift[0];
            int end = shift[1];
            int x = (shift[2] == 1) ? 1 : -1;
            
            diff[st] += x;
            diff[end + 1] -= x; 
        }
        
        // Step 3: Prefix sum aur string update
        int current_shift = 0;
        for (int i = 0; i < n; i++) {
            current_shift += diff[i];
            
            // C++ me negative values ke liye modulo fix
            int net_shift = (current_shift % 26 + 26) % 26; 
            
            // Character update using safe wrap-around
            s[i] = 'a' + (s[i] - 'a' + net_shift) % 26;
        }
        
        return s;
    }
};