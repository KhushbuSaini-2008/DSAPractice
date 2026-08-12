class Solution {
public:

    int lengthofLL(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL)
            return head;

        int n = lengthofLL(head);

        k = k % n;

        if(k == 0)
            return head;

        // Find last node
        ListNode* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        // Make circular
        temp->next = head;

        // Find new tail
        ListNode* newTail = head;

        for(int i = 1; i < n-k; i++) {
            newTail = newTail->next;
        }

        // New head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return newHead;
    }
};