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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode * temp = dummy;

        //for any carry generated
        int carry = 0;

        //iteration till any of the three becomes NULL or 0
        while(l1 != NULL || l2 != NULL || carry !=0 ){
            //sum is initialized to 0 at start of every iteration
            int sum = 0;
            if(l1!=NULL){
                sum += l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum += l2->val;
                l2=l2->next;
            }
            //for first one carry is always 0
            sum+=carry;
            carry = sum/10;
            //creating a new node and its value is assigned to sum%10
            ListNode*node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};