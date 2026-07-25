class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
       bool inc = false ;
       bool dec =false ;

      int n = nums.size();

      for(int i=0 ; i<n-1 ; i++){
        if(nums[i] < nums[i+1]) inc = true ;
        if(nums[i] > nums[i+1]) dec = true ;

        if(dec && inc) return false ;
      }
      return true ;
      



       
    }
};