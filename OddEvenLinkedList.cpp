/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        int flag = 0;
        ListNode *curr = head, *temp,*oddLast =NULL, *evenStart;
        int count = 0;
        while(curr != NULL && curr->next != NULL){
            temp = curr->next;
            count++;
            if(count == 2){
                evenStart = curr;
            }
            if(curr->next->next == NULL && (count %2)) oddLast = curr;
            curr->next = curr->next->next;
            curr = temp;
               
        }
        if(!oddLast)
            oddLast = curr;
        oddLast->next = evenStart;
        return head;
        
        
    }
};
