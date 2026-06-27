class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // -------------------- PHASE 1 --------------------
        // Find the two possible majority candidates.

        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {

            // Candidate 1 empty hai aur current element candidate 2 nahi hai.
            if (cnt1 == 0 && nums[i] != ele2) {
                ele1 = nums[i];
                cnt1 = 1;
            }

            // Candidate 2 empty hai aur current element candidate 1 nahi hai.
            else if (cnt2 == 0 && nums[i] != ele1) {
                ele2 = nums[i];
                cnt2 = 1;
            }

            // Candidate 1 mila -> vote increase
            else if (nums[i] == ele1) {
                cnt1++;
            }

            // Candidate 2 mila -> vote increase
            else if (nums[i] == ele2) {
                cnt2++;
            }

            // Kisi bhi candidate se match nahi hua.
            // Dono candidates ke votes cancel.
            else {
                cnt1--;
                cnt2--;
            }
        }

        // -------------------- PHASE 2 --------------------
        // Verify ki candidates actually n/3 se zyada baar aaye hain ya nahi.

        cnt1 = 0;
        cnt2 = 0;

        for (int num : nums) {

            if (num == ele1)
                cnt1++;

            if (num == ele2)
                cnt2++;
        }

        vector<int> ans;

        // Minimum frequency required (> n/3)
        int mini = nums.size() / 3 + 1;

        if (cnt1 >= mini)
            ans.push_back(ele1);

        if (cnt2 >= mini)
            ans.push_back(ele2);

        // LeetCode expects sorted output.
        sort(ans.begin(), ans.end());

        return ans;
    }
};