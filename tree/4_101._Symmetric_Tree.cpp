/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
    Input: root = [1,2,2,3,4,4,3]
    Output: true
Example 2:
    Input: root = [1,2,2,null,3,null,3]
    Output: false
Constraints:
    The number of nodes in the tree is in the range [1, 1000].
    -100 <= Node.val <= 100
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Ref:- https://leetcode.com/problems/symmetric-tree/discuss/33056/15-lines-of-c%2B%2B-solution-8-ms
class Solution {
public:
    bool helpers(TreeNode* p, TreeNode* q)
    {
        // If both the nodes are null
        if(!p && !q)
            return true;
        // if one of the nodes is null
        else if(!p || !q) return false;
        // if both the nodes has different values.
        if(p->val != q->val)
            return false;
        // Recursive call for rest of the nodes.
        return helpers(p->left, q->right) && helpers(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL) return true;
        return helpers(root->left, root->right);
      
    }
};
