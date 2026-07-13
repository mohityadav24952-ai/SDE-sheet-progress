class Solution {
public:

    // Function to count number of digits in a number
    int countDigits(int n) {
        int cnt = 0;

        while (n) {
            cnt++;
            n /= 10;
        }

        return cnt;
    }

    vector<int> sequentialDigits(int low, int high) {

        // String containing all sequential digits
        string s = "123456789";

        vector<int> ans;

        // Minimum and maximum length of numbers required
        int minLen = countDigits(low);
        int maxLen = countDigits(high);

        // Try every possible length
        for (int len = minLen; len <= maxLen; len++) {

            // Sliding window over "123456789"
            for (int i = 0; i + len <= 9; i++) {

                // Extract current window
                string temp = s.substr(i, len);

                // Convert substring to integer
                int num = stoi(temp);

                // Check if it lies in the given range
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};