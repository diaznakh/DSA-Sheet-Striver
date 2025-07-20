/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode* a = headA;
        ListNode* b = headB;
        //swaps the dummy node a or b just
        //as it reaches NULL
        while (a != b) {
            //if a = NULL it is assigned to headB
            //if not hten it is shifted by one node
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        return a;
    }
};