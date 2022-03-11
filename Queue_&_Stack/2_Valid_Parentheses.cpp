/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Example 1:
    Input: s = "()"
    Output: true
Example 2:
    Input: s = "()[]{}"
    Output: true
Example 3:
    Input: s = "(]"
    Output: false
Constraints:
    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.
*/
class Solution {
    //std::vector<std::string> v;
    vector<char> v;
public:
    bool isValid(string s) 
    {
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == '[' || s[i] == '{'|| s[i] == '(') 
            {
                v.push_back(s[i]);
            }
            
            else if(s[i] == ']' || s[i] == '}' || s[i] == ')')
                
            {
                if(v.empty()) return false;
                  switch(s[i])
                  {
                        case ')':   if(v.back() == '(')
                        {
                                        v.pop_back();
                                        continue;
                        }
                          break;
                          
                        case ']': if(v.back() == '[')
                        {
                            v.pop_back();
                            continue;
                        }
                          break;
                      case '}': if(v.back() == '{')
                      {
                          v.pop_back();
                          continue;
        
                      }
                          break;
                      default: break;
                  }
                return false;
            }
        }
        if(!v.empty()) return false;
        
        return true;
    }
};
