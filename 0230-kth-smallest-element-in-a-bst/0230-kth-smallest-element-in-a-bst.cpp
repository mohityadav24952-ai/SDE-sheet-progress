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

    // Kitne nodes visit ho chuke hain
    int count = 0;

    // Final answer
    int answer = -1;

    void inorder(TreeNode* root, int k)
    {
        // Base Case
        if(root == NULL)
            return;

        // STEP 1:
        // Left subtree traverse karo
        inorder(root->left, k);

        // STEP 2:
        // Current node pe aaye

        // Ek aur node visit ho gayi
        count++;

        // Agar ye kth node hai
        if(count == k)
        {
            answer = root->val;
            return;
        }

        // STEP 3:
        // Right subtree traverse karo
        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        // Inorder traversal start karo
        inorder(root, k);

        return answer;
    }
};