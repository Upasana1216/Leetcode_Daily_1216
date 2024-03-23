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
    void reorderList(ListNode* head) {
        ListNode* s = head, *f=head;

        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }

        ListNode* prev=NULL, *nex = NULL,*curr = s->next;
        
        while(curr){
            nex= curr->next;
            curr->next = prev;
            prev = curr;
            curr=nex;
        }
        s->next = nullptr;
        
        ListNode *temp1 = head, *temp2=prev;
        
        while(temp1!=NULL && temp2!=NULL){
            ListNode* t=temp1->next;
            temp1->next = temp2;
            ListNode* t2 = temp2->next;
            temp2->next = t;
            temp1 = t;
            temp2 = t2;
        }
        
    }
};
