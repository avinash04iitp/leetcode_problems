/*
Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

Note that the letters wrap around.

For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
Example 1:
    Input: letters = ["c","f","j"], target = "a"
    Output: "c"
Example 2:
    Input: letters = ["c","f","j"], target = "c"
    Output: "f"
Example 3:
    Input: letters = ["c","f","j"], target = "d"
    Output: "f"
Constraints:
    2 <= letters.length <= 104
    letters[i] is a lowercase English letter.
    letters is sorted in non-decreasing order.
    letters contains at least two different characters.
    target is a lowercase English letter.
*/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        int start = 0, end = letters.size()-1, mid;
        if(int(letters[0]) > int(target)) return letters[0];
        else if(int(letters[end]) <= int(target)) return letters[0];
        else
        {     
            while(start < end)
            {
                mid = start + (end-start)/2;
                if(int(letters[mid]) == int(target)) 
                {
                    for(int i = mid; i<=end; i++)
                    {
                    if(int(letters[i]) > int(target)) return letters[i];
                    }
                }
                else if(int(letters[mid]) > int(target))
                    end = mid;
                else
                    start = mid + 1;
            }
            if(int(letters[mid]) > int(target))
                return letters[mid];
            else if(int(letters[mid]) <= int(target))
            {
                for(int i = mid; i<=end; i++)
                {
                    if(int(letters[i]) > int(target)) return letters[i];
                }
            }
        }
        return letters[mid];
    }
};
