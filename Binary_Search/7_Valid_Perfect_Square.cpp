/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

Example 1:
    Input: num = 16
    Output: true
Example 2:
    Input: num = 14
    Output: false
Constraints:
    1 <= num <= 2^31 - 1
*/
class Solution {
public:
    bool isPerfectSquare(int num)
    {
        long int mid = num/2;
        long int i;
        for(i = 1; i<mid; i=i*2)
        {
            if(i*i == num) return true;
            else if(i*i > num)
                break;
        }
        for(long int j = i/2; j <= i; j++)
        {
            if(j * j == num) return true;
        }
        return false;
    }
};
