/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]
Example 2:
    Input: root = [1]
    Output: [[1]]
Example 3:
    Input: root = []
    Output: []
Constraints:
    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000
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
/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> listNodes;
        //vecotr<int> nodes;
        traversal(root, listNodes);//, nodes);
        return listNodes;
    }
    void traversal(TreeNode* root, vector<vector<int>> &listNodes)//, vecotr<int> &nodes)
    {
        if(!root) return;
        
        for(int i = 0; i<listNodes.size()-1; i++)
        {
            vector<int> temp;
            if(temp[i]->left != NULL)
            {
                temp.push_back(temp[i]->left->val);
            }
            if(temp[i]->right != NULL)
            {
                temp.push_back(temp[j]->right->val);
            }
            listNodes.push_back(temp);
        }
        
    }
};
*/
//Sol ref:- https://leetcode.com/explore/learn/card/recursion-ii/503/recursion-to-iteration/2784/discuss/1377899/C++-Solution
class Solution {
public:
   vector<vector<int>> sol;
	void helper(TreeNode* node, int level)
	{
		if(node == NULL) return ;
		if(level ==  (int)sol.size()){
			vector<int> temp;
			sol.push_back(temp);
		}
		sol[level].push_back(node->val);
		if(node->left)  helper(node->left, level+1);
		if(node->right) helper(node->right, level+1);
		
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		if(root == NULL) return sol;
		 helper(root, 0);
		return sol;
		
	}
};
