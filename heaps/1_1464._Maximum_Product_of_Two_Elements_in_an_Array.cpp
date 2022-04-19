/*
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

Example 1:
    Input: nums = [3,4,5,2]
    Output: 12 
    Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:
    Input: nums = [1,5,4,5]
    Output: 16
    Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
Example 3:
    Input: nums = [3,7]
    Output: 12

Constraints:
    2 <= nums.length <= 500
    1 <= nums[i] <= 10^3
*/
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int maxNum = 0;
        int maxIndex;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=maxNum)
            {
                maxNum = nums[i];
                maxIndex = i;
            }
        }
        int secMax = 0;
        for(int j=0; j<nums.size();j++)
        {
            if((nums[j] <= maxNum) && (nums[j]>secMax) && (j != maxIndex))
                secMax = nums[j];
        }
        return (maxNum-1)*(secMax-1);
    }
};

// One more best solution
// Ref:- https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/discuss/661780/C%2B%2B-Biggest-and-Second-Biggest
/*
class Solution {
public:
int maxProduct(vector<int>& nums) {
	auto m1 = 0, m2 = 0;
	for (auto n: nums) {
		if (n > m1)
            m2 = exchange(m1, n);
		else
			m2 = max(m2, n);
	}
	return (m1 - 1) * (m2 - 1);
}
};
*/
