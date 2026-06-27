class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;

        vector<int> ans;

        int rows = mat.size();
        int cols = mat[0].size();

        for(int i=0 ; i<rows ; i++){

            int soldiers = 0;

            // Current row me soldiers count karo
            for(int j=0 ; j<cols ; j++){
                if(mat[i][j] == 1)
                    soldiers++;
            }

            // (soldiers, rowIndex)
            minh.push({soldiers, i});
        }

        // k weakest rows nikalo
        while(k--){

            ans.push_back(minh.top().second);
            minh.pop();
        }

        return ans;
    }
};