/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node==NULL) s.append("#,");
            else s.append(to_string(node->val)+',');
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream stream(data);
		getline(stream, data, ',');
        TreeNode *root = new TreeNode(stoi(data));
        queue<TreeNode*> q({ root });

        while (!q.empty()){
            TreeNode *front = q.front();
			q.pop();
            string left, right;
            getline(stream, left, ',');
			getline(stream, right, ',');

			if (left == "#")  front->left = NULL;
			else {
				front->left = new TreeNode(stoi(left));
				q.push(front->left);
			}
			if (right == "#") front->right = NULL;
            else {
				front->right = new TreeNode(stoi(right));
				q.push(front->right);
			}
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));