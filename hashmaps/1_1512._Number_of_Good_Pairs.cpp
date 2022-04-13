/*
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

Example 1:
    Input: nums = [1,2,3,1,1,3]
    Output: 4
    Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:
    Input: nums = [1,1,1,1]
    Output: 6
    Explanation: Each pair in the array are good.
Example 3:
    Input: nums = [1,2,3]
    Output: 0

Constraints:
    1 <= nums.length <= 100
    1 <= nums[i] <= 100
*/
class Solution {
public:
    double fact(int num)
    {
        double result;
        if(num==1 || num == 0) result= 1;
        if(num>1)
            result = num*fact(num-1);
        return result;
    }
    int numIdenticalPairs(vector<int>& nums) 
    {
        map<int, int> pairs;
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            pairs[nums[i]] = pairs[nums[i]]+1;
        }
        for(auto m: pairs)
        {
            if(m.second > 1)
            {
                count = count + fact(m.second)/(fact(2)*fact(m.second-2));
            }
        }
        return count;
    }
};
