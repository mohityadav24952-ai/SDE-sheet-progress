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
    void lorder(TreeNode* root , vector<double>&ans){
        if(root==NULL) return ;

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int lvlsize = q.size();

            double sum=0;

            vector<int>temp;

            for(int i=0 ; i<lvlsize;i++){

                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);
               
               if(node->left) q.push(node->left);

               if(node->right) q.push(node->right);



            }



            for(int i=0 ; i<temp.size();i++){
                 sum += temp[i];
            }

            ans.push_back((double)sum/temp.size());



        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;

        lorder(root,ans);

        return ans;
    }
};