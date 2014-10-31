// Author : miea
// Date   : 2014-10-31

/********************************************************************************** 
*Given a digit string, return all possible letter combinations that the number could represent.
*
*A mapping of digit to letters (just like on the telephone buttons) is given below.
*
*
*
*Input:Digit string "23"
*Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*Note:
*Although the above answer is in lexicographical order, your answer could be in any order you want.
**********************************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	Solution()
	{
		mapTable['2'].push_back('a');
		mapTable['2'].push_back('b');
		mapTable['2'].push_back('c');
		mapTable['3'].push_back('d');
		mapTable['3'].push_back('e');
		mapTable['3'].push_back('f');
		mapTable['4'].push_back('g');
		mapTable['4'].push_back('h');
		mapTable['4'].push_back('i');
		mapTable['5'].push_back('j');
		mapTable['5'].push_back('k');
		mapTable['5'].push_back('l');
		mapTable['6'].push_back('m');
		mapTable['6'].push_back('n');
		mapTable['6'].push_back('o');
		mapTable['7'].push_back('p');
		mapTable['7'].push_back('q');
		mapTable['7'].push_back('r');
		mapTable['7'].push_back('s');
		mapTable['8'].push_back('t');
		mapTable['8'].push_back('u');
		mapTable['8'].push_back('v');
		mapTable['9'].push_back('w');
		mapTable['9'].push_back('x');
		mapTable['9'].push_back('y');
		mapTable['9'].push_back('z');
	}
	vector<string> letterCombinations(string digits) 
	{
		const char* mid = digits.c_str();
		vector<string> vec;
		string str = "";
		Combination(vec, str, mid);
		return vec;
	}
	void Combination(vector<string>& vec, string mid, const char* digits)
	{
	    if(*digits == '\0')
		{
			vec.push_back(mid);
			return ;
		}
	    vector<char> tmpVec = mapTable[*digits];
		int len = tmpVec.size();
		string tmStr = "";
		for(int i = 0; i < len; i++)
		{
	        Combination(vec, mid + tmpVec[i], digits+1);
		}
	}

private:
	map<char, vector<char>> mapTable;
};
