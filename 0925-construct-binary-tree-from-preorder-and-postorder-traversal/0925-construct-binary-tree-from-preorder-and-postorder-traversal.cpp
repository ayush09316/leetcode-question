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
    int preIndex = 0;
    TreeNode* solve(vector<int>&pre,vector<int>&post,int start,int end,unordered_map<int,int>mp){
        
        if(start > end || preIndex >= pre.size())  return NULL;
        
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if(preIndex >= pre.size() || start == end)  return root;
        int pos = mp[pre[preIndex]];
        
        root->left = solve(pre, post, start, pos,mp);
        root->right = solve(pre, post, pos + 1, end - 1,mp);
        
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size() , m = postorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++) mp[postorder[i]]=i;
        return solve(preorder, postorder, 0, n - 1,mp);
    }
};