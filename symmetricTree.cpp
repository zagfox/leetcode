/****************************************
 * Name: Symmetric tree
 * Author: Feng Zhu
 * Function: solve leetcode symmetric tree problem
 * Date: 2013-10-23
 ***************************************/
#include<iostream>
//#include<vector>
using namespace std;

/**
 * Definition for binary tree
 */ 
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	//Do it like BFS, examine each layer
	public:
		bool isSymmetric(TreeNode *root) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			int i, len;
			vector<TreeNode*> vecA, vecB;
			vecA.push_back(root);
			while (!vecA.empty()) {
				len = vecA.size();	
				for (i = 0; i < len; i++) {
					if (vecA[i] == NULL && vecA[len-1-i] == NULL)	{}
					else if (vecA[i] == NULL || vecA[len-1-i] == NULL)	return false;
					else{
						if (vecA[i]->val == vecA[len-1-i]->val) {
							vecB.push_back(vecA[i]->left);
							vecB.push_back(vecA[i]->right);
						}
						else {
							return false;
						}
					}
				}
				vecA.clear();
				swap(vecA, vecB);
			}
			return true;
		}
};

class Solution2 {
	//Learn from fish in water, use recursive method to solve it
	public:
		bool recSym(TreeNode *lnode, TreeNode *rnode) {
			if (lnode == NULL)
				return (rnode == NULL);
			if (rnode == NULL)
				return (lnode == NULL);
			if (lnode->val != rnode->val)
				return false;
			else {
				if (!recSym(lnode->left, rnode->right))
					return false;
				if (!recSym(lnode->right, rnode->left))
					return false;
			}
			return true;
		}

		bool isSymmetric(TreeNode *root) {
			if (root == NULL) return true;
			else 
				return recSym(root->left, root->right);
		}
};
int main(){
	Solution2 sn;
	//TreeNode *nodeA = new TreeNode(1);
	//TreeNode *nodeB = new TreeNode(2);
	//nodeA->left = nodeB;
	cout<<sn.isSymmetric(NULL)<<endl;
	return 0;
}
