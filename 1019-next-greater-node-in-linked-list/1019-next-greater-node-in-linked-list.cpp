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
class Solution {
public:
    ListNode* reverselist(ListNode* head){
        ListNode* prev = NULL ;
        ListNode* p = head ;

        while(p!=NULL){
         
         ListNode* next = p->next ;

         p->next = prev ;
         prev = p ;
         p = next ;


        }
        return prev ;
    }

    vector<int> nextLargerNodes(ListNode* head) {
    // 1. Reverse the list to process from end to start
    ListNode* rhead = reverselist(head);
    stack<int> st;
    vector<int> ans;

    // 2. Iterate through the reversed list
    while (rhead != NULL) {
        // Pop elements smaller than current from the stack
        while (!st.empty() && st.top() <= rhead->val) {
            st.pop();
        }

        // If stack is empty, no greater node exists
        if (st.empty()) {
            ans.push_back(0);
        } else {
            // The top of the stack is the next greater node
            ans.push_back(st.top());
        }

        // Push current node value to stack
        st.push(rhead->val);
        rhead = rhead->next;
    }

    // 3. Reverse the answer vector because we processed the list backwards
    reverse(ans.begin(), ans.end());
    return ans;
}
};