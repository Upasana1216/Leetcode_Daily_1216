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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start=list1, *end = list1;
        
        for(int i=0; i<a-1; i++){
            start=start->next;
            end=end->next;
        }

        for(int i=0; i<=b-a; i++)
            end=end->next;

        start->next = list2;
        while(list2->next)
            list2 = list2->next;

        list2->next = end->next;
        
        return list1;
    }
};
