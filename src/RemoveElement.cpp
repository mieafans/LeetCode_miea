// Author : miea
// Date   : 2014-11-4

/********************************************************************************** 
*Given an array and a value, remove all instances of that value in place and return the new length.
*
*The order of elements can be changed. It doesn't matter what you leave beyond the new length.
**********************************************************************************/
#include <string>
#include <list>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		if(A == NULL)
		{
			return n;
		}
		 for(int i = 0; i < n; i++)
		 {
			 if(A[i] == elem)
			 {
				 while(A[n - 1] == elem && n - 1 != i)
				 {
					 n--;
				 }

				 if(n-1 == i)
				 {
					 n--;
					 continue;
				 }
				 else
				 {
					 A[i] = A[n - 1];
					 n--;
				 }
			 }
		 }
		 return n;
	}
};
