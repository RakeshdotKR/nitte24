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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ptr1=head->next;
        ListNode *ptr2=head;
        int sum = 0;
        while(ptr1!=NULL){
            if(ptr1->val == 0){
                ptr2->val = sum;
                if(ptr1->next!=NULL){
                    ptr2 = ptr2->next;
                }
                sum = 0;
            }
            else{
                sum+=ptr1->val;
            }
            ptr1 = ptr1->next;
        }
    ptr2->next = NULL;
    return head;
    }
};
