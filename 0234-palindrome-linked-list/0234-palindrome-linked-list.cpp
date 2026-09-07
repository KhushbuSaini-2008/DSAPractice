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
ListNode* findmid(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL&& fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* reverseLinkedList(ListNode* head){
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(curr!=NULL){
        ListNode* forword=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forword;
    }
return prev;
}
int length(ListNode* head ){
    ListNode* temp=head;
    int count=0;
    while(temp!=NULL){
count++;
temp=temp->next;
    }
    return count;
}
    bool isPalindrome(ListNode* head) {
        if(head==NULL && head->next==NULL){
            return true;
        }
        //find mid

        ListNode* mid=findmid(head);
        int len=length(head);
        // odd from mid next
        ListNode* finalmid=NULL;
        if(len%2!=0){
            finalmid=mid->next;
        }
        
        //even from mid
         else{
            finalmid=mid;
         }
        //reverse from mid
auto reverse=reverseLinkedList(finalmid);
         ListNode* temp=head;
         while( temp!=NULL && reverse!=NULL ){
            if(temp->val!=reverse->val){
                return false;
            }
            temp=temp->next;
           reverse=reverse->next;
         }
         return true;
    }
};