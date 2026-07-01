// dp[i] = true matlab hum index i tak pahunch sakte hain.

// For every index i:

// Hum i par tabhi aa sakte hain agar:
// s[i] == '0'
// aur range [i-maxJump, i-minJump] me koi reachable index (dp[j] == true) ho.

// Naive approach me har range ko check karoge to O(n²) ho jayega.

// Isliye ek variable reachable maintain karte hain jo batata hai ki current valid range me kitne reachable indices hain.



class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        // dp[i] = true means hum index i tak pahunch sakte hain
        vector<bool> dp(n, false);

        // Starting position hamesha reachable hai
        dp[0] = true;

        // Sliding window me kitne reachable indices hain
        int reachable = 0;

        for (int i = 1; i < n; i++) {

            // Window me naya index add karo
            // (i - minJump) ab valid starting point ban gaya
            if (i >= minJump && dp[i - minJump])
                reachable++;

            // Window se purana index hata do
            // (i - maxJump - 1) ab range ke bahar chala gaya
            if (i > maxJump && dp[i - maxJump - 1])
                reachable--;

            // Current index tabhi reachable hai jab:
            // 1. Character '0' ho
            // 2. Window me kam se kam ek reachable index ho
            if (s[i] == '0' && reachable > 0)
                dp[i] = true;
        }

        // Last index reachable hai ya nahi
        return dp[n - 1];
    }
};