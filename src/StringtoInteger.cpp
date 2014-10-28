// Author : miea
// Date   : 2014-10-28

/********************************************************************************** 
*Implement atoi to convert a string to an integer.
*
*Hint: Carefully consider all possible input cases. 
*If you want a challenge, please do not see below and ask yourself what are the possible input cases.
*
*Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
*You are responsible to gather all the input requirements up front.
**********************************************************************************/
#include <sstream>

using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		stringstream ss;
		ss << str;
		int nRet = 0;
		ss >> nRet;
		return nRet;
	}
};
