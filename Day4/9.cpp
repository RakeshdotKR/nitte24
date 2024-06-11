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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        int size = 0;
        pair<ListNode*, ListNode*> p1,p2;

        while(curr){ //finding the kth term fro the beginning
            if(size==k-1){
                p1 = {prev,curr};
            }
            prev = curr;
            curr = curr->next;
            size++;
        }
        curr = head;
        int last = size - k;
        prev = NULL;

        while(last--){
            prev = curr;
            curr = curr -> next;
        }
        p2 = {prev,curr};
        
        //To swap
        int x = p1.second->val;
        p1.second->val = p2.second->val;
        p2.second->val = x;

        return head;
    }
};
