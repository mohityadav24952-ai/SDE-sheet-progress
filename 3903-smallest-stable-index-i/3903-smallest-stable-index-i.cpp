class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>maxi(n);
        maxi[0]=nums[0];
        int maxx = nums[0];

        for(int i=1 ; i<n ; i++){
            
            if(nums[i]>maxx) 
            {
                maxx=nums[i];               
            }
             maxi[i]=maxx;
        }

        vector<int>mini(n);

        mini[n-1]=nums[n-1];

        int minn = nums[n-1];

      
        for(int i=n-1 ; i>=0 ; i--){
            
            if(nums[i]<minn) 
            {
                minn=nums[i];               
            }
             mini[i]=minn;
        }


        for(int i=0 ; i<n ; i++){
            if((maxi[i]-mini[i])<=k) return i;
        }


        return -1;

    }
};