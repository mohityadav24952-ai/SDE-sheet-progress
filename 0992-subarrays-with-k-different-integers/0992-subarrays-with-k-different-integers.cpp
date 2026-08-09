class Solution {
public:
    int func(vector<int>& nums, int k){
        unordered_map<int,int>mp;
        int l = 0;int r=0;
        int n = nums.size();
        int count =0;
        while(r<n){
            mp[nums[r]]++;

            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]== 0) mp.erase(nums[l]);
                l++;
            }
            count += r-l+1;
            r++;

        }
        return count;        
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k) - func(nums,k-1);
    }
};