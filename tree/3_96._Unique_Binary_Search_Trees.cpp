/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:
    Input: n = 3
    Output: 5
Example 2:
    Input: n = 1
    Output: 1
Constraints:
    1 <= n <= 19
*/
class Solution {
public:
    int numTrees(int n)
    {
        int leftCount = 1;
        int rightCount = 1;
        int sum = 0;
        if(n==1) return 1;
        if(n == 2) return 2;
        if(n > 2)
        {
            for(int i = 1; i<=n; i++)
            {
                leftCount = numTrees(i-1);
                rightCount = numTrees(n-i);
                sum = sum + leftCount * rightCount ;
            }     
        }
        else
            sum = sum + leftCount * rightCount;
        return sum;
    }
};
