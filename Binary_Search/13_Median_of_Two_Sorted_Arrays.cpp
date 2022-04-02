/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000
    Explanation: merged array = [1,2,3] and median is 2.
Example 2:
    Input: nums1 = [1,2], nums2 = [3,4]
    Output: 2.50000
    Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Constraints:
    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1Size = nums1.size(); 
        int n2Size = nums2.size();
        int i = 0, j = 0;
        double median = 0;
        vector<int> result;
        while(i < n1Size && j < n2Size)
        {
            if(nums1[i] <= nums2[j]) 
            {
                result.push_back(nums1[i]);
                i++;
            }
            else
            {
                result.push_back(nums2[j]);
                j++;
            }
        }
        if(i == n1Size) 
        {
            while(j < n2Size)
            {
                result.push_back(nums2[j]);
                j++;
            }
        }
        else if(j == n2Size)
        {
            while(i < n1Size)
            {
                result.push_back(nums1[i]);
                i++;
            }
        }
        n1Size = result.size();
        if(n1Size % 2 == 0)
        {
            i = n1Size/2;
            median = (result[i] + result[i-1])/2.00000;
        }
        else
            median = result[n1Size/2];
        return median;
    }
};
