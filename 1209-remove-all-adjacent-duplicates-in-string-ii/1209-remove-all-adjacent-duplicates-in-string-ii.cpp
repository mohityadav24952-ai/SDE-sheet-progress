class Solution {
public:
    string removeDuplicates(string s, int k) {
        // We use a stack to keep track of characters and how many times
        // they have appeared consecutively.
        // Each element in the stack is a pair: {character, count}
        stack<pair<char, int>> st;

        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                // If current char is same as the one on top, increment its count
                st.top().second++;
            } else {
                // Otherwise, push the new character with a count of 1
                st.push({c, 1});
            }

            // If the count of the character at the top reaches k, 
            // it means we found k adjacent duplicates, so remove them.
            if (st.top().second == k) {
                st.pop();
            }
        }

        // Now build the result string from the stack
        string ans = "";
        while (!st.empty()) {
            // Append the character (st.top().first) as many times as its count (st.top().second)
            ans.append(st.top().second, st.top().first);
            st.pop();
        }

        // Since we popped from the stack, the string is reversed.
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};