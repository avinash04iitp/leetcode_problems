/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2]
Example 2:
    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [9,4]
    Explanation: [4,9] is also accepted.
Constraints:
    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000
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
/*    
    bool binarySearch(vector<int>& nums,int p, int q, int target)
    {
        if(p<=q)
        {
            int mid = (p+q)/2;
            if(nums[mid] == target) return true;
        
            else if(nums[mid]<target)
            {
                binarySearch(nums, mid+1, q, target);
            }
            else if(nums[mid]>target)
            {
                binarySearch(nums, p, mid-1, target);
            } 
            //else return false;
        }
        return false;
    }
*/    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
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
                //if(binarySearch(nums2, 0, nums2Size-1, nums1[i]) != -1)
                if(binarySearch(nums2,nums1[i]) != -1)

                {
                    std::vector<int>::iterator it;
                    it = std::find (result.begin(), result.end(), nums1[i]);
                    if (it != result.end())
                    {
                        //result.push_back(nums1[i]);
                        continue;
                    }
                    else result.push_back(nums1[i]);
                }
            }
        }
        //if(nums1Size <= nums2Size) 
        else
        {
            for(int i = 0; i < nums2Size; i++)
            {
                if(binarySearch(nums1, nums2[i]) != -1)
                {
                    std::vector<int>::iterator it;
                    it = std::find (result.begin(), result.end(), nums2[i]);
                    if (it != result.end())
                    {
                        //result.push_back(nums1[i]);
                        continue;
                    }
                    else result.push_back(nums2[i]);
                }
            }
        }
              
        return result;
    }
};
