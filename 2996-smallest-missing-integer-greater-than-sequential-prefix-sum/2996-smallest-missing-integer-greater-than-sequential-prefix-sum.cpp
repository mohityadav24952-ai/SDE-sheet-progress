class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int>st(nums.begin(),nums.end());
        int sq=nums[0];

        for(int i=1 ;i<n ; i++){
                if(nums[i] == nums[i-1]+1) sq += nums[i];
                else break;
        }

        while(true){
            if(st.find(sq)==st.end()) return sq;
            else sq++;
        }
    }
};