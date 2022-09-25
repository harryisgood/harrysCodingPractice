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
class Solution {
public:
    
    void find_paths(TreeNode *root, int sum, vector<vector<int> > &paths, vector<int> &path)
    {
        if(!root)
            return;
        
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            int total = 0;
            for(auto i : path)
            {
                total += i;
            }
            
            if(total == sum)
                paths.push_back(path);
        }
        find_paths(root->left, sum, paths, path);
        find_paths(root->right, sum, paths, path);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int> > result;
        vector<int> tmp;
        
        find_paths(root, sum, result, tmp);
        return result;
    }
};