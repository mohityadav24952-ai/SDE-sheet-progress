class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // Edge Case: Agar tree empty hai
        if(root == NULL)
            return {};

        queue<TreeNode*> q;
        q.push(root);

        // Final answer
        vector<vector<int>> res;

        // Direction maintain karega
        // true  -> Left to Right
        // false -> Right to Left
        bool leftToRight = true;

        while(!q.empty())
        {
            // Current level me kitne nodes hain
            int levelSize = q.size();

            // Current level ke answers store karne ke liye
            vector<int> temp(levelSize);

            // Forward aur Backward index
            int f = 0;
            int l = levelSize - 1;

            while(levelSize--)
            {
                TreeNode* t = q.front();
                q.pop();

                // Agar Left -> Right direction hai
                if(leftToRight)
                {
                    temp[f] = t->val;
                    f++;
                }

                // Agar Right -> Left direction hai
                else
                {
                    temp[l] = t->val;
                    l--;
                }

                // Next level ke liye children queue me daalo
                if(t->left != NULL)
                    q.push(t->left);

                if(t->right != NULL)
                    q.push(t->right);
            }

            // Current level answer me add karo
            res.push_back(temp);

            // Next level ke liye direction change karo
            leftToRight = !leftToRight;
        }

        return res;
    }
};