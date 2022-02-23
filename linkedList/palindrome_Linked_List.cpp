/*
Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
    Input: head = [1,2,2,1]
    Output: true
Example 2:
    Input: head = [1,2]
    Output: false
Constraints:
    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9
Follow up: Could you do it in O(n) time and O(1) space?
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

// Main Logic:- Reverse the half linked list(mid to end) and then compare the first half to second half
class Solution {
public:
    // Reverse the half linked list(mid to end) 
    ListNode* reverseLinkedList(ListNode* head1, ListNode* lastNode, int count)
    {
        ListNode *temp1;
        ListNode *temp2;
        for(int i=1; i<count; i++)
        {
            temp1 = head1;
            temp2 = lastNode->next;
            lastNode ->next = head1;
            head1 = head1->next;
            temp1->next = temp2;
        }
        return head1;
    }   
    bool isPalindrome(ListNode* head) 
    {
        // Case-1:- When LL has 0/1 element.
        if(head == NULL || head->next == NULL)
            return head;
        else
        {
            ListNode *curr = head;
            int count = 1;
            //TO get the total number of nodes
            while(curr->next != NULL)
            {
                curr = curr->next;
                count ++;
            }
            // Case-2:-When there are only two nodes and each value is equal.
            if(count == 2 && head->val == (head->next)->val )
                return true;
            //Case-3: When there are 3 or more elements.
            else
            {
                ListNode *tempHead = head;
                ListNode *prev;
                int tempCount = count;
                if(count%2 != 0)
                    tempCount = count+1;
                for(int i=1; i<=tempCount/2; i++)
                {
                    prev = tempHead;
                    tempHead = tempHead->next;
                }
                ListNode *head1 = reverseLinkedList(tempHead, curr, count/2);
                // Compare the first half with the second half.
                prev->next = head1;
                for(int i=1; i<=count/2; i++)
                {
                    if(head->val == head1->val)
                    {
                        head = head->next;
                        head1 = head1->next;
                    }
                    else
                        return false;                     
                }
                return true;
            }            
        }            
    }
};
