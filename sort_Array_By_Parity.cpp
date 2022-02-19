/*
#Sort Array By Parity

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.
Example 1:
    Input: nums = [3,1,2,4]
    Output: [2,4,3,1]
    Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:
    Input: nums = [0]
    Output: [0]
Constraints:
    1 <= nums.length <= 5000
    0 <= nums[i] <= 5000
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int len = nums.size();
        for(int i=0; i<len-1; i++)
        {
            // Case-1:- (odd-odd) - When first and last elements are odd.
            if((nums[i]%2 != 0) && (nums[len-1]%2 != 0))
            {
                len --;
                i--;
            }
          // Case-1:- (odd-even) - When first is odd and last elements is even.
            else if((nums[i]%2 != 0) && (nums[len-1]%2 == 0))
            {
                swap(nums[i], nums[len-1]);
                len--;
            }
          // Case-1:- (even-odd) - When first is even and last elements is odd.
            else if((nums[i]%2 == 0) && (nums[len-1]%2 != 0))
            {
                len --;
            }
          // Case-1:- (even-even) - When first and last elements are even.
            else if((nums[i]%2 == 0) && (nums[len-1]%2 == 0))
            {
                continue;
            }
        }
        return nums;
    }
};
