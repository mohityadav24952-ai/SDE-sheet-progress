class Solution {
public:
    string frequencySort(string s) {

        // Step 1 : Store frequency of every character
        unordered_map<char,int> freq;

        for(char c : s){
            freq[c]++;
        }

        // Step 2 : Copy map into vector
        vector<pair<char,int>> v;

        for(auto x : freq){
            v.push_back(x);
        }

        // Step 3 : Sort by frequency (Descending)    ---------------- IMPORTANT
        sort(v.begin(), v.end(),
        [](pair<char,int> a, pair<char,int> b){
            return a.second > b.second;
        });

        // Step 4 : Build answer
        string ans = "";

        for(auto x : v){

            // Add character x.second times
            ans.append(x.second, x.first);

            // OR
            // for(int i = 0; i < x.second; i++)
            //     ans += x.first;
        }

        return ans;
    }
};