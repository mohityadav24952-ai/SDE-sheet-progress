// Try solving the problem using 3 cases.
// a) Considering all the values are 9.
// b) Considering the last digit is not 9.
// c) Considering the last digit is 9.
// This will make the coding a bit easy for you


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        // Last digit se start karo
        for(int i = n - 1; i >= 0; i--) {

            // Agar digit 9 se choti hai to simply +1 kar do
            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // Agar 9 hai to 0 bana do aur carry aage jayegi
            digits[i] = 0;
        }

        // Agar saare digits 9 the (ex: 999)
        // To answer hoga 1000
        digits.insert(digits.begin(), 1);

        return digits;
    }
};