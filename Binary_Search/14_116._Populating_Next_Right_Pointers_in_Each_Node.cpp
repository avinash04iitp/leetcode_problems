/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Example 1:
    Input: root = [1,2,3,4,5,6,7]
    Output: [1,#,2,3,#,4,5,6,7,#]
    Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:
    Input: root = []
    Output: []
Constraints:
    The number of nodes in the tree is in the range [0, 212 - 1].
    -1000 <= Node.val <= 1000
 
Follow-up:
    You may only use constant extra space.
    The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        vector<vector<Node*>> tempVector;
        vector<vector<int>> result;
        // If root is empty
        if(!root) return NULL;
        // If root is not empty
        vector<Node*> nodeVec;
        nodeVec.push_back(root);
        tempVector.push_back(nodeVec);
        for(int i=0; i<tempVector.size(); i++)
        {
            vector<Node*> nodeVector;
            for(int j=0; j<tempVector[i].size(); j++)
            {
                //cout<<tempVector[i][j]<<endl;
                if(tempVector[i][j]->left)
                {
                    nodeVector.push_back(tempVector[i][j]->left);
                }
                if(tempVector[i][j]->right)
                {
                    nodeVector.push_back(tempVector[i][j]->right);
                }
            }
            if(nodeVector.size() != 0)          
            {
                tempVector.push_back(nodeVector);
            }
        }  
        for(int i=0; i<tempVector.size();i++)
        {
            for(int j=0; j<tempVector[i].size();j++)
            {
                //cout<<tempVector[i][j]<<endl;
                //cout<<i<<j<<endl;
                int m = j;
                cout<<tempVector[i].size()<<endl;
                if(++m == tempVector[i].size()){
                    cout<<tempVector[i][j]<<endl;
                    tempVector[i][j]->next = NULL;}
                else
                {
                    cout<<tempVector[i][j]<<endl;
                    tempVector[i][j]->next = tempVector[i][m];}
            }
        }
        return tempVector[0][0];
    }
};
