class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        // INDEX STORE KRRE HAI...KYUKI WIDTH NIKALNI HAI
        stack<int> st;

        // left[i]  = Previous Smaller ka index
        // right[i] = Next Smaller ka index
        vector<int> left(n), right(n);

        // ---------------- STEP-1 : PREVIOUS SMALLER ----------------

        for(int i = 0; i < n; i++) {

            // current se bade ya equal heights ka koi use ni
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // previous smaller nahi mila
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        // naye pass ke liye stack empty
        while(!st.empty()) st.pop();

        // ---------------- STEP-2 : NEXT SMALLER ----------------

        for(int i = n - 1; i >= 0; i--) {

            // current se bade ya equal heights hata do
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // next smaller nahi mila
            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        // ---------------- STEP-3 : HAR BAR KI MAX AREA NIKALO ----------------

        int ans = 0;

        for(int i = 0; i < n; i++) {

            // BHAIII YE HI ACTUAL WIDTH HAI
            int width = right[i] - left[i] - 1;

            // Rectangle Area = Height × Width
            int area = heights[i] * width;

            ans = max(ans, area);
        }

        return ans;
    }
};