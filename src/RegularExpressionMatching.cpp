// Author : miea
// Date   : 2014-10-28

/********************************************************************************** 
*'.' Matches any single character.
*'*' Matches zero or more of the preceding element.
*
*The matching should cover the entire input string (not partial).
*
*The function prototype should be:
*bool isMatch(const char *s, const char *p)
*
*Some examples:
*isMatch("aa","a") → false
*isMatch("aa","aa") → true
*isMatch("aaa","aa") → false
*isMatch("aa", "a*") → true
*isMatch("aa", ".*") → true
*isMatch("ab", ".*") → true
*isMatch("aab", "c*a*b") → true
**********************************************************************************/

class Solution {
public:
	bool isMatch(const char *s, const char *p) {

		char* src = (char*) s;
		char* pa = (char*) p;

		return Match(src, pa);

	}
	bool Match(char *src, char *pa) {
		if(*pa == '\0')
		{
			return *src == '\0';
		}

		if(*src == '\0')
		{
			return (*pa == '*' && *(pa+1) == '\0') || (*(pa+1) == '*' && *(pa+2) == '\0');
		}
		if((*pa == '*' && *(pa+1) == '\0'))
		{
			return true;
		}

		if((*pa == '.' || *pa == *src) && *(pa+1)!= '*')
		{
			return Match(src+1, pa+1);
		}
		if(*pa == '*')
		{	
			while(*(pa+1) == '*')
				pa++;

			if(Match(src, pa+1))
			{
				return true;
			}
			int i = 1;
			while(*(src+i-1) != '\0')
			{
				if(!Match(src+i, pa+1))
				{
					i++;
				}
				else
				{
					return true;
				}
			}
			return false;
		}
		if(*(pa+1) == '*')
		{
			while(*(pa+3) != '\0' && *pa == *(pa+2) && *(pa+3) == '*')
			{
				pa = pa + 2;
			}

			if(*pa != *src && *pa != '.')
			{
				return Match(src, pa+2);
			}

			if(Match(src, pa+2))
			{
				return true;
			}

			int i = 1;
			while(*(src+i-1) != '\0')
			{
				if(*pa != *(src+i) && *pa != '.')
				{
					return Match(src+i, pa+2);
				}

				if(  !Match(src+i, pa))
				{
					i++;
				}
				else
				{
					return true;
				}
			}

			return false;

		}
		else
		{
			return false;
		}

	}
};
