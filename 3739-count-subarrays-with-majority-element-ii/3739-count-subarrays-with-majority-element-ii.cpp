class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();
        long long ans = 0;

        // TARGET KO +1 BNA DO
        // BAAKI SAB ELEMENTS KO -1
        for(int i = 0; i < n; i++) {

            if(nums[i] == target) {
                nums[i] = 1;
            }
            else {
                nums[i] = -1;
            }
        }

        // PREFIX SUM ARRAY
        vector<int> pref(n);

        pref[0] = nums[0];

        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }

        // NEGATIVE PREFIX SUM HANDLE KRNE KE LIYE SHIFT
        int shift = n;

        // PREFIX SUM FREQUENCY STORE KREGA
        vector<int> freq(2 * n + 1, 0);

        // PREFIX SUM = 0 EK BAAR PEHLE SE EXIST KRTA HAI
        freq[shift] = 1;

        long long valid = 0;

        // PREVIOUS PREFIX SUM
        int lastsum = 0;

        for(int i = 0; i < n; i++) {

            // AGAR CURRENT PREFIX BADA HAI
            if(pref[i] > lastsum) {

                valid += freq[lastsum + shift];
            }

            // AGAR CHHOTA YA EQUAL HAI
            else {

                valid -= freq[pref[i] + shift];
            }

            // CURRENT POSITION TAK KITNE VALID SUBARRAYS HAIN
            ans += valid;

            // CURRENT PREFIX KO STORE KR DO
            freq[pref[i] + shift]++;

            // UPDATE LAST PREFIX
            lastsum = pref[i];
        }

        return ans;
    }
};