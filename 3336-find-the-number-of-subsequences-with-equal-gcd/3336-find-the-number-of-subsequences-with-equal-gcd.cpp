class Solution {
public:
    int n;
    int mod = 1e9 + 7;

    vector<int> nums;

    // GCD pehle hi calculate karke rakh liya
    vector<vector<int>> gcdTable;

    // dp[index][gcd of seq1][gcd of seq2]
    vector<vector<vector<long long>>> dp;

    long long solve(int index, int gcd1, int gcd2) {

        // Sare elements process ho gye
        if(index == n){

            // Dono subsequences ka gcd same hona chahiye
            // Aur empty subsequence nahi honi chahiye
            if(gcd1 == gcd2 && gcd1 != 0)
                return 1;

            return 0;
        }

        // Memoization
        if(dp[index][gcd1][gcd2] != -1)
            return dp[index][gcd1][gcd2];

        // ---------------- Choice 1 ----------------
        // Current element ko ignore kar do
        long long skip = solve(index + 1, gcd1, gcd2);

        // ---------------- Choice 2 ----------------
        // Current element ko first subsequence me daal do

        int newGcd1;

        if(gcd1 == 0)
            newGcd1 = nums[index];
        else
            newGcd1 = gcdTable[gcd1][nums[index]];

        long long takeInFirst =
            solve(index + 1, newGcd1, gcd2);

        // ---------------- Choice 3 ----------------
        // Current element ko second subsequence me daal do

        int newGcd2;

        if(gcd2 == 0)
            newGcd2 = nums[index];
        else
            newGcd2 = gcdTable[gcd2][nums[index]];

        long long takeInSecond =
            solve(index + 1, gcd1, newGcd2);

        // Total ways
        return dp[index][gcd1][gcd2] =
            (skip + takeInFirst + takeInSecond) % mod;
    }

    int subsequencePairCount(vector<int>& arr) {

        nums = arr;
        n = arr.size();

        // GCD table bana lo
        gcdTable.resize(201, vector<int>(201));

        for(int i = 0; i <= 200; i++){
            for(int j = 0; j <= 200; j++){
                gcdTable[i][j] = __gcd(i, j);
            }
        }

        // DP initialize
        dp.assign(
            n,
            vector<vector<long long>>(
                201,
                vector<long long>(201, -1)
            )
        );

        return solve(0, 0, 0);
    }
};