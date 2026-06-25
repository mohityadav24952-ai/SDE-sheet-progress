class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();
        long long ans = 0;     // total majority subarrays count

        // HAR INDEX SE SUBARRAY START KRVAO
        for(int i = 0; i < n; i++) {

            int freq = 0;      // target kitni baar aaya current subarray me

            // SUBARRAY KO AAGE BADHATE JAO
            for(int j = i; j < n; j++) {

                // AGAR TARGET MIL GYA TO FREQUENCY BADHA DO
                if(nums[j] == target) {
                    freq++;
                }

                int len = j - i + 1;   // current subarray length

                // MAJORITY CONDITION:
                // target ki frequency > length/2 honi chahiye
                if(freq > len / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};