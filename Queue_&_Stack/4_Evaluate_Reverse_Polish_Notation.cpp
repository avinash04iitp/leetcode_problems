/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

Example 1:
    Input: tokens = ["2","1","+","3","*"]
    Output: 9
    Explanation: ((2 + 1) * 3) = 9
Example 2:
    Input: tokens = ["4","13","5","/","+"]
    Output: 6
    Explanation: (4 + (13 / 5)) = 6
Example 3:
    Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    Output: 22
    Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    = ((10 * (6 / (12 * -11))) + 17) + 5
    = ((10 * (6 / -132)) + 17) + 5
    = ((10 * 0) + 17) + 5
    = (0 + 17) + 5
    = 17 + 5
    = 22
Constraints:
    1 <= tokens.length <= 104
    tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/
class Solution {
public:
    vector<int> s;
    int evalRPN(vector<string>& tokens) 
    {
        int n = tokens.size();
        for(int i=0; i<n; i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")

            {
                if(tokens[i] == "+")
                {
                    auto num1 = s.back();
                    s.pop_back();
                    auto num2 = s.back();
                    s.pop_back();
                    s.push_back(num1+num2);
                }
                else if(tokens[i] == "-")
                {
                    auto num1 = s.back();
                    s.pop_back();
                    auto num2 = s.back();
                    s.pop_back();
                    s.push_back(num2-num1);
                }
                else if(tokens[i] == "*")
                {
                    auto num1 = s.back();
                    s.pop_back();
                    auto num2 = s.back();
                    s.pop_back();
                    s.push_back(num1*num2);
                }
                else if(tokens[i] == "/")
                {
                    auto num1 = s.back();
                    s.pop_back();
                    auto num2 = s.back();
                    s.pop_back();
                    s.push_back(num2/num1);
                }               
            }
            else
            {
                auto newNum = stoi(tokens[i]);
                s.push_back(newNum);
            }
        }
        return s[0];
    }
};