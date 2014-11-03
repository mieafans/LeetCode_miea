// Author : miea
// Date   : 2014-11-3

/********************************************************************************** 
*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*
*For example, given n = 3, a solution set is:
*
*"((()))", "(()())", "(())()", "()(())", "()()()"
**********************************************************************************/
#include <string>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> vec;
		list<char> tmp;
		string mid = "";
		int l = n, r = n;
		generate(vec, tmp, l, r, mid);
		return vec;
	}

	void generate(vector<string>& vec, list<char> tmp, int l, int r, string mid)
	{
		if(mid.empty() && l > 0)
		{
			tmp.push_back('(');
			mid += '(';
			l--;
		}

		if(l == 0 && r == 0 && tmp.empty())
		{
			vec.push_back(mid);
			return ;
		}


		if(l > 0)
		{
			tmp.push_back('(');
			string strMid = mid + '(';
			generate(vec, tmp, l-1, r, strMid);
			tmp.pop_back();
		}

		if(r > 0)
		{
			if(!tmp.empty())
			{
				char c = tmp.back();
				if(c == '(')
				{
					tmp.pop_back();
				}
			}
			string strMid = mid + ')';
			generate(vec, tmp, l, r-1, strMid);
		}

	}

	
};
