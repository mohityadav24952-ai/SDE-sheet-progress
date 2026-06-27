class Solution {
public:

    // ----------------------------------------------------
    // Generates one row of Pascal Triangle
    // ----------------------------------------------------
    vector<int> generateRow(int row) {

        vector<int> ansRow;

        // First element is always 1
        long long value = 1;
        ansRow.push_back(1);

        // Generate remaining elements using nCr formula
        for (int col = 1; col < row; col++) {

            // Current = Previous * (row-col) / col
            value = value * (row - col);
            value = value / col;

            ansRow.push_back(value);
        }

        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        // Generate each row one by one
        for (int row = 1; row <= numRows; row++) {
            ans.push_back(generateRow(row));
        }

        return ans;
    }
};