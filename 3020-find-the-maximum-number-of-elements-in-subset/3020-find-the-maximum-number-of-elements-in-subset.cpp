class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> freq;

        // Store frequency of every number
        for (int num : nums) {
            freq[num]++;
        }

        // Handle number 1 separately
        // We can only take odd count of 1's
        int ans = (freq[1] - 1) | 1;

        // Remove 1 because it is already processed
        freq.erase(1);

        // Try starting chain from every unique number
        for (auto it : freq) {

            long long current = it.first;

            // Check if current is already the square of another
            // number which appears at least twice.
            // If yes, then this chain has already been considered.
            long long root = sqrt(current);

            if (root * root == current &&
                freq.count(root) &&
                freq[root] > 1) {
                continue;
            }

            int length = 0;

            // Continue the chain while current number
            // appears at least twice.
            while (freq.count(current) && freq[current] > 1) {

                length += 2;

                current = current * current;
            }

            // Last number contributes:
            // +1 if present once
            // -1 if absent
            if (freq.count(current))
                length++;
            else
                length--;

            ans = max(ans, length);
        }

        return ans;
    }
};