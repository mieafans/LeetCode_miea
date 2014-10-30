// Author : miea
// Date   : 2014-10-30

/********************************************************************************** 
*Given an integer, convert it to a roman numeral.
*
*Input is guaranteed to be within the range from 1 to 3999.
**********************************************************************************/
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	Solution(){
		MapTable[1] = "I";
		MapTable[4] = "IV";
		MapTable[5] = "V";
		MapTable[9] = "IX";
		MapTable[10] = "X";
		MapTable[40] = "XL";
		MapTable[50] = "L";
		MapTable[90] = "XC";
		MapTable[100] = "C";
		MapTable[400] = "CD";
		MapTable[500] = "D";
		MapTable[900] = "CM";
		MapTable[1000] = "M";
	}
	string intToRoman(int num) {
	   string strRet  = "";
	   for(map<int, string>::reverse_iterator itor = MapTable.rbegin(); itor != MapTable.rend(); itor++)
	   {
			if(num - itor->first >= 0)
			{
				strRet += itor->second;
				return strRet += (intToRoman(num - itor->first));
			}
	   }
	   return "";
	}
private:
	map<int, string> MapTable;
};
