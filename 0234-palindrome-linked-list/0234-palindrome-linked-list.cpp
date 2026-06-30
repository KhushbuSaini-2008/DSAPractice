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
int getlength(ListNode *&head){
    ListNode* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
ListNode* midofll(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode * reverseofll(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    while(curr!=NULL){
        ListNode* forword=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forword;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        int length=getlength(head);
    ListNode* mid=midofll(head);
ListNode* finalmid=NULL;
if(length&1){
    finalmid=mid->next;
}
else{
    finalmid=mid;
}
ListNode* reverse=reverseofll(finalmid);
ListNode*temp=head;
while(temp!=NULL && reverse!=NULL){
    if(temp->val!=reverse->val){
        return false;
    }
    temp=temp->next;
    reverse=reverse->next;
}
return true;
        
    }
};