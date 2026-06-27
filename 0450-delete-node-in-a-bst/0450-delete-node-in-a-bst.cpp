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

    // helper: find minimum node in BST (inorder successor)
    TreeNode* findMin(TreeNode* node){

        while(node->left != NULL){
            node = node->left;
        }

        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        // edge case: empty tree
        if(root == NULL) return NULL;

        TreeNode* curr = root;
        TreeNode* parent = NULL;

        // ================================
        // STEP 1: SEARCH NODE ITERATIVELY
        // ================================
        while(curr != NULL && curr->val != key){

            parent = curr;

            if(key < curr->val){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }

        // ❌ key not found
        if(curr == NULL) return root;

        // ================================
        // STEP 2: HANDLE 3 CASES
        // ================================

        // CASE 1: LEAF NODE
        if(curr->left == NULL && curr->right == NULL){

            // if node is root itself
            if(parent == NULL) return NULL;

            // detach from parent
            if(parent->left == curr) parent->left = NULL;
            else parent->right = NULL;

            delete curr;
        }

        // CASE 2A: ONLY RIGHT CHILD
        else if(curr->left == NULL){

            if(parent == NULL) return curr->right;

            if(parent->left == curr) parent->left = curr->right;
            else parent->right = curr->right;

            delete curr;
        }

        // CASE 2B: ONLY LEFT CHILD
        else if(curr->right == NULL){

            if(parent == NULL) return curr->left;

            if(parent->left == curr) parent->left = curr->left;
            else parent->right = curr->left;

            delete curr;
        }

        // ================================
        // CASE 3: TWO CHILDREN
        // ================================
        else{

            // find inorder successor (smallest in right subtree)
            TreeNode* successorParent = curr;
            TreeNode* successor = curr->right;

            while(successor->left != NULL){
                successorParent = successor;
                successor = successor->left;
            }

            // copy successor value to current node
            curr->val = successor->val;

            // now delete successor node (it has at most right child)
            if(successorParent->left == successor){
                successorParent->left = successor->right;
            }
            else{
                successorParent->right = successor->right;
            }

            delete successor;
        }

        return root;
    }
};