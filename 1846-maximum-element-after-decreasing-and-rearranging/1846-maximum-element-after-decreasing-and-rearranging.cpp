// ---------------------BACKLOG--------------------


class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        int n = arr.size();

        // Frequency array
        // cnt[i] = kitne elements ki value i hai
        // Agar koi element n se bada hai to usse n hi treat karenge,
        // kyunki final answer kabhi n se bada ho hi nahi sakta.
        vector<int> cnt(n + 1, 0);

        // Store frequencies
        for (int num : arr) {
            cnt[min(num, n)]++;
        }

        // val = maximum valid value jo ab tak bana sakte hain
        int val = 0;

        // Process values from 1 to n
        for (int i = 1; i <= n; i++) {

            // val + cnt[i]
            // = itne elements available hain jinhe maximum yahan tak assign kar sakte hain
            //
            // Lekin value i se zyada nahi ho sakti.
            val = min(i, val + cnt[i]);
        }

        return val;
    }
};