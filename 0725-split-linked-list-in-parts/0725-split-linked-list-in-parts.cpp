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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        auto it=head;
        while(it){
            n++;
            it=it->next;
        }
        int idealpartsize=n/k;
        int extrapartsize=n%k;
        vector< ListNode* >ans(k,NULL);
        it=head;
        for(int i=0;i<k && it;i++){
            ans[i]=it;
            int actualpartsize=idealpartsize+(extrapartsize-->0?1:0);
           
            for(int j=0;j<actualpartsize-1;j++){
                it=it->next;
            }
        
            auto nextpart= it->next;
            it->next=NULL;
            it=nextpart;
            
        }
        return ans;
        
    }
};