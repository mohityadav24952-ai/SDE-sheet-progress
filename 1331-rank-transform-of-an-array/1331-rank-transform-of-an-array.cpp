class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        // Copy of original array
        vector<int> temp = arr;

        // Sort the copied array
        sort(temp.begin(), temp.end());

        // Stores <element, rank>
        unordered_map<int, int> mp;

        int rank = 1;

        // Assign rank only to unique elements
        for(int i = 0; i < temp.size(); i++){

            // If element is not present in map, assign a new rank
            if(mp.find(temp[i]) == mp.end()){
                mp[temp[i]] = rank;
                rank++;
            }
        }

        vector<int> ans;

        // Replace every element with its corresponding rank
        for(int i = 0; i < arr.size(); i++){
            ans.push_back(mp[arr[i]]);
        }

        return ans;
    }
};