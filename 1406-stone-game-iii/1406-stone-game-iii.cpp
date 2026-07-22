class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> t(n + 1);

        int a = 0; // t[i+1]
        int b = 0; // t[i+2]
        int c = 0; // t[i+3]

        //  Forward nahi, reverse iterate karna hai theek bhai ??????????????
        for (int i = n - 1; i >= 0; i--) {

            int result = INT_MIN;

            // CASE - 1 : Take 1 stone
            result = max(result, stoneValue[i] - a);

            // CASE - 2 : Take 2 stones
            if (i + 1 < n)
                result = max(result,
                             stoneValue[i] + stoneValue[i + 1] - b);

            // CASE - 3 : Take 3 stones
            if (i + 2 < n)
                result = max(result,
                             stoneValue[i] +
                             stoneValue[i + 1] +
                             stoneValue[i + 2] - c);

           
            c = b;
            b = a;
            a = result;
        }

        int diff = a;

        if (diff < 0)
            return "Bob";
        else if (diff > 0)
            return "Alice";

        return "Tie";
    }
};