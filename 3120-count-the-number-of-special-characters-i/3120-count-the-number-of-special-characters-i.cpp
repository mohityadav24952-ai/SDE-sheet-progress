// Ek array me lowercase ki frequency/store.
// Dusre array me uppercase ki frequency/store.
// Har alphabet (a-z) ke liye check karo:
// agar lowercase bhi mila
// aur uppercase bhi mila
// to answer++.


class Solution {
public:
    int numberOfSpecialChars(string word) {

        // lowercase present hai ya nahi
        vector<int> small(26, 0);

        // uppercase present hai ya nahi
        vector<int> capital(26, 0);

        // pura string traverse karo
        for (char ch : word) {

            // lowercase mila
            if (islower(ch))
                small[ch - 'a']++;

            // uppercase mila
            else
                capital[ch - 'A']++;
        }

        int ans = 0;

        // Har alphabet check karo
        for (int i = 0; i < 26; i++) {

            // dono present hone chahiye
            if (small[i] > 0 && capital[i] > 0)
                ans++;
        }

        return ans;
    }
};