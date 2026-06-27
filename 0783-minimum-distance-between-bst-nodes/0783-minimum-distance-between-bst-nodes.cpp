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

    // Inorder traversal me previous visited node store karega
    TreeNode* previous = NULL;

    // Minimum difference store karega
    int minimum_Difference = INT_MAX;

    void inorder(TreeNode* root)
    {
        // Base Case
        if (root == NULL)
            return;

        // STEP 1:
        // Left subtree traverse karo
        inorder(root->left);

        // STEP 2:
        // Current node pe aaye

        // Agar previous node exist karti hai,
        // to current aur previous ka difference nikalo
        if (previous != NULL)
        {
            minimum_Difference = min(minimum_Difference,
                                     root->val - previous->val);
        }

        // Current node ko previous bana do
        previous = root;

        // STEP 3:
        // Right subtree traverse karo
        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root)
    {
        // Inorder traversal start karo
        inorder(root);

        // Final answer return karo
        return minimum_Difference;
    }
};