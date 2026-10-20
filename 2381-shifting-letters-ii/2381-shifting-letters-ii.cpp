class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n, 0); 

        // Step 1: Build the difference array 
        for (auto& query : shifts) {
            int L = query[0], R = query[1], dir = query[2]; 
            int x = (dir == 0) ? -1 : 1; 
            diff[L] += x; 
            if (R + 1 < n) diff[R + 1] -= x; 
        } 

        // Step 2: Compute prefix sums 
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1]; 
        } 

        // Step 3: Apply shifts to the string 
        for (int i = 0; i < n; i++) {
            int shift = diff[i] % 26; 
            if (shift < 0) shift += 26; 
            s[i] = ((s[i] - 'a') + shift) % 26 + 'a'; 
        } 
        
        return s; 
    } 
};