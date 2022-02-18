/* 
Ref:- https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3251/
#Valid Mountain Array 

Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:
    arr.length >= 3
    There exists some i with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Example 1:
    Input: arr = [2,1]
    Output: false
Example 2:
    Input: arr = [3,5,5]
    Output: false
Example 3:
    Input: arr = [0,3,2,1]
    Output: true
Constraints:
    1 <= arr.length <= 104
    0 <= arr[i] <= 104
*/
class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
        int len = arr.size();
        int tempLen = len;
        int count = 0;
        int i, j;
        // Case-1:- if array length < 3 then return false
        if(len<3)
            return false;
        else
        {
            for(i=0; i<tempLen-1; i++)
            {
                if(arr[i]<arr[i+1])
                    continue;
                // Case-2: If any two consecutive numbers are equal then return false.
                else if(arr[i] == arr[i+1])
                    return false;
                
                else if(i != 0 && arr[i]>arr[i+1])
                {
                    count ++;
                    // Case-3 :Once reached the peak then break it here and go to next for loop to track the 
                            //strictly decreasing part.
                    tempLen = 0;
                }
                // Case-4: If the first element itself is greater then second then return false
                else
                    return false;
            }
            for(j=i; j<len-1; j++)
            {
                // Case-5 :Return false if next num is greater than the current one because it is violating the
                        // strictly decreasing property.
                if(arr[j] < arr[j+1] || arr[j] == arr[j+1])
                    return false;
                else 
                    count ++;

            }
            // Case-6: if numbers are only in increasing order. [0,1,2,3]
            if(count == 0) 
                return false;
            //Case-7: Return true if there nothing wrong above.
            return true;
        }
    }
};
