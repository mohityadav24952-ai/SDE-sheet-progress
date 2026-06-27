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
    bool isCousins(TreeNode* root, int x, int y) {

        if(root == NULL) return false;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int lvlsize = q.size();

            bool foundX = false;
            bool foundY = false;

            // process current level
            for(int i = 0; i < lvlsize; i++) {

                TreeNode* node = q.front();
                q.pop();

                // check current node
                if(node->val == x) foundX = true;
                if(node->val == y) foundY = true;

                // IMPORTANT: check siblings (same parent case)
                if(node->left && node->right) {
                    if((node->left->val == x && node->right->val == y) ||
                       (node->left->val == y && node->right->val == x)) {
                        return false; // same parent → not cousins
                    }
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            // if both found at same level → cousins
            if(foundX && foundY)
                return true;

            // if only one found → not possible in same level
            if(foundX || foundY)
                return false;
        }

        return false;
    }
};