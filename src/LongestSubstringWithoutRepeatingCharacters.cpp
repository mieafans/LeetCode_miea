// Author : miea
// Date   : 2014-10-26

/********************************************************************************** 
* 
*Given a string, find the length of the longest substring without repeating characters. 
*For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
*which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*              
**********************************************************************************/

#include<string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int dic[256];
		memset(dic, 0, 256 * sizeof(int));
		int count = 0;
		int maxCount = 0;
		int len = s.length();
		int aci = 0;

		for(int i = 0; i< len; )
		{
			aci = (int)s[i];
			if(dic[aci] != 0)
			{
				if(maxCount < count)
				{
					maxCount = count;
				}
					
				count = 0;

				i = dic[aci];
				if(len - i - 1 < maxCount)
				{
					return maxCount;
				}
				memset(dic, 0, 256 * sizeof(int));
				continue;
			}
			else
			{
				count++;
				dic[aci] = i + 1; 
				i++;
				continue;
			}
		}
		if(count > maxCount)
			maxCount = count;

		return maxCount;
	}
};

//int main()
//{
//	Solution so;
//	int ret = so.lengthOfLongestSubstring("endtomfgdwdwfcgpxiqvkuytdlcgd");
//	system("pause");
//	return 0;
//}