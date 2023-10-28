class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* mid = head;
        while (mid->next) {
            ListNode* n = new ListNode(gcd(mid->val, mid->next->val));
            n->next = mid->next;
            mid->next = n;
            mid = n->next;
        }
        return head;
    }
};