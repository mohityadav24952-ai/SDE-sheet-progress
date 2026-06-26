// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         unordered_map<int,int> freq;

//         int n = nums.size();

//         for(int i=0 ; i<n ; i++){

//             freq[nums[i]]++;

//             if(freq[nums[i]] > n/2)
//                 return nums[i];
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = 0;
        int count = 0;

        for(int num : nums){

            // Agar count 0 ho gaya,
            // to current element ko naya candidate maan lo.
            if(count == 0)
                candidate = num;

            // Agar current element candidate ke equal hai,
            // to uski frequency badhao.
            if(num == candidate)
                count++;

            // Nahi hai to ek frequency cancel kar do.
            else
                count--;
        }

        // Question guarantee karta hai ki majority element hamesha exist karega.
        return candidate;
    }
};