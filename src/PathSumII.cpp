// Author : miea
// Date   : 2014-11-5

/********************************************************************************** 
*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
*
*For example:
*Given the below binary tree and sum = 22,
*5
* / \
* 4   8
* /   / \
* 11  13  4
* /  \    / \
* 7    2  5   1
*return
*[
*[5,4,11,2],
*[5,8,4,5]
*]
**********************************************************************************/
#include <string>
#include <list>
#include <vector>
#include <iostream>
using namespace std;



  //Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ret;
		vector<int> vecRet;
		if(root == NULL)
		{
			return ret;
		}
		int nRet = sum - root->val;

		vecRet.push_back(root->val);

		if(nRet == 0 && root->left == NULL && root->right == NULL)
		{
			ret.push_back(vecRet);
		}

		if(root->left != NULL)
		{
			Deep(root->left, ret, vecRet, nRet);
		}
		if(root->right != NULL)
		{
		    Deep(root->right, ret, vecRet, nRet);
		}
		
		return ret;

    }
	void Deep(TreeNode* node, vector<vector<int>>& ret, vector<int> vecRet, int nRet)
	{
	    if(node == NULL)
		{
			if(nRet == 0)
			{
				ret.push_back(vecRet);
			}
			return ;
		}
		
	
		vecRet.push_back(node->val);
		if(nRet == node->val && node->left == NULL && node->right == NULL)
		{
			ret.push_back(vecRet);
		}
		if(node->left != NULL)
		{
			Deep(node->left, ret, vecRet, nRet - node->val);
		}
		if(node->right != NULL)
		{
			Deep(node->right, ret, vecRet, nRet - node->val);
		}

		return ;
	}
};
