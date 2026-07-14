class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;

        for(string word : strs)
        {
            string temp = word;              // original word ki copy

            sort(temp.begin(), temp.end()); // signature bana di

            mp[temp].push_back(word);       // original word store kar diya
        }
        vector<vector<string>> ans;
        for(auto x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};