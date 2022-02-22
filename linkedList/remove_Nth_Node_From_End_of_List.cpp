/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]
Example 2:
    Input: head = [1], n = 1
    Output: []
Example 3:
    Input: head = [1,2], n = 1
    Output: [1]
Constraints:
    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
 
Follow up: Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == NULL)
            return NULL;
        else if(head->next ==0 && n==1)
            head = NULL;
        else
        {
            int count =0;
            ListNode *p1 = head;
            ListNode *p2 = head;
            for(int i=0; i<n; i++)
            {
                if(p2->next !=NULL)
                {
                    p2 = p2->next;
                    count++;
                }             
            }
            while(p2->next != NULL)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            // If count is less than given n, then we have to delete the first element
            if(count <n)
            {
                head = p1 ->next;
                p1->next = NULL;
            }
            else
            {
                ListNode *temp = p1->next;
                p1->next = p1->next->next;
                temp->next = NULL;
            }
        }
        return head;
    }
};
