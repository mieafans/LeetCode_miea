// Author : miea
// Date   : 2014-10-26

/********************************************************************************** 
* 
* Reverse digits of an integer.
*
*Example1: x = 123, return 321
*Example2: x = -123, return -321
* 
*               
**********************************************************************************/
#include<sstream>
using namespace std;


class Solution {
public:
	int reverse(int x) {
		if(x == 0)
		{
			return x;
		}

		stringstream ss;
		std::string retStr = "";
		int retInt;
		char tmpC;

		ss << x;
		ss >> retStr;
		int len = retStr.length();
		int j = len - 1;
		int i = 0;
		int flag = 1;
		if(x < 0)
		{
			i = 1;
			flag = 0;
		}

		for(; i < j; i++, j--)
		{
			tmpC = retStr[i];
			retStr[i] = retStr[j];
			retStr[j] = tmpC;
		}
		ss.clear();
		ss << retStr;
		ss >> retInt;

		return retInt;
	}
};

int main()
{
	Solution so;
	so.reverse(-10);
	return 0;
}