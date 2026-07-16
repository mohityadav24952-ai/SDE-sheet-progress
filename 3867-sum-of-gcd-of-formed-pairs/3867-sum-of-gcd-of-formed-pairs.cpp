class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        vector<int>prefixgcd;


        for(int i=0 ; i<n ; i++){

           if(mx<nums[i]) mx = nums[i];
           prefixgcd.push_back(gcd(nums[i],mx));
        }

        sort(prefixgcd.begin() , prefixgcd.end() );

        int i = 0 ; 
        int j = prefixgcd.size()-1;

long long sum = 0;

        while(i<j){
            sum += gcd( prefixgcd[i], prefixgcd[j]) ;
            i++;
            j-- ;
        }

        return sum ;
    }
};