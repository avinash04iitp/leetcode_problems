/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
Example 1:
    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
    Explanation: 9 exists in nums and its index is 4
Example 2:
    Input: nums = [-1,0,3,5,9,12], target = 2
    Output: -1
    Explanation: 2 does not exist in nums so return -1
Constraints:
    1 <= nums.length <= 104
    -104 < nums[i], target < 104
    All the integers in nums are unique.
    nums is sorted in ascending order.
*/
class Solution {
    int mid;
    void binarySearch(vector<int>& nums, int p, int q, int target)
    {
        if(p<=q)
        {
            mid = (p+q)/2;
            if(nums[mid] == target) return ;
        
            else if(nums[mid]<target)
            {
                binarySearch(nums, mid+1, q, target);
            }
            else if(nums[mid]>target)
            {
                binarySearch(nums, p, mid-1, target);
            } 
        }
    }
public:
    int search(vector<int>& nums, int target) 
    {
        int end = nums.size()-1;
        binarySearch(nums, 0, end, target);
        if(nums[mid]==target) return mid;
        else return -1;
    }
};
