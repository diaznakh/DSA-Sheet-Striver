//merging 2 sorted linked lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        //the 2 edge cases in case either of the lists are empty
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        //we always need the lowest value to be l1
        if (list1->val > list2->val)
            std::swap(list1, list2);

        //result node to store the final merged list
        ListNode * res = list1;

        //first iteration for traversing through both the list
        //till both the lists have been exhausted
        while (list1 != NULL && list2 != NULL) {
            //tmp node to keep track of the lowest val from both lists
            ListNode * tmp = NULL;
            /*
            second iteration for moving the list1 node linearly
            and swapping it when its value is greater than list2
            */
            while(list1 != NULL && list1->val <= list2->val) {
                tmp = list1;
                list1 = list1->next;
            }
            //tmp->next brakes the link and connects it with the
            //second list.
            tmp->next = list2;
            std::swap(list1, list2);
        }
        return res;
    }
};