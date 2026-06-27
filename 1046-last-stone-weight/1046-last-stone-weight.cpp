class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxh;

        int n = stones.size();

        // Sare stones max heap me daal do
        for(int i=0 ; i<n ; i++){
            maxh.push(stones[i]);
        }

        while(maxh.size() > 1){

            // Do sabse bade stones nikalo
            int first = maxh.top();
            maxh.pop();

            int second = maxh.top();
            maxh.pop();

            // Agar dono equal nahi hain to difference wapas daal do
            if(first != second){
                maxh.push(first - second);
            }
        }

        // Agar koi stone bacha hai to return karo, warna 0
        if(maxh.empty())
            return 0;

        return maxh.top();
    }
};




// Sabhi stones max heap me daal do.
// Top nikalo = largest
// Dubara top nikalo = second largest
// Agar dono equal hain → dono destroy.
// Agar different hain → difference (x-y) wapas heap me daal do.
// Jab heap me 0 ya 1 stone bache, wahi answer hai.