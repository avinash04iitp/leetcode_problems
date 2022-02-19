/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:
    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]
Example 2:
    Input: nums = [0]
    Output: [0]
Constraints:
    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1
Follow up: Could you minimize the total number of operations done?
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int len = nums.size();
        //int j=0;
        int flag = 0;
        int j = -1;
        for(int i=0; i<len; i++)
        {
            if(nums[i] != 0 && flag == 0)
                continue;
            else if(nums[i]==0 && flag==0)
            {
                if(j==-1)
                    j=i;
                flag = 1;
            }
            else if(nums[i]!=0 && flag ==1)
            {
                nums[j] = nums[i];
                nums[i] = 0;
                j++;
            }
        }
    }
};
