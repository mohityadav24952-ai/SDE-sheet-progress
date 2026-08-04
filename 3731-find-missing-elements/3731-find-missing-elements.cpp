class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i=0; i<n ; i++){
            mp[nums[i]]++;
        }
;
        
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end()); 
        
        vector<int>ans ;

        if ((maxi - mini) == n-1) return ans ;
       

        int i = mini ;
        while(i<=maxi){
            if(i+1<maxi && mp.find(i+1)==mp.end()) ans.push_back(i+1);

         i++; 
        }

       return ans ;
    }
};