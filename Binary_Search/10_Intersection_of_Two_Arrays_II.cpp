/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:
    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2,2]
Example 2:
    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [4,9]
    Explanation: [9,4] is also accepted.
Constraints:
    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000
Follow up:
  What if the given array is already sorted? How would you optimize your algorithm?
  What if nums1's size is small compared to nums2's size? Which algorithm is better?
  What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/
class Solution {
public:
     int binarySearch(vector<int>& nums, int target)
     {
        if(nums.size() == 0)
        return -1;

        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            // Prevent (left + right) overflow
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            { 
                return mid;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            { 
                right = mid - 1; 
            }
        }

  // End Condition: left > right
        return -1;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        int itr;
        sort(nums1.begin(), nums1.end()); 
        sort(nums2.begin(), nums2.end()); 
        vector<int> result;
        
        if(nums1Size <= nums2Size) 
        {
            for(int i = 0; i < nums1Size; i++)
            {
                int index = binarySearch(nums2,nums1[i]);
                if(index != -1) 
                {
                    nums2[index] = -1;
                    sort(nums2.begin(), nums2.end());
                    result.push_back(nums1[i]);
                    continue;
                }
            }
        }
        else
        {
            for(int i = 0; i < nums2Size; i++)
            {
                int index = binarySearch(nums1,nums2[i]);
                if(index != -1)
                {
                    nums1[index] = -1;
                    sort(nums1.begin(), nums1.end());
                    result.push_back(nums2[i]);
                    continue;
                }
            }
        }     
        return result;
    }
};
