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

 //---------RECURSIVE SOL ME SPACE O(h) use hoti hai---------
// class Solution {
// public:

//     TreeNode* insertIntoBST(TreeNode* root, int val) {

//         // Case 1: agar tree empty hai
//         // yahi naya node banega root
//         if(root == NULL){
//             return new TreeNode(val);
//         }

//         // BST rule:
//         // agar value chhoti hai → left me insert karo
//         if(val < root->val){

//             root->left = insertIntoBST(root->left, val);
//         }

//         // agar value badi hai → right me insert karo
//         else{

//             root->right = insertIntoBST(root->right, val);
//         }

//         // updated tree root return karo
//         return root;
//     }
// };



// ----------ITERATIVE ME NO STACK SPACE ....SO O(h)------
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // agar tree empty hai
        if(root == NULL){
            return new TreeNode(val);
        }

        TreeNode* curr = root;

        while(true){

            // agar value chhoti hai → left jao
            if(val < curr->val){

                // agar left NULL hai → yahi insert karo
                if(curr->left == NULL){
                    curr->left = new TreeNode(val);
                    break;
                }

                // warna aage move karo
                curr = curr->left;
            }

            // agar value badi hai → right jao
            else{

                // agar right NULL hai → yahi insert karo
                if(curr->right == NULL){
                    curr->right = new TreeNode(val);
                    break;
                }

                // aage move karo
                curr = curr->right;
            }
        }

        return root;
    }
};