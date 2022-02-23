/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:
    Input: head = [1,2,6,3,4,5,6], val = 6
    Output: [1,2,3,4,5]
Example 2:
    Input: head = [], val = 1
    Output: []
Example 3:
    Input: head = [7,7,7,7], val = 7
    Output: []
Constraints:
    The number of nodes in the list is in the range [0, 104].
    1 <= Node.val <= 50
    0 <= val <= 50
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
    ListNode* removeElements(ListNode* head, int val) 
    {
        // Case-1: When the linked list has no element.
        if(head == NULL) return NULL;
        // Case-2: When the linked list has single element and that too is equal to val.
        else if(head->next == NULL && head->val == val)
        {
            return NULL;
        }       
        else
        {
            // Case-1: When the first element of linked list itself contains val.
            while(head->val == val && head !=NULL)
            {
                ListNode *curr = head;
                ListNode *temp = curr;
                if(curr->val == val)
                {
                    head = curr->next;
                    curr -> next = NULL;
                    curr = head;
                    temp = curr;
                }
                if(curr == NULL || head == NULL) return head;
            }
            // Case-2: When the first element of linked list does not contain val.
            ListNode *curr = head;
            ListNode *temp = curr;
            while(head != NULL && curr->next != NULL)
            {
                if(curr->val == val)
                {
                    temp->next = curr->next;
                    curr->next = NULL;
                    curr = temp->next;                
                }
                else
                {
                    temp = curr;
                    curr = curr->next;  
                }
            }
            if(curr->next == NULL && curr->val == val)
            {
                temp->next = NULL;
                delete curr;
            }
        }
        return head;
    }
};
