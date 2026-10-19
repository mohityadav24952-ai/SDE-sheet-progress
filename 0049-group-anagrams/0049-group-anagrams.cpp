class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
               int n = strs.size();

        unordered_map<string,vector<string>>mp;

        

      for(string s : strs){

        vector<int>v(26,0);

           for(char c : s){
               v[c-'a']++;         
           }

            string key = " ";

           for(int i=0 ; i<26 ; i++){
              key += "#" + to_string(v[i]);
           }

           mp[key].push_back(s);

          
        }

        vector<vector<string>>ans;

        for(auto pairs : mp){
            ans.push_back(pairs.second);
        }



        return ans;
    }
};