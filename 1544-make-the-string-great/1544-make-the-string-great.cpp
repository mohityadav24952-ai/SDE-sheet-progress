class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
       
        string ans = "";
        for(char ch : s){           
            if(!ans.empty() && abs(ch-ans.back()) == 32) ans.pop_back();
            else ans.push_back(ch);
        }
        return ans ;
    }
};