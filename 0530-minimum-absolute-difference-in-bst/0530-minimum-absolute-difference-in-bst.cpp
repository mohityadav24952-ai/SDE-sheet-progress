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

    // Previous visited node (Inorder traversal me)
    TreeNode* previous = NULL;

    // Final answer store karega
    int minimum_Difference = INT_MAX;

    void inorder(TreeNode* root)
    {
        // Base Case:
        // Agar node NULL hai to wapas chale jao
        if (root == NULL)
            return;

        // STEP 1:
        // Pehle left subtree ko completely traverse karo
        inorder(root->left);

        // STEP 2:
        // Ab current node pe aaye hain

        // Agar previous node exist karti hai,
        // to current aur previous ka difference nikalo
        if (previous != NULL)
        {
            minimum_Difference = min(minimum_Difference,
                                     root->val - previous->val);
        }

        // Current node ko previous bana do,
        // taaki inorder me aane wali next node isse compare kar sake
        previous = root;

        // STEP 3:
        // Ab right subtree traverse karo
        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root)
    {
        // Inorder traversal start karo
        inorder(root);

        // Minimum difference return karo
        return minimum_Difference;
    }
};