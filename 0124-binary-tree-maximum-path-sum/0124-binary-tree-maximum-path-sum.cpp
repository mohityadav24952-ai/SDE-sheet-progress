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
// class Solution {
// public:
//     int maxPathSum(TreeNode* root) {
//         int maxi = INT_MIN ;
//         maxpathdown(root , maxi);
//         return maxi ;
//     }

//     int maxpathdown(TreeNode* node , int &maxi){
//         if(node == NULL) return 0;

//         int left = max(0, maxpathdown(node->left , maxi));
//         int right = max(0,maxpathdown(node->right , maxi ));

//         maxi = max(maxi , left+right+node->val);

//         return max(left , right) + node->val ;
//     }
// };

class Solution{
    public:
        int maxi ;

        int solve(TreeNode* root){
            if (root==NULL) return 0;

            int l = solve(root->left);
            int r = solve(root->right);

            int neeche_hi_mil_gya = l + r + root->val;

            int koi_ek_acha_mila = max(l,r)+root->val;

            int only_root_acha = root->val ;

            maxi = max({maxi,neeche_hi_mil_gya,koi_ek_acha_mila,only_root_acha} );

            return max(koi_ek_acha_mila,only_root_acha);
        }

        int maxPathSum(TreeNode* root){
            maxi = INT_MIN;
            solve(root);
            return maxi;
        }

};