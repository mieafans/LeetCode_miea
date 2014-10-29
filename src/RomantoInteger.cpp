// Author : miea
// Date   : 2014-10-29

/********************************************************************************** 
* 
*Given a roman numeral, convert it to an integer.
*
*Input is guaranteed to be within the range from 1 to 3999.
* 
*               
**********************************************************************************/

#include <string>
#include <map>
using namespace std;



class Solution {
public:
	Solution(){
		MapTable['I'] = 1;
		MapTable['V'] = 5;
		MapTable['X'] = 10;
		MapTable['L'] = 50;
		MapTable['C'] = 100;
		MapTable['D'] = 500;
		MapTable['M'] = 1000;
	}
	int romanToInt(string s) {
		int ret = 0;
		int len = s.size();
		for(int i = 0; i < len; i++)
		{
			if(i == len - 1)
			{
				ret += MapTable[s[i]];
			}
			else if(MapTable[s[i]] >= MapTable[s[i+1]])
			{
				ret += MapTable[s[i]];
			}
			else if(MapTable[s[i]] < MapTable[s[i+1]])
			{
				ret -= MapTable[s[i]];
			}
		}
		return ret;
	}
private:
	map<char, int> MapTable;
};

int  main()
{
	Solution so;
	so.romanToInt("DCXXI");
	return 0;
}