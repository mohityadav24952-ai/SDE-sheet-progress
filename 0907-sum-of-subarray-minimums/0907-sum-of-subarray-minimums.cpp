class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        int mod = 1e9 + 7;

        // Previous Smaller Element ke liye stack
        stack<pair<int,int>> pse;

        // Next Smaller Element ke liye stack
        stack<pair<int,int>> nse;

        // left[i] = kitne subarrays me arr[i] minimum ban sakta hai left side se
        vector<int> left(n);

        // right[i] = kitne subarrays me arr[i] minimum ban sakta hai right side se
        vector<int> right(n);

        // default values
        for(int i=0;i<n;i++){
            left[i] = i + 1;
            right[i] = n - i;
        }

        for(int i=0;i<n;i++){

            // ---------------- Previous Smaller ----------------

            // current se bade elements hata do
            while(!pse.empty() && pse.top().first > arr[i]){
                pse.pop();
            }

            // previous smaller tak ki distance
            if(!pse.empty()){
                left[i] = i - pse.top().second;
            }

            // current element push
            pse.push({arr[i], i});


            // ---------------- Next Smaller ----------------

            // jinke liye current element next smaller ban gaya
            while(!nse.empty() && nse.top().first > arr[i]){

                pair<int,int> temp = nse.top();
                nse.pop();

                // next smaller ki distance
                right[temp.second] = i - temp.second;
            }

            // current push
            nse.push({arr[i], i});
        }


        long long ans = 0;

        // Contribution Technique
        for(int i=0;i<n;i++){

            // arr[i] kitne subarrays me minimum banega
            ans = (ans + (1LL * arr[i] * left[i] * right[i])) % mod;
        }

        return ans;
    }
};