class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast){
            fast = fast->next;
            if(fast){
                fast = fast -> next;//fast = fast->next->next;
                slow = slow -> next;
            }
        }
        return slow;
    }
};
