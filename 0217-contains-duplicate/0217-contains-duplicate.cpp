class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
       int n = nums.size();

       unordered_set<int>st;

        for(auto num : nums){
            if(st.find(num)!=st.end()){
                return true;
            }
            else st.insert(num);
        }

        return false;
    }
};