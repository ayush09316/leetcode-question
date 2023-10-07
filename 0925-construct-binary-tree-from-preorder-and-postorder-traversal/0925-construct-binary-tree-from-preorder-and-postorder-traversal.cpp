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
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, 
                              vector<int>& postorder, int postStart, int postEnd, 
                              unordered_map<int, int>& postMap) {

        if (preStart > preEnd || postStart > postEnd)  return NULL;
 
        TreeNode* root = new TreeNode(preorder[preStart]);
 
        if (preStart == preEnd)  return root; 
        
        int leftRootVal = preorder[preStart + 1];
        int leftRootIndexInPost = postMap[leftRootVal];
        int leftSubtreeSize = leftRootIndexInPost - postStart + 1;
 
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize, 
                                     postorder, postStart, leftRootIndexInPost, postMap);
        root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd, 
                                      postorder, leftRootIndexInPost + 1, postEnd - 1, postMap);
 
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postMap;
        
        for (int i = 0; i < postorder.size(); i++)  postMap[postorder[i]] = i;
        
        return buildTreeHelper(preorder, 0, preorder.size() - 1, 
                              postorder, 0, postorder.size() - 1, postMap);
    }
};