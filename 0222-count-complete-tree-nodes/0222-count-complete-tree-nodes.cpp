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
    
    void count(TreeNode* root, int &ans)
    {
      ans++;
      if(!root -> left) return;
      count(root -> left, ans);
      if(!root -> right) return;
      count(root -> right, ans);
    }
    int countNodes(TreeNode* root) {
      if(!root) return 0;
        int ans = 0;
        count(root, ans);
        return ans;
    }

};