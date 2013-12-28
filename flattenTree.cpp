class Solution {
public:
	TreeNode * flattenTree(TreeNode * node) {
		// Inspired by DFS search, first deal with left child, 
		// Return last node after it, and then deal with right child
		// Before go in this function, we can ensure node is not NULL
		TreeNode * tmpnode = node;
		TreeNode * lnode = node->left;
		TreeNode * rnode = node->right;

		node->left = NULL;
		if (lnode != NULL) {
			node->right = lnode;
			tmpnode = flattenTree(node->right);
		}
		if (rnode != NULL) {
			tmpnode->right = rnode;
			tmpnode = flattenTree(rnode);
		}
		return tmpnode;
	}
	void flatten(TreeNode *root) {
		// If root is NULL, return NULL
		if (node == NULL)   return NULL;	
		flattenTree(root);
	}
};
