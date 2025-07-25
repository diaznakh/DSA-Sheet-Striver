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
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        /*
        we move the fast and slow nodes till 
        both of them intersect with the condition
        that fast->next and fast->next->next is
        not equal to NULL
        */
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};