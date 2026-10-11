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
 void lorder(TreeNode* root , vector<int>&temp){
        if(root==NULL) return;

        queue<TreeNode*>q;
        q.push(root);

          int ltor = 1;

        while(!q.empty()){

            int lvlsize  = q.size();
            
          


            for(int i=0 ; i<lvlsize ;i++){


                TreeNode* node = q.front();
                q.pop();

                if(i==lvlsize-1) temp.push_back(node->val);

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);



            
            }
            
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>temp;


        lorder(root,temp);

        return temp;

    }
};