class Solution {
public:
    int minLength(string s) {

        string ans = "";

        for(char ch : s) {

            // AB ya CD mila to pair remove kar do
            if(!ans.empty() &&
              ((ans.back() == 'A' && ch == 'B') ||
               (ans.back() == 'C' && ch == 'D')))
            {
                ans.pop_back();
            }
            else {
                ans.push_back(ch);
            }
        }

        return ans.size();
    }
};