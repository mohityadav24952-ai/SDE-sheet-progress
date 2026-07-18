class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max = 0;
        int min = 0;

        max = *max_element(nums.begin() , nums.end());
         min = *min_element(nums.begin() , nums.end());

        return gcd(max,min);
    }
};