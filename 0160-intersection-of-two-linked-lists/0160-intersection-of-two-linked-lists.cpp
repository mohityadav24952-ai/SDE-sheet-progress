class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode *h1 = headA;
        ListNode *h2 = headB;

        while (h1 != h2) {
            // Agar h1 end par pahuch gaya, toh usko dusri list (headB) par bhej do
            if (h1 == NULL) {
                h1 = headB;
            } else {
                h1 = h1->next;
            }

            // Agar h2 end par pahuch gaya, toh usko pehli list (headA) par bhej do
            if (h2 == NULL) {
                h2 = headA;
            } else {
                h2 = h2->next;
            }
        }

        // Jab dono mil jayenge (ya dono ek sath NULL ho jayenge no-intersection pe), loop tut jayega
        return h1; 
    }
};