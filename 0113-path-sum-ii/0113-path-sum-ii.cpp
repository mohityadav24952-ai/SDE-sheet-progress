class Solution {
public:
    void path(TreeNode* root, int targetSum, vector<int>& ans, vector<vector<int>>& res) {
        if (root == NULL) return;

        // 1. Current node ko path mein add karo
        ans.push_back(root->val);

        // 2. Leaf node aur sum check
        if (root->left == NULL && root->right == NULL && root->val == targetSum) {
            res.push_back(ans); 
        } else {
            // 3. Left aur right subtree mein jao
            path(root->left, targetSum - root->val, ans, res);
            path(root->right, targetSum - root->val, ans, res);
        }

        // 4. Backtrack: parent par wapas jaane se pehle current node ko list se hatao
        ans.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ans;
        path(root, targetSum, ans, res);
        return res;
    }
};