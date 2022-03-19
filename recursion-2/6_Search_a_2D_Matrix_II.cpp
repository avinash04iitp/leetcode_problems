/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 
Example 1:
    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
    Output: true
Example 2:
    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
    Output: false
Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= n, m <= 300
    -109 <= matrix[i][j] <= 109
    All the integers in each row are sorted in ascending order.
    All the integers in each column are sorted in ascending order.
    -109 <= target <= 109
*/
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int a = 0;
        int b = matrix[a].size()-1;
        while(a<matrix.size() && b>=0)
        {
            if(matrix[a][b] == target) return true;
            else if(matrix[a][b] > target)
            {
                b--;      
            }  
            else if(matrix[a][b]<target)
                a++;
        }
        return false;
    }
};
