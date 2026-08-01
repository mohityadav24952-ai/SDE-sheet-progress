class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp; // bhai rem and index save karlete hai 
        int n = nums.size();
        int sum=0;
        int size = 0 ;

        // edge case
        mp[0] = -1;

        for(int i=0 ; i<n ; i++){
            sum += nums[i];

            if(mp.find(sum%k) != mp.end()){
                size = i - mp[sum%k];
                if(size >=2){
                    return true;
                }
            }
            else mp[sum%k]=i;
        }
        return false;
    }
};