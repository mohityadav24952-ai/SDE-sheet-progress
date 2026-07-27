class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      
         int j= 0; int i=0;
         int minl = INT_MAX;
         int cursum = 0;
         int n = nums.size();


         while(j<n){
            cursum += nums[j];

            while(cursum >= target){
                minl = min(minl , j-i+1);
                cursum -=  nums[i];
                i++;
            }

            j++;

         }
         if(minl == INT_MAX) return 0;
         else return minl ;
    }
};