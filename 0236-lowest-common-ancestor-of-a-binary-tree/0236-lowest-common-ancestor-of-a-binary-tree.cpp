/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base case:
        // Tree khatam ho gaya
        if(root == NULL) return NULL;

        // Agar current node hi p ya q hai
        // Is node ko upar return kar do
        if(root == p || root == q){
            return root;
        }

        // Left subtree me answer dhoondo
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Right subtree me answer dhoondo
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Agar dono side se node mili
        // Current root hi LCA hai
        if(left != NULL && right != NULL){
            return root;
        }

        // Sirf left side se answer mila
        if(left != NULL){
            return left;
        }

        // Sirf right side se answer mila
        return right;
    }
};