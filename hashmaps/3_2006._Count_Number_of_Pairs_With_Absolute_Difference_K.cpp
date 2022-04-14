/*
Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:

x if x >= 0.
-x if x < 0.
 
Example 1:
    Input: nums = [1,2,2,1], k = 1
    Output: 4
    Explanation: The pairs with an absolute difference of 1 are:
    - [1,2,2,1]
    - [1,2,2,1]
    - [1,2,2,1]
    - [1,2,2,1]
Example 2:
    Input: nums = [1,3], k = 3
    Output: 0
    Explanation: There are no pairs with an absolute difference of 3.
Example 3:
    Input: nums = [3,2,1,5,4], k = 2
    Output: 3
    Explanation: The pairs with an absolute difference of 2 are:
    - [3,2,1,5,4]
    - [3,2,1,5,4]
    - [3,2,1,5,4]
Constraints:
    1 <= nums.length <= 200
    1 <= nums[i] <= 100
    1 <= k <= 99
*/
/*
//My Solution
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        int count=0;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i; j<nums.size(); j++)
            {
                if(abs(nums[i]-nums[j])==k) count++;
            }
        }
        return count;
    }
};
*/

// Another solution
// Ref:- https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/discuss/1470906/C%2B%2B-oror-Using-Map

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]+k]) count+=map[nums[i]+k]; 
            if(map[nums[i]-k]) count+=map[nums[i]-k]; 
            map[nums[i]]++;
        }
        return count;
    }
};
