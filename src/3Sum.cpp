// Author : miea
// Date   : 2014-10-31

/********************************************************************************** 
*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
*Find all unique triplets in the array which gives the sum of zero.
*
*Note:
*Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
*The solution set must not contain duplicate triplets.
*For example, given array S = {-1 0 1 2 -1 -4},
*
*A solution set is:
*(-1, 0, 1)
*(-1, -1, 2)
**********************************************************************************/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> ret;
		vector<int> vecRet(3);
		int len = num.size();
		if(len < 3)
		{
			return ret;
		}
		sort(num.begin(), num.end());

		for(int i = 0; i < len - 2; i++)
		{
			int j = len - 1;
			int k = i + 1;
			while(j > k)
			{
				if(num[i] + num[j] + num[k] > 0)
				{
					j--;
				}
				else if(num[i] + num[j] + num[k] < 0)
				{
					k++;
				}
				else
				{
					vecRet.push_back(num[i]);
					vecRet.push_back(num[k]);
					vecRet.push_back(num[j]);
					ret.push_back(vecRet);
					vecRet.clear();
					do { k++; }while (k < j && num[k - 1] == num[k]);
					do { j--; }while (k < j && num[j + 1] == num[j]);
				}
			}
		}
		return ret;
	}
};
