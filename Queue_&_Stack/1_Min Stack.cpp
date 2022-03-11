/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.

Example 1:
    Input
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]
    Output
    [null,null,null,null,-3,null,0,-2]

Explanation
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
 
Constraints:

    -231 <= val <= 231 - 1
    Methods pop, top and getMin operations will always be called on non-empty stacks.
    At most 3 * 104 calls will be made to push, pop, top, and getMin.

*/
// Ref to vector pair - https://www.codespeedy.com/use-push_back-for-vector-pair-in-c/#:~:text=C%2B%2B%20program%20for%20push%20back%20in%20Vector%20pair,vector%20%E2%80%9Cmake_pair%E2%80%9D%20function%20%28pair%20functions%20are%20inside%20%23include%3Calgorithm%3E%29.
// Ref to vector- https://www.geeksforgeeks.org/vector-in-cpp-stl/
class MinStack {
public:
    vector<pair<int, int>> s;
    //initializes the stack object.
    MinStack()
    {
        //stack<int> s;
    }
    //pushes the element val onto the stack.
    void push(int val)
    {
        if(s.empty()) s.push_back(make_pair(val, val));
        else
        {
            int currMin = s.back().second;
            s.push_back(make_pair(val, min(val,currMin)));
        }
        
    }
    //removes the element on the top of the stack.
    void pop() 
    {
        s.pop_back();
    }
    //gets the top element of the stack.
    int top() 
    {
        int topElement = s.back().first;
        return topElement;
    }
    //retrieves the minimum element in the stack.
    int getMin()
    {
        //if(!s.empty()) 
        return s.back().second;
        //else return
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
