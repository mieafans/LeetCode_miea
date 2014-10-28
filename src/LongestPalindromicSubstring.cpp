// Author : miea
// Date   : 2014-10-28

/********************************************************************************** 
*Given a string S, 
*find the longest palindromic substring in S. 
*You may assume that the maximum length of S is 1000, 
*and there exists one unique longest palindromic substring.
**********************************************************************************/

#include<string>
using namespace std;

class Solution {
public:

	string longestPalindrome(string s) {
		if(s.size() == 1)
		{
			return s;
		}
		string strRet = "";
		int len = s.size();
		for(int i = 0; i< len; i++)
		{
			{
				int j = i;
				int k = i + 1;
				while( k < len && j >= 0&& s[j] == s[k])
				{
					j--;
					k++;
				}
				k--;
				j++;
				if((k - j + 1) > strRet.size())
				{
					strRet = s.substr(j , k - j + 1);
				}
			}

			{
				int j = i - 1;
				int k = i + 1;
				while( k < len && j >= 0&& s[j] == s[k])
				{
					j--;
					k++;
				}
				k--;
				j++;
				if((k - j + 1) > strRet.size())
				{
					strRet = s.substr(j , k - j + 1);
				}
			}
		}
		return strRet;
	}
