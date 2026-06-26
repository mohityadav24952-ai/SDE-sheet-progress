class Solution {
public:

    // ---------------- HISTOGRAM KA FUNCTION ----------------

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        stack<int> st;

        // Previous Smaller aur Next Smaller ke index
        vector<int> left(n), right(n);

        // -------- Previous Smaller --------

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        // Stack empty
        while(!st.empty()) st.pop();

        // -------- Next Smaller --------

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        int maxArea = 0;

        // Har bar ko rectangle ki height maan ke area nikal do
        for(int i = 0; i < n; i++) {

            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // BHAIII YE HAMARA HISTOGRAM HAI
        vector<int> height(cols, 0);

        int ans = 0;

        // Har row ko base maan ke histogram banao
        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                // Agar 1 mila to mountain aur bada ho gaya
                if(matrix[i][j] == '1')
                    height[j]++;

                // 0 mila to mountain toot gaya
                else
                    height[j] = 0;
            }

            // Current histogram ka max area nikal lo
            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }
};