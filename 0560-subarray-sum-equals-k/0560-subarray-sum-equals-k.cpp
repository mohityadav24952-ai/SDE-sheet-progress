class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        int sum = 0;
        int rem = 0;
        int ans = 0;
        
        // Base case: jab prefix sum 0 ho (matlab pure sequence ka sum k ke barabar ho)
        mp[0] = 1; 

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            rem = sum - k;

            // Agar rem pehle mil chuka hai, toh uski frequency add karo
            if (mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            // Prefix sum ki frequency badhao har case me
            mp[sum]++;
        }

        return ans;
    }
};