class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int,int>mp;

        for(int i=0 ; i<n ; i++){
            mp[arr[i]]++;
        }

        vector<bool>check(1001,false);


        for(auto it : mp){
            int c = it.second;

            if(check[c]) return false;

            check[c] = true;
        }

        return true;
    }
};