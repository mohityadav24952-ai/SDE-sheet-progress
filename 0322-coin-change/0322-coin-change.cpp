class Solution {
public:

    int subsetsum(vector<int>& arr, int w) {

        int n = arr.size();

        vector<vector<int>> t(n + 1, vector<int>(w + 1));

        // Base initialization
        for(int i = 0; i <= n; i++) {
            t[i][0] = 0;
        }

        for(int j = 1; j <= w; j++) {
            t[0][j] = INT_MAX - 1;
        }

        // 2nd row initialization
        for(int j = 1; j <= w; j++) {
            if(j % arr[0] == 0)
                t[1][j] = j / arr[0];
            else
                t[1][j] = INT_MAX - 1;
        }

        // Unbounded Knapsack DP
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= w; j++) {

                if(arr[i - 1] <= j) {

                    t[i][j] = min(
                        t[i - 1][j],                     // not take
                        1 + t[i][j - arr[i - 1]]        // take
                    );
                }
                else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        if(t[n][w] == INT_MAX - 1)
            return -1;

        return t[n][w];
    }

    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0) return 0;

        return subsetsum(coins, amount);
    }
};