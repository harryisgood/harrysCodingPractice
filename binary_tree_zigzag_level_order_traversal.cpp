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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(!root)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        
        vector<vector<int> > result;
        int flag = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> tmp;
            
            while(size > 0)
            {
                TreeNode *top_value = q.front();
                q.pop();
                if(top_value)
                    tmp.push_back(top_value->val);
                if(top_value && top_value->left)
                    q.push(top_value->left);
                if(top_value && top_value->right)
                    q.push(top_value->right);
                --size;
            }
            if(flag % 2 == 0)
                result.push_back(tmp);
            else
            {
                reverse(tmp.begin(), tmp.end());
                result.push_back(tmp);
            }
            ++flag;   
        }
        return result;
    }
};