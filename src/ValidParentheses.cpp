// Author : miea
// Date   : 2014-11-3

/********************************************************************************** 
*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
*determine if the input string is valid.
*
*The brackets must close in the correct order, 
*"()" and "()[]{}" are all valid but "(]" and "([)]" are not.
**********************************************************************************/
#include <string>
#include <list>
using namespace std;


class Solution {
public:
	bool isValid(string s) {
		list<int> listTmp;
		int len = s.size();
		for(int i = 0; i < len; i++)
		{
			if(s[i] == '(' || s[i] == '{' ||s[i] == '[')
			{
				listTmp.push_back(s[i]);
			}

			if(s[i] == ']'|| s[i] == ')' || s[i] == '}')
			{
				if(listTmp.empty())
				{
					return false;
				}
				else
				{
					char tmp = listTmp.back();
					if(tmp == '(' && s[i] == ')')
						 listTmp.pop_back();
					else if(tmp == '{' && s[i] == '}')
						listTmp.pop_back();
					else if(tmp == '[' && s[i] == ']')
						listTmp.pop_back();
					else
						return false;
				}
			}
		}
		if(!listTmp.empty())
			return false;
		return true;
	}
};
