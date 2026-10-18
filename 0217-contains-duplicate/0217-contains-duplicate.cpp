class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
       int n = nums.size();

        unordered_map<int,int>mp;

        for(auto num : nums){
            if(mp.find(num)!=mp.end()){
                return true;
            }
            else mp[num]++;
        }


        return false;
    }
};