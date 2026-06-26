class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        // Answer array ko pehle se 0 se initialize kar liya hai
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            // Jab tak stack khali nahi hai aur current temp stack ke top temp se bada ya barabar hai
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop(); // Chhote elements hata do kyunki wo aage kisi ke Next Greater nahi ban sakte
            }

            // Agar stack khali nahi hai, toh top element hi hamara Next Greater Temperature hai
            if (!st.empty()) {
                ans[i] = st.top() - i; // Din ka difference nikal kar store kar lo
            }

            // Current index ko aage aane wale dino ke comparison ke liye push kar do
            st.push(i);
        }
        
        return ans;
    }
};
