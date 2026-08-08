const int N = 3e5;
int last[N];

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        memset(last, -1, n2 * sizeof(int));
        last[n2] = n1;

        int j = n1 - 1;

        for (int i = n2 - 1; i >= 0; i--) {
            while (j >= 0 && word2[i] != word1[j]) {
                j--;
            }

            if (j < 0) break;

            last[i] = j;
            j--;
        }

        vector<int> ans(n2);

        bool changed = false;
        j = 0;

        for (int i = 0; i < n1 && j < n2; i++) {

            bool same = (word1[i] == word2[j]);
            bool canChange = (!changed && i < last[j + 1]);

            if (same || canChange) {
                ans[j] = i;
                j++;

                if (!same) {
                    changed = true;
                }
            }
        }

        if (j == n2) {
            return ans;
        }

        return {};
    }
};