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
        int node_cnt = 1;
        ListNode * cur = head;
        while (cur->next) {
            ++node_cnt;
            cur = cur->next;
        }
        k = node_cnt - k % node_cnt;
        if (k == 0)
            return head;
        cur->next = head;
        while (k > 0) {
            --k;
            cur = cur->next;
        }
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};
