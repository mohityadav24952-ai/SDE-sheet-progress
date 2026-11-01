class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int n = nums.size();


        int s = 0;

        int mini = *min_element(nums.begin(),nums.end());

        for(int i=0 ; i<n ; i++){
            s += nums[i];
        }

        int ans=0;

         ans = (s - n*(mini));

        return ans;
    }
};