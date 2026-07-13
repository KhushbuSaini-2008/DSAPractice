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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        int count=0;
        while(temp!=NULL && count<k){
            count++;
            temp=temp->next;
        }
        if(count==k){
            int i=0;
            ListNode* prev=NULL;
            ListNode* curr=head;
            ListNode*forword=NULL;
            while(i<k){
                forword=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forword;
                i++;
            }
            ListNode * recursionkahead=reverseKGroup(forword,k);
            head->next=recursionkahead;
            return prev;

        }
        else{
            return head;
        }
    }
};