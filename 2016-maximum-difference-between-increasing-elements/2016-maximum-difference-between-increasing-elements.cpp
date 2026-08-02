class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
       
        int maxd = -1;int diff = -1;
        int mine = nums[0];

        for(int i=1 ; i<n ; i++){
            
          if(nums[i]>mine)  diff = nums[i]-mine;
          mine = min(mine,nums[i]);
          maxd = max(maxd,diff);
        }
        return maxd;
    }
};