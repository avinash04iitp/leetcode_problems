/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

Example 1:
    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:
    Input: numbers = [2,3,4], target = 6
    Output: [1,3]
    Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:
    Input: numbers = [-1,0], target = -1
    Output: [1,2]
    Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
Constraints:
    2 <= numbers.length <= 3 * 104
    -1000 <= numbers[i] <= 1000
    numbers is sorted in non-decreasing order.
    -1000 <= target <= 1000
    The tests are generated such that there is exactly one solution.
*/
class Solution {
public:
 
    int binarySearch(vector<int>& nums, int left, int right, int target)
     {
        if(nums.size() == 0)
        return -1;

        //int left = 0, right = nums.size() - 1;
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
    
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int vecSize = numbers.size();
        vector<int> result;
        for(int i=0; i<vecSize; i++)
        {
            //if(result.size() == 2) break;
            
            int remaining = target - numbers[i];
            /* // Using linear search
            for(int j=i+1; j<vecSize; j++)
            {
                if(numbers[j] == remaining)
               {
                   result.push_back(i+1);
                    result.push_back(j+1);
                    break;
                }
            }
            */
            // Using binary search
            int index = binarySearch(numbers, i+1, vecSize-1, remaining);
            if(index != -1)
            {
                result.push_back(i+1);
                result.push_back(index+1);
                //return result;
                break;
            }  
            
        }
        return result;
    }
};
