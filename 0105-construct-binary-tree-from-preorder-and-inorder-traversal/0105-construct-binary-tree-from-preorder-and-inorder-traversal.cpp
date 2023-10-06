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
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,int inStart,int inEnd,
    int preStart,int preEnd,map<int,int>&mp){

        if(inStart>inEnd || preStart>preEnd) return NULL;

        TreeNode* root= new TreeNode(preorder[preStart]);
        int ind= mp[root->val];
        int nEle=ind-inStart;
        root->left=solve(inorder,preorder,inStart,ind-1,preStart+1,preStart+nEle,mp);
        root->right=solve(inorder,preorder,ind+1,inEnd,preStart+nEle+1,preEnd,mp);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inStart=0 , preStart=0;
        int inEnd=inorder.size()-1 , preEnd=preorder.size()-1;
        map<int,int>mp;
        for(int i=inStart;i<=inEnd;i++){
            mp[inorder[i]]=i;
        }
        return solve(inorder,preorder,inStart,inEnd,preStart,preEnd,mp);
    }
};