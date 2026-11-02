class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum =0;
        int rsum =0;

      
        int rind = n-1;
      


        for(int i=0 ;i<k ; i++){
            lsum += cardPoints[i];
        }

        int ans = lsum;

        int ind = k-1;

        while(k--){
           
            rsum += cardPoints[rind];
            lsum -= cardPoints[ind];

            rind--;
            ind--;

            ans = max(ans , lsum+rsum);
        }


        return ans;
    }
};