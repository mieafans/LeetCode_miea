// Author : miea
// Date   : 2014-10-30

/********************************************************************************** 
*Write a function to find the longest common prefix string amongst an array of strings.
**********************************************************************************/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string pre = "";
		bool init = false;
		for(vector<string>::iterator itor = strs.begin(); itor != strs.end(); itor++)
		{
			if(!init)
			{
				init = true;
				pre = (*itor);
				continue;
			}
			for(int i = 0; i <= itor->size() && i <= pre.size(); i++)
			{
				if(pre[i] == (*itor)[i])
				{
					continue;
				}
				else
				{
					pre = pre.substr(0,i);
				}
			}
		}
		return pre;
	}
};
