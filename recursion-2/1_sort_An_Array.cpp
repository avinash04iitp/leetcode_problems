/*
Given an array of integers nums, sort the array in ascending order.
Example 1:
    Input: nums = [5,2,3,1]
    Output: [1,2,3,5]
Example 2:
    Input: nums = [5,1,1,2,0,0]
    Output: [0,0,1,1,2,5]
Constraints:
    1 <= nums.length <= 5 * 104
    -5 * 104 <= nums[i] <= 5 * 104
*/
/*
class Solution {
public:
    int merge(int nums[], int start, int mid, int mid2, int last)
    {
        //int i = 0;
        while(start <= mid || mid2 <= last)
        {
            if(nums[start] <= nums[mid2])
            {
                start ++;
            }
            else if(nums[start] > nums[mid2])
            {
                swap(nums[start], nums[mid2]);
                mid2 ++;
            }
        }
        return 0;
    }
    int mergeSort(int nums[], int start, int last)
    {
        if(start == last) return 0;
        int mid = (start + last)/2;
        mergeSort(nums, start, mid);
        int mid2 = mid+1;
        mergeSort(nums, mid2, last);
        merge(nums, start, mid, mid2, last);
        return 0;
    }
    int sortArray(int nums[]) 
    {      
  
        //auto arrlen = end(nums) - begin(nums);
        //int lastIndex = nums.size() -1;
        //for(int i=0; i<)
        //auto arrlen = std::ssize(nums);
        int len = sizeof(nums)/sizeof(nums[0]);

        int lastIndex = len-1;
        int startIndex = 0;
        mergeSort(nums, startIndex, lastIndex);
        return nums;
    }    
};*/
//Ref- Sol:- https://leetcode.com/explore/learn/card/recursion-ii/470/divide-and-conquer/2944/discuss/1811017/Clean-C++-merge-sort
class Solution {
public:
    vector<int> merge(vector<int>& left, vector<int>& right) {
        left.push_back(INT_MAX);
        right.push_back(INT_MAX);
        int i = 0, j = 0;
        vector<int> result;
        while (i != left.size()-1 || j != right.size()-1) {
            int p = 0;
            if (left[i] > right[j]) {
                p = right[j];
                j++;
            } else {
                p = left[i];
                i++;
            }
            result.push_back(p);
        }
        return result;
    }
    
    vector<int> mergeSort(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return vector<int>();
        if (lo + 1 == hi) return vector<int>{nums[lo]};
        vector<int> left = mergeSort(nums, lo, (hi+lo)/2);
        vector<int> right = mergeSort(nums, (hi+lo)/2, hi);
        return merge(left, right);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size());    
    }
};
