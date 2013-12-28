// Construct Binary Tree from Preorder and Inorder Traversal 
class Solution {
public:
	TreeNode *rebuildTree(vector<int> &preorder, int &pre_pos, 
					vector<int> &inorder, int in_begin, int in_end) {
		// Use classic method on textbook
		// Can do well in pre and in reconstruct
		if (in_begin > in_end)	return NULL;
		int i, val = preorder[pre_pos++];
		TreeNode *node = new TreeNode(val);
		for (i = in_begin; i <= in_end; i++) {
			if (val == inorder[i])	break;
		}
		node->left = rebuildTree(preorder, pre_pos, inorder, in_begin, i-1);
		node->right = rebuildTree(preorder, pre_pos, inorder, i+1, in_end);
	}
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int pos = 0;
		if (preorder.size() == 0 || inorder.size() == 0)	
			return NULL;
		return rebuildTree(preorder, pos, inorder, 0, inorder.size()-1);
	}
};
// Construct Binary Tree from Inorder and Postorder Traversal 
class Solution {
public:
	TreeNode *rebuildTree(vector<int> &postorder, int &post_pos, 
					vector<int> &inorder, int in_begin, int in_end) {
		// Use classic method on textbook
		if (in_begin > in_end)	return NULL;
		int i, val = postorder[post_pos--];
		TreeNode *node = new TreeNode(val);
		for (i = in_begin; i <= in_end; i++) {
			if (val == inorder[i])	break;
		}
		node->right = rebuildTree(postorder, post_pos, inorder, i+1, in_end);
		node->left = rebuildTree(postorder, post_pos, inorder, in_begin, i-1);
	}
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (inorder.size() == 0 || postorder.size() == 0)	
			return NULL;
		int pos = postorder.size()-1;
		return rebuildTree(postorder, pos, inorder, 0, inorder.size()-1);
	}
};
