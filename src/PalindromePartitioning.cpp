// Author : miea
// Date   : 2014-11-6

/********************************************************************************** 
*Given a string s, partition s such that every substring of the partition is a palindrome.
*
*Return all possible palindrome partitioning of s.
*
*For example, given s = "aab",
*Return
*
*[
*["aa","b"],
*["a","a","b"]
*]
**********************************************************************************/
#include <string>
#include <list>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> ret;
		vector<string> vecRet;

		palindrome(ret, vecRet, s);
		return ret;
	}
	void palindrome(vector<vector<string>>& ret, vector<string> vecRet, string s) {
		int len = s.size();
		if(len == 0)
		{
			if(!vecRet.empty())
			{
				ret.push_back(vecRet);
			}
		}
		string tmp = "";
		bool flag = false;
		for(int i = 0; i < len; i++)
		{
			flag = false;
			tmp = s.substr(0, i + 1);
			int l = tmp.size();
			for(int j = 0; j < l/2 + 1; j++)
			{
				if(tmp[j] != tmp[l - 1 - j])
				{
					flag = true;
					break;
				}
			}
			if(flag)
			{
				continue;
			}
			vecRet.push_back(tmp);
			palindrome(ret, vecRet, s.substr(i + 1, len - i - 1));
			vecRet.pop_back();
		}
	}
};
