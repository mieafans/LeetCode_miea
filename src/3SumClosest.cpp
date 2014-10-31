// Author : miea
// Date   : 2014-10-31

/********************************************************************************** 
*Given an array S of n integers, 
*find three integers in S such that the sum is closest to a given number, target.
*Return the sum of the three integers. 
*You may assume that each input would have exactly one solution.
*
*For example, given array S = {-1 2 1 -4}, and target = 1.
*
*The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
**********************************************************************************/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		int ret = 0;
		int mid = 0;
		vector<int> vecRet(3);
		int len = num.size();
		for(int i = 0; i < (len<3?len:3); i++)
		{
			ret += num[i];
		}
		if(len < 3)
			return ret;

		sort(num.begin(), num.end());

		for(int i = 0; i < len - 2; i++)
		{
			int j = len - 1;
			int k = i + 1;
			while(j > k)
			{
				mid = num[i] + num[j] + num[k];
				if(mid > target)
				{
					j--;
				}
				else if(mid < target)
				{
					k++;
				}
				else
				{
					return mid;
				}
				if(abs(mid - target) < abs(ret -target))
				{
					ret = mid;
				}
			}
		}
		return ret;
	}
};
