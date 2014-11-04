// Author : miea
// Date   : 2014-11-4

/********************************************************************************** 
*Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
*
*Do not allocate extra space for another array, you must do this in place with constant memory.
*
*For example,
*Given input array A = [1,1,2],
*
*Your function should return length = 2, and A is now [1,2].
**********************************************************************************/
#include <string>
#include <list>
#include <vector>
#include <iostream>
using namespace std;


 class Solution {
 public:
	 int removeDuplicates(int A[], int n) {
		 if(A == NULL || n < 1)
		 {
			 return n;
		 }
		 int pre = A[0];
		 int preIndex = 0;
		 int nowIndex = 1;
		 for(; nowIndex < n; nowIndex++)
		 {
			 if(pre != A[nowIndex])
			 {
			     if(preIndex + 1 != nowIndex)
				 {
					 memcpy(&A[preIndex + 1], &A[nowIndex], (n - nowIndex) * sizeof(int));
					 n = n - (nowIndex - preIndex) + 1;
					 nowIndex = preIndex + 1;
					 preIndex = nowIndex;
					 pre = A[preIndex];
				 }
				 else
				 {
					 preIndex = nowIndex;
					 pre = A[nowIndex];
				 }
			 }
		 }
		 if(nowIndex != preIndex + 1 && nowIndex == n)
		 {
			 n = preIndex + 1;
			 memset(&A[preIndex + 1], 0, sizeof(int) * (nowIndex - preIndex - 1));
		 }


		 return n;
	 }
 };
