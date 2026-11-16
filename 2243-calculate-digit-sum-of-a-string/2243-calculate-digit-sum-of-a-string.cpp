class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string next_s = "";
            int n = s.size();
            for (int i = 0; i < n; i += k) {
                int val = 0;
                for (int j = i; j < min(i + k, n); j++) {
                    val += s[j] - '0';
                }
                next_s += to_string(val);
            }
            s = next_s;
        }
        return s;
    }
};