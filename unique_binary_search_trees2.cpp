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
    vector<TreeNode *> f(int start,int stop)
    {
        if(start>stop)
            return {NULL};
        if(start==stop)
            return {new TreeNode(start)};
        
        vector<TreeNode *> ans;
        for(int i=start;i<=stop;i++)
        {
            vector<TreeNode *> v1;
            vector<TreeNode *> v2;
            v1=f(start,i-1);
            
            v2=f(i+1,stop);
            for(int j=0;j<v1.size();j++)
            {
                for(int k=0;k<v2.size();k++)
                {
                    TreeNode * root= new TreeNode(i);
                    root->left=v1[j];
                    root->right=v2[k];
                    ans.push_back(root);
                }
            }

        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) 
    {
        if(n==0) return {};
        return f(1,n);
    }
};