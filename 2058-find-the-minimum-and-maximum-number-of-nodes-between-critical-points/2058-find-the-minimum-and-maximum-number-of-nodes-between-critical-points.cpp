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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* p = head;
        ListNode* prev = NULL;
        ListNode* nxt = p->next;
        int c = 1;

        vector<int>pos;

        while((p->next->next)!=NULL){
            prev=p;
            p=nxt;c++;
            nxt=nxt->next;

            if((p->val)>(prev->val) && (p->val)>(nxt->val)) pos.push_back(c);

            if((p->val)<(prev->val) && (p->val)<(nxt->val)) pos.push_back(c);
        }


       if(pos.size() < 2) return {-1,-1};

       vector<int>ans;

       int nn = pos.size();
       int maxd = pos[nn-1]-pos[0];
       int mind = pos[nn-1]-pos[nn-2];

       for(int i=1;i<nn;i++){
           maxd=max(maxd,pos[i]-pos[i-1]);
           mind=min(mind,pos[i]-pos[i-1]);
       }

       ans.push_back(mind);
       ans.push_back(maxd);

        return ans;
    }
};