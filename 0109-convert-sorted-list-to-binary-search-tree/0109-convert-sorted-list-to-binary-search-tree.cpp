/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    ListNode* findMiddle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // slow reaches middle
        // fast reaches end
        while(fast != NULL && fast->next != NULL) {

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // split list into two halves
        if(prev != NULL)
            prev->next = NULL;

        return slow;
    }

    TreeNode* buildBST(ListNode* head) {

        if(head == NULL)
            return NULL;

        // single node case
        if(head->next == NULL)
            return new TreeNode(head->val);

        // find middle node (root)
        ListNode* mid = findMiddle(head);

        TreeNode* root = new TreeNode(mid->val);

        // left half becomes left subtree
        root->left = buildBST(head);

        // right half becomes right subtree
        root->right = buildBST(mid->next);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        return buildBST(head);
    }
};