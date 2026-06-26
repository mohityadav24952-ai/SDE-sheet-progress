class Solution {
public:

    // ================= SUM OF SUBARRAY MINIMUMS =================

    long long sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        stack<int> st;

        // left  = Previous Smaller tak ki distance
        // right = Next Smaller tak ki distance
        vector<int> left(n), right(n);

        // -------- Previous Smaller --------

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if(st.empty())
                left[i] = i + 1;
            else
                left[i] = i - st.top();

            st.push(i);
        }

        // naye pass ke liye stack empty
        while(!st.empty()) st.pop();

        // -------- Next Smaller --------

        for(int i = n - 1; i >= 0; i--) {

            // >= taaki duplicate elements double count na ho
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty())
                right[i] = n - i;
            else
                right[i] = st.top() - i;

            st.push(i);
        }

        // -------- Contribution Add --------

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            // Contribution = Value × Left Choices × Right Choices
            ans += 1LL * arr[i] * left[i] * right[i];
        }

        return ans;
    }

    // ================= SUM OF SUBARRAY MAXIMUMS =================

    long long sumSubarrayMaxs(vector<int>& arr) {

        int n = arr.size();

        stack<int> st;

        // left  = Previous Greater tak ki distance
        // right = Next Greater tak ki distance
        vector<int> left(n), right(n);

        // -------- Previous Greater --------

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            if(st.empty())
                left[i] = i + 1;
            else
                left[i] = i - st.top();

            st.push(i);
        }

        // naye pass ke liye stack empty
        while(!st.empty()) st.pop();

        // -------- Next Greater --------

        for(int i = n - 1; i >= 0; i--) {

            // <= taaki duplicate elements double count na ho
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if(st.empty())
                right[i] = n - i;
            else
                right[i] = st.top() - i;

            st.push(i);
        }

        // -------- Contribution Add --------

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            // Contribution = Value × Left Choices × Right Choices
            ans += 1LL * arr[i] * left[i] * right[i];
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {

        // Answer = Sum of Maximums - Sum of Minimums
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};