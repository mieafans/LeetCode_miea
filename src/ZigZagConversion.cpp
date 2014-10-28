// Author : miea
// Date   : 2014-10-28

/********************************************************************************** 
* 
*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
*(you may want to display this pattern in a fixed font for better legibility)
*
*P   A   H   N
*A P L S I I G
*Y   I   R
*And then read line by line: "PAHNAPLSIIGYIR"
*Write the code that will take a string and make this conversion given a number of rows:
*
*string convert(string text, int nRows);
*convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
**********************************************************************************/


#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		int len = s.size();
		if(len < nRows || nRows == 1)
		{
			return s;
		}
		
		string strRet = "";
		vector<string> vecRet(nRows);
		int step = 0;
		int index = 0;
		for(int i = 0; i < len; i++)
		{
			if(index == nRows - 1)
				step = -1;
			if(index == 0)
				step = 1;

			vecRet[index]+=s[i];
			index+=step;
		}

		for(int j = 0; j < vecRet.size(); j++)
		{
			strRet.append(vecRet[j]);
		}
		return strRet;
	}
};
