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

        // jab tak answer nahi milta
        while(root != NULL){

            // dono nodes left subtree me hain
            if(root->val > p->val && root->val > q->val){

                root = root->left;
            }

            // dono nodes right subtree me hain
            else if(root->val < p->val && root->val < q->val){

                root = root->right;
            }

            // ek left me aur ek right me
            // ya root hi p/q hai
            else{

                return root;
            }
        }

        return NULL;
    }
};


//-------------------RECURSIVE SOL-----------EASY TO RIGHT BUT o(H)--SC

// class Solution {
// public:

//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

//         // Base case
//         if(root == NULL) return NULL;

//         // Dono nodes current root se chhote hain
//         // LCA left subtree me hoga
//         if(root->val > p->val && root->val > q->val){

//             return lowestCommonAncestor(root->left, p, q);
//         }

//         // Dono nodes current root se bade hain
//         // LCA right subtree me hoga
//         if(root->val < p->val && root->val < q->val){

//             return lowestCommonAncestor(root->right, p, q);
//         }

//         // Ek left me aur ek right me hai
//         // Ya current root hi p/q hai
//         // To current root hi LCA hai
//         return root;
//     }
// };