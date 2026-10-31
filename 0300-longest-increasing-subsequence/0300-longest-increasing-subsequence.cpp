class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>temp;
        
        temp.push_back(nums[0]);
        int len = 1;


        for(int i=0 ;i<n ; i++){

            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
           else {
    // 1. lower_bound ko 'temp' array par lagayein, 'nums' par nahi
           auto ind = lower_bound(temp.begin(), temp.end(), nums[i]);
    
    // 2. Iterator wale address par direct nayi value daal dein
              *ind = nums[i]; 
}
        }

        return len ;
    }
};