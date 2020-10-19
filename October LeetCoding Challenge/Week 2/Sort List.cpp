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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode * f_node = head;
        while (f_node->next) {
            ListNode * s_node = f_node->next;
            while (s_node) {
                if (s_node->val < f_node->val)
                    swap(s_node->val, f_node->val);
                s_node = s_node->next;
            }
            f_node = f_node->next;
        }
        return head;
    }
};
