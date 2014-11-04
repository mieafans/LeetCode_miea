// Author : miea
// Date   : 2014-11-4

/********************************************************************************** 
*Implement strStr().
*
*Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*
*Update (2014-11-02):
*The signature of the function had been updated to return the index instead of the pointer. 
*If you still see your function signature returns a char * or String, 
*please click the reload button  to reset your code definition.
**********************************************************************************/
#include <string>
#include <list>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if(haystack == NULL || needle == NULL)
		{
			return -1;
		}
		if(*needle == '\0')
		{
			return 0;
		}
		char* p1 = haystack, *p3;
		char* p2 = needle;
		int cont = 0;

		while(*p1 != '\0')
		{
			if(*p1 != *p2)
			{
				p1++;
				cont++;
				continue;
			}

			p3 = p1;
			while(*p3 != '\0' && *p2 != '\0' &&*p3 == *p2 )
			{
				p3++;
				p2++;
			}
			if(*p2 == '\0')
			{
				return cont;
			}		  

			p2 = needle;
			cont++;
			p1++;
		}
		return -1;
	}
};
