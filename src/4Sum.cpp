// Author : miea
// Date   : 2014-10-31

/********************************************************************************** 
*Given an array S of n integers, are there elements a, b, c, 
*and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
*
*Note:
*Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
*The solution set must not contain duplicate quadruplets.
*For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
*
*A solution set is:
*(-1,  0, 0, 1)
*(-2, -1, 1, 2)
*(-2,  0, 0, 2)
**********************************************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		 vector<vector<int> > ret;
		 vector<int> vecRet;
		 int len = num.size();
		 if(len < 4)
		 {
			 return ret;
		 }
		 map<int, vector<pair<int,int>>> mapMid;  
		 
		 for(int i = 0; i < len - 1; i++)
		 {
			 for(int j = i + 1; j < len; j++)
			 {
				 mapMid[num[i] + num[j]].push_back(make_pair(i, j));
			 }
		 }
		 map<int, vector<pair<int,int>>> mapMid1 = mapMid;

		 map<int, vector<pair<int,int>>>::iterator itor1 = mapMid1.begin();
		 for(map<int, vector<pair<int,int>>>::iterator it = mapMid.begin(); it != mapMid.end(); it++)
		 {
			 int sum = target - it->first;
			 map<int, vector<pair<int,int>>>::iterator itor2 = mapMid1.find(sum);
			 if(itor2 != mapMid1.end())
			 {
				 vector<pair<int,int>>::iterator itor3 = itor2->second.begin();
				 for(; itor3 != itor2->second.end(); itor3++)
				 {
					 vector<pair<int,int>>::iterator it1 = it->second.begin();
					 for(; it1 != it->second.end(); it1++)
					 {
						  vecRet.push_back(itor3->first);
						  vecRet.push_back(itor3->second);
						  vecRet.push_back(it1->first);
						  vecRet.push_back(it1->second);
						  ret.push_back(vecRet);
						  vecRet.clear();
					 }
				 }
			 }
			 mapMid1.erase(itor1++);
		 }
		 return ret;
	}
};
