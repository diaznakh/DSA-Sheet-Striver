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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int count = 1;

        ListNode* counter = head;

        while (counter->next != NULL) {
            counter = counter->next;
            count++;
        }
        counter->next = head;

        k = k % count;
        k = count - k;

        while (k--)
            counter = counter->next;

        head = counter->next;
        counter->next = NULL;

        return head;
    }
};