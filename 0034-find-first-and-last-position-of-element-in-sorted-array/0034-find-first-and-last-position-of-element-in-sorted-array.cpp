class Solution {
public:

int firstocc(vector<int>& nums, int target , int n){
    int l = 0 ;
    int r=n-1;
    int f = -1 ;

    while(l<=r){

            int m = l + (r-l)/2 ;

        if(nums[m] == target) {
            f = m ;
            r = m -1;
        }
        else if(nums[m]<target){
            l = m + 1;
        }
        else r = m - 1;
    }

    return f ;
}



int lastocc(vector<int>& nums, int target , int n){
    int l = 0 ;
    int r=n-1;
    
    int last = -1 ;

    while(l<=r){

        int m = l + (r-l)/2 ;
        if(nums[m] == target) {
            last = m ;
            l = m + 1;
           
        }
        else if(nums[m]<target){
            l = m + 1;
        }
        else r = m - 1;
    }

    return last ;
}




    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
    vector<int>ans;
    ans.push_back(firstocc(nums,target,n));
    ans.push_back(lastocc(nums,target,n));

    return ans;
    }
};