/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
    Input: n = 2
    Output: 1
    Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:
    Input: n = 3
    Output: 2
    Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:
    Input: n = 4
    Output: 3
    Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
Constraints:
    0 <= n <= 30
*/
class Solution {
public:
    map <int, int> mp;
    int fib(int n) 
    {
        // Sol-1:- Without Memoization
        //if(n<2) return n;
        //else return fib(n-1) + fib(n-2);
        ///*
        
        // Sol-2:- With memoization. Line-3 is with memoization
        mp.insert(pair<int, int>(0, 0));
        mp.insert(pair<int, int>(1, 1));  
        if(mp.count(n))
        {
            return mp[n];
            //auto itr = mp.find(n);
            //return itr->second;
        }
        if(n<2) return n;
        else
        {
            int res = fib(n-1) + fib(n-2);
            mp[n] = res;
            //mp.insert(pair<int, int>(n, res));
            return mp[n];
            
        }
    }
};
