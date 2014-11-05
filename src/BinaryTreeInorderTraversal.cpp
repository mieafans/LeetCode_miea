// Author : miea
// Date   : 2014-11-5

/********************************************************************************** 
*Given a binary tree, return the inorder traversal of its nodes' values.
*
*For example:
*Given binary tree {1,#,2,3},
* 1
* \
* 2
* /
* 3
*return [1,3,2].
**********************************************************************************/
#include <string>
#include <list>
#include <vector>
#include <iostream>
using namespace std;



 
 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> vecRet;
		if(root == NULL)
		{
			return vecRet;
		}

		if(root->left != NULL)
		{
			Deep(root->left, vecRet);
		}

		vecRet.push_back(root->val);

		if(root->right != NULL)
		{
			Deep(root->right, vecRet);
		}

		return vecRet;
    }
	void Deep(TreeNode *node, vector<int>& vecRet)
	{
		if(node == NULL)
		{
			return ;
		}
		if(node->left != NULL)
		{
			Deep(node->left, vecRet);
		}

		vecRet.push_back(node->val);

		if(node->right != NULL)
		{
			Deep(node->right, vecRet);
		}

		return ;
	}
};
