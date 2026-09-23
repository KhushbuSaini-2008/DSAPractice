class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* ans = new ListNode(-1);
        ListNode* it = ans;

        int carry = 0;

        while (temp1 || temp2 || carry) {

            int data1 = (temp1) ? temp1->val : 0;
            int data2 = (temp2) ? temp2->val : 0;

            int sum = data1 + data2 + carry;

            int digit = sum % 10;
            carry = sum / 10;

            it->next = new ListNode(digit);
            it = it->next;

            if (temp1)
                temp1 = temp1->next;

            if (temp2)
                temp2 = temp2->next;
        }

        return ans->next;
    }
};