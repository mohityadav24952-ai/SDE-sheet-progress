class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        int n = prices.size();

        stack<int> st;
        vector<int> nse(n, 0);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {

            // Bade elements hata do
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            // Next smaller/equal mil gaya
            if (!st.empty()) {
                nse[i] = st.top();
            }

            // Current element push karo
            st.push(prices[i]);
        }

        // Final prices calculate karo
        for (int i = 0; i < n; i++) {
            ans[i] = prices[i] - nse[i];
        }

        return ans;
    }
};