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

    vector<int> rightSideView(TreeNode* root) {

        // Edge Case
        if(root == NULL)
            return {};

        queue<TreeNode*> q;
        q.push(root);

        // Final Answer
        vector<int> ans;

        while(!q.empty())
        {
            // Current level ke total nodes
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* t = q.front();
                q.pop();

                // Agar ye current level ka last node hai,
                // to ye right side se dikhega
                if(i == levelSize - 1)
                    ans.push_back(t->val);

                // Next level ke nodes queue me daalo
                if(t->left != NULL)
                    q.push(t->left);

                if(t->right != NULL)
                    q.push(t->right);
            }
        }

        return ans;
    }
};