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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // take a dummy node and add it at the begining of the list
        ListNode node=ListNode(0, head);

        // map to store the preSum
        unordered_map<int, ListNode*> m;
        int preSum=0;

        ListNode* ptr = &node;

        //storing the preSum at each node
        while(ptr){
            preSum+=(ptr->val);
            m[preSum]=ptr;
            ptr=ptr->next;
        }

        preSum=0;
        ptr = &node;
        // now directly pointing the pointer to preSum->next avoiding all the zero points
        while(ptr){
            preSum+=(ptr->val);
            ptr->next=m[preSum]->next;
            ptr=ptr->next;
        }
        return node.next;
    }
};

// Explaination:

// A ListNode struct is defined to represent a node in a singly-linked list. It has an integer value (val) and a pointer to the next node (next).

// The removeZeroSumSublists function is defined to remove contiguous sublists whose sum is zero from the given linked list.

// A dummy node is created and added at the beginning of the list. This dummy node simplifies the logic for handling the head of the list.

// An unordered map m is used to store the prefix sum (preSum) of the linked list nodes encountered so far. The key is the prefix sum, and the value is a pointer to the node with that prefix sum.

// The first loop calculates the prefix sum for each node in the linked list and stores the node with that prefix sum in the map m.

// The second loop calculates the prefix sum again, but this time, it also updates the next pointers of the nodes to remove the zero sum sublists. If a sublist with zero sum is found, the next pointer of the current node is updated to skip over the sublist.

// Finally, the function returns the next pointer of the dummy node, which points to the head of the updated linked list.
