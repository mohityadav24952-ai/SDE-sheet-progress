class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {       
        int n = nums.size();
        int l=0 ; int r=0;
        long long sum=0;long long msum =0;

        unordered_set<int>st;

       while(r<=n-1){

            while(st.find(nums[r])!=st.end() || (r-l+1)>k){
                sum-=nums[l];
                st.erase(nums[l]);
                l++;
                
            }

            st.insert(nums[r]);
            sum+=nums[r];

           if(r-l+1 ==k) msum = max(msum,sum);
            
            r++;
        }
        return msum;
    }
};