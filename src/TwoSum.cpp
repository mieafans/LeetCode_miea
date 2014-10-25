// Source : https://oj.leetcode.com/problems/two-sum/
// Author : miea
// Date   : 2014-10-25

/********************************************************************************** 
* 
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
* 
*               
**********************************************************************************/

#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		map<int, int> tmp;
		vector<int> ret;
		for(int i = 0; i < numbers.size(); i++)
		{
			if(tmp.find(numbers[i]) == tmp.end())
			{
				tmp.insert(make_pair(target - numbers[i], i));
			}
			else
			{
				ret.push_back(tmp[numbers[i]] + 1);
				ret.push_back(i + 1);
				return ret;
			}
		}
		return ret;
	}
};