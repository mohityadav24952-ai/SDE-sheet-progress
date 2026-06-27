/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool checkBST(TreeNode* root, long long minVal, long long maxVal) {

        // empty tree is valid
        if(root == NULL) return true;

        // current node must lie in range
        if(root->val <= minVal || root->val >= maxVal)
            return false;

        // left subtree → max becomes root value
        bool left = checkBST(root->left, minVal, root->val);

        // right subtree → min becomes root value
        bool right = checkBST(root->right, root->val, maxVal);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {

        return checkBST(root, LLONG_MIN, LLONG_MAX);
    }
};