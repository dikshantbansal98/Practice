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
   
    ListNode **root;
    bool isPalindrome(ListNode* head) {
     
        root = &head;
        return is(head);
    }
    bool is(ListNode *tail){
        if(tail==NULL)
            return true;
        if(!is(tail->next)||(*root)->val!=tail->val) {
            return false;
        }
        *root = (*root)->next;
        return true;
    }
};