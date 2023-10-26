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
    int ans, max_depth;
    void dfs(TreeNode* root,int d){
        if(!root) return;
        if(d>max_depth){
            max_depth=d;
            ans=root->val;
        }
        else if(d==max_depth) ans+=root->val;
        
        dfs(root->left,d+1);
        dfs(root->right,d+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        ans=0;
        max_depth=0;
        dfs(root,ans);
        return ans;
    }
};