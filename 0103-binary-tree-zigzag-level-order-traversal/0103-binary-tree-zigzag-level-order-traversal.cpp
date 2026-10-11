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
    void lorder(TreeNode* root , vector<vector<int>>&res){
        if(root==NULL) return;

        queue<TreeNode*>q;
        q.push(root);

          int ltor = 1;

        while(!q.empty()){

            int lvlsize  = q.size();
            vector<int>temp(lvlsize);
          

            int end = lvlsize-1;

            for(int i=0 ; i<lvlsize ;i++){


                TreeNode* node = q.front();
                q.pop();

                if(ltor){
                    temp[i]=node->val;                   
                }
                else
                 {
                    temp[end]=node->val;
                    end--;
                }

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);



            
            }
            res.push_back(temp);
            ltor = 1-ltor;

        }
    }



    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;

        lorder(root,res);

        return res;
    }
};