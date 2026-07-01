// Logic
// Har lowercase character ka last occurrence store kro.
// Har uppercase character ka first occurrence store kro.
// Agar
// lowercase present hai
// uppercase present hai
// aur last lowercase < first uppercase
// To vo character special hai.



class Solution {
public:
    int numberOfSpecialChars(string word) {

        // last occurrence of a-z
        vector<int> lastSmall(26, -1);

        // first occurrence of A-Z
        vector<int> firstCapital(26, -1);

        // Pure string ek baar traverse karenge
        for (int i = 0; i < word.size(); i++) {

            // lowercase character
            if (islower(word[i])) {
                // last occurrence update karte rahenge
                lastSmall[word[i] - 'a'] = i;
            }

            // uppercase character
            else {

                // sirf first occurrence store karni hai
                if (firstCapital[word[i] - 'A'] == -1)
                    firstCapital[word[i] - 'A'] = i;
            }
        }

        int ans = 0;

        // Har alphabet check karo
        for (int i = 0; i < 26; i++) {

            // dono exist karne chahiye
            if (lastSmall[i] != -1 && firstCapital[i] != -1) {

                // saare lowercase pehle hone chahiye
                if (lastSmall[i] < firstCapital[i])
                    ans++;
            }
        }

        return ans;
    }
};