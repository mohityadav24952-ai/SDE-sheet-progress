//store all in set -> now everything in unique -> from set, just add (+ve) -> this is max subarray sum here
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        if(mx <= 0) return mx;

        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for(int x : st) {
            if(x > 0){
                ans = ans + x;
            }
        }

        return ans;
    }
};